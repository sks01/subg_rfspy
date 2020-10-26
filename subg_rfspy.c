/*Changes vs original 2.2
- changed CLKCON intialization to a hex value
- removed leds related routines, there are no leds connected to CC in EmaLink
- added LED blink at start
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

void subg_rfspy_main() {
	SLEEP &= ~SLEEP_OSC_PD;
	while( !(SLEEP & SLEEP_XOSC_S) );
	
	//CLKCON = 0xAB;  		//CLKSPD = 3Mhz, TICKSPD = 750Khz - too slow for receiving packets
	//CLKCON =  0xAA;		//CLKSPD = 6Mhz, TICKSPD = 750Khz - too slow for receiving packets
	//CLKCON =  0xA9;		//CLKSPD = 12Mhz, TICKSPD = 750Khz 
	CLKCON =  0xA8;			//CLKSPD = 24Mhz, TICKSPD = 750Khz
	while (CLKCON & CLKCON_OSC);
	SLEEP |= SLEEP_OSC_PD;

	//P2DIR |= BIT1;			//activate P2_1 as output for debugging
	//P2_1=1;				//put for high for USART

	init_timer();
	EA = 1;		  // Global interrupt enable

	configure_serial();
	configure_radio();

	//LED test
  	GREEN_LED_PIN = 1;
  	delay(100);
  	GREEN_LED_PIN = 0;
  	RED_LED_PIN = 1;
  	delay(100);
  	RED_LED_PIN = 0;

	subg_rfspy_init_finished = true;

	WDCTL = WDCTL_EN;	  // Start watchdog at 1s interval

	while(!subg_rfspy_should_exit) {
		get_command();
	}

}
