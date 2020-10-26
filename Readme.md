## Pre-Requisites for Building subg_rfspy

[sdcc] (http://sdcc.sourceforge.net/) version >= 4.0.2 is required for this build. There is a [docker image](https://hub.docker.com/r/ps2docker/sdcc_docker/) available for this purpose.

It's also possible to build it under Windows. The best way to do this is to:

1. install SDCC version 4.0.2 or higher
2. install Cygwin
3. use Cygwin to install make
4. Use cygwin bash to build the project

# Building

```
make -f Makefile.spi1_alt2 install
