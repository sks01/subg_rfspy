#ifndef VERSION_H
#define VERSION_H

#define SUBG_RFSPY_VERSION "subg_rfspy 2.2.22"
//watchdog enabled
//24Mhz active clock
//1.5Mhz idle clock, works only with BLE v3.4 or above
//fifo routines improves in time sensitive sections for serial and radio
//SPI_BUF_LEN=128
//added coments on changes for each relevant file
//COMPILE ONLY WITH SDCC 4.0.2 or above, versions between 3.8.0 and 4.0.0 produce bad code for send_packet_from_serial()
//version change to 2.2.x to make Loop happy; I will continue with minor number changes only
//reduced CPU frequency while waiting to receive first byte to reduce consumption for MySentry pumps;
//IOCFG1 |= IOCFG1_GDO_DS; 		//In applications where the digital I/O power supply voltage VDD on pin DVDD is below 2.6 V, the register bit IOCFG1.GDO_DS should be set to 1.
//CC1110 goes to PM1 and waits for BLE to wake it up by triggering an interrupt on P1_2
//CC1110 signal back to BLE when it is active such that BLE can stop polling when CC is sleeping
//reworked reset command, it was not working before
//removed all references to feed_watchdog
//tell BLE113 to restart itself when CC restarted itself or needs to be intialized again


#endif //VERSION_H


