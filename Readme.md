# subg_rfspy

[![Build Status](https://travis-ci.org/ps2/subg_rfspy.svg?branch=master)](https://travis-ci.org/ps2/subg_rfspy)

# Building subg_rfspy

Building under Windows

1. install [sdcc] (http://sdcc.sourceforge.net/) version >= 3.7.0
2. install Cygwin
3. use Cygwin to install make
4. in Cygwin, run this command in the "subg_rfspy" folder: make -f Makefile.spi1_alt2

# Installing

Use TI SmartRF Flash Programmer to burn the .hex image resulting out of build process (in folder "output\spi1_alt2_RILEYLINK_US_STDLOC") 

# Protocol

See [protocol.md](protocol.md)
