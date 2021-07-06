/*Changes vs. original 2.2
- simplified ifdef for use with CC1110
*/

#include <cc1110.h>
#include "subg_rfspy.h"

// All ISR functions must be present or included in the file that contains the
// function main, as described in SDCC manual section 3.8.1
void t1_isr(void) __interrupt T1_VECTOR;
void rftxrx_isr(void) __interrupt RFTXRX_VECTOR;
void rf_isr(void) __interrupt RF_VECTOR;
void rx1_isr(void) __interrupt URX1_VECTOR;
void tx1_isr(void) __interrupt UTX1_VECTOR;
void port1_isr(void) __interrupt P1INT_VECTOR;


int main(void)
{
  subg_rfspy_main();
}
