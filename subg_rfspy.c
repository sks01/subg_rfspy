/*Changes vs original 2.2
- changed CLKCON intialization to a hex value
- removed leds related routines, there are no leds connected to CC in EmaLink
*/

#include <stdint.h>
#include <stdio.h>
#include "hardware.h"
#include "serial.h"
#include "radio.h"
#include "timer.h"
#include "commands.h"
#include "subg_rfspy.h"
//#include "fifo.h"

bool __xdata subg_rfspy_init_finished;
bool __xdata subg_rfspy_should_exit;
//bool __xdata in_a_command = false;

void port1_isr(void) __interrupt P1INT_VECTOR
{
 // Clear the SLEEP.MODE bits, because an interrupt can also occur before the SoC has actually entered PM. If this interrupt occurs in between the
 // three NOPs (that is; before the corresponding interrupt blocking has actually taken effect) in Figure 2, then this clearing of the SLEEP.MODE
 // bits will ensure that the application does not enter PM{1 – 3}.
	P1IFG = 0;				//Clear P1 interrupt flags
	IRCON2 &= ~BIT3; 		//Clear P1IF cpu interrupt flag
	SLEEP &= 0xFC; 			//
}

void go_to_sleep() {
	volatile uint16_t i=50;

	//debug_putc(1);

	IRCON2 &= ~P1IF; 	//Clear P1IF
	P1IFG = 0;			//Clear IF for all P1 pins
	IEN2 |= BIT4;    	//Enable P1IE interrupt
	P1IEN |= BIT2;		//Enable P1_2 interrupt
	
	P1_2 = 1;		//going to sleep, don't disturb me unless you have a new command for me
	P1DIR &= ~BIT2;	//P1_2 as input
	
	SLEEP = (SLEEP & 0xFC) | 0x01;
	__asm
	nop
	nop
	nop
	__endasm;
// If no interrupt was executed in between the above NOPs, then all interrupts are effectively blocked when reaching this code position.
// If the SLEEP.MODE bits have been cleared at this point, which means that an ISR has indeed executed in between the above NOPs, then the
// application should not enter PM{1 – 3} !
	if (SLEEP & 0x03) { 
	 PCON |= 0x01;	//activate PM1
	 // The SoC is now in PM and will only wake up upon Port1 Interrupt
	 __asm
	 nop				//first instruction after waking up
	 __endasm;
	} 
	
	while(i--);  					//Wait until [HS XOSC] is stable following errata C (software delay)
	while(!(SLEEP & 0x40));			// Monitor SLEEP.XOSC_STB to ensure the HS XOSC is stable before continuing
	SLEEP |= 0x04;					// Set SLEEP.OSC_PD to power down the HS RCOSC
	
	IRCON2 &= ~P1IF; 	//Clear P1IF
	P1IFG = 0;			//Clear IF for all P1 pins
	IEN2 &= ~BIT4;    	//Disable P1IE interrupt
	P1IEN &= ~BIT2;		//Disable P1_2 interrupt
		
	P1_2 = 0;		//I'm awake and doing something usefull
	P1DIR |= BIT2;	//P1_2 as output to signal to BLE
	
	//debug_putc(2);
}

void subg_rfspy_main() {
	SLEEP &= ~SLEEP_OSC_PD;
	while( !(SLEEP & SLEEP_XOSC_S) );
	
	//CLKCON = 0xAB;  		//CLKSPD = 3Mhz, TICKSPD = 750Khz - too slow for receiving packets
	//CLKCON =  0xAA;		//CLKSPD = 6Mhz, TICKSPD = 750Khz - too slow for receiving packets
	//CLKCON =  0xA9;		//CLKSPD = 12Mhz, TICKSPD = 750Khz 
	CLKCON =  0xA8;			//CLKSPD = 24Mhz, TICKSPD = 750Khz
	while (CLKCON & CLKCON_OSC);
	SLEEP |= SLEEP_OSC_PD;

	P2DIR |= BIT1;			//activate P2_1 as output for debugging
	P2_1 = 1;					//activate debug
	P2_1 = 0;					//pulse to show it works
	P2_1 = 1;					//

	IOCFG1 |= IOCFG1_GDO_DS; 		//In applications where the digital I/O power supply voltage VDD on pin DVDD is below 2.6 V, the register bit IOCFG1.GDO_DS should be set to 1.

	PICTL |= 0x02; 		//P1ICON = 1 (Falling edge interrupt on Port 1)
	
	init_timer();
	EA = 1;		  // Global interrupt enable

	configure_serial();
	configure_radio();

	subg_rfspy_init_finished = true;

	//WDCTL = WDCTL_EN;	  // Start watchdog at 1s interval

	while(!subg_rfspy_should_exit) {
		go_to_sleep(); 	//nothing to do yet, wait for the wake-up call from BLE module
		get_command();
	}

}
