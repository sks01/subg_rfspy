# subg_rfspy

# This fork of subg_rfspy is intended only for use with RileyLink hardware. 
  Change vs. the original:
  - removed all files & code that is not needed to support RileyLink
  - reduce CPU frequency from 24Mhz to 6Mhz to reduce power consumption
  - reduce CPU frequency further to 3Mhz while not processing any commands, also for reducing power consumption

# Building subg_rfspy in Windows

1. install SDCC version >= 3.7.0
2. install Cygwin
3. use Cygwin to install make
4. download subg_rfspy from github and unzip it
4. cd to subg_rfspy folder in Cygwin
5. execute "make -f Makefile.spi1_alt2" to build it

# Installing

use Texas Instruments SmartRF Flash Programmer to flash the .hex file located in "subg_rfspy/output" folder

# Protocol

See [protocol.md](protocol.md)
