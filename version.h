#ifndef VERSION_H
#define VERSION_H

#define SUBG_RFSPY_VERSION "subg_rfspy 2.2.16"
//watchdog enabled
//24Mhz active clock
//1.5Mhz idle clock, works only with BLE v3.4 or above
//fifo routines improves in time sensitive sections for serial and radio
//SPI_BUF_LEN=128
//added coments on changes for each relevant file
//COMPILE ONLY WITH SDCC 4.0.2 or above, versions between 3.8.0 and 4.0.0 produce bad code for send_packet_from_serial()
//version change to 2.2.x to make Loop happy; I will continue with minor number changes only


#endif //VERSION_H


