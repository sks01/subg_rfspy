#include <stdint.h>
#include <stdio.h>
#include "hardware.h"
#include "serial.h"
#include "radio.h"
#include "timer.h"
#include "commands.h"
#include "subg_rfspy.h"

bool __xdata subg_rfspy_init_finished;
bool __xdata subg_rfspy_should_exit;

void subg_rfspy_main() {
  SLEEP &= ~SLEEP_OSC_PD;
  while( !(SLEEP & SLEEP_XOSC_S) );
  CLKCON =  0xAA;		//CLKSPD = 6Mhz, TICKSPD = 750Khz - no need to go faster than this, radio frequency is dependent on quartz frequency not on CPU clock
  while (CLKCON & CLKCON_OSC);
  SLEEP |= SLEEP_OSC_PD;

  P2DIR |= BIT1;		//activate P2_1 as output for debugging
  P2_1=1;				//put for high for USART
  
  init_timer();
  EA = 1;		  // Global interrupt enable

  configure_serial();
  configure_radio();

  subg_rfspy_init_finished = true;

  //WDCTL = WDCTL_EN;	  // Start watchdog at 1s interval

  while(!subg_rfspy_should_exit) {
    get_command();
  }
}
