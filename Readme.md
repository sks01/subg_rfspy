# subg_rfspy

[![Build Status](https://travis-ci.org/ps2/subg_rfspy.svg?branch=master)](https://travis-ci.org/ps2/subg_rfspy)

# Building subg_rfspy

Building under Windows

1. install [sdcc] (http://sdcc.sourceforge.net/) version >= 3.7.0
2. install Cygwin
3. use Cygwin to install make
4. Use cygwin bash to build the project

# Installing

Use TI SmartRF Flash Programmer to burn the .hex image resulting out of build process (in folder "output") 

# Protocol

See [protocol.md](protocol.md)

## Supported Registers

### SYNC1 (0x00)

Sync Word, High Byte. 8 MSB of 16-bit sync word.

### SYNC0 (0x01)

Sync Word, Low Byte. 8 LSB of 16-bit sync word.

### PKTLEN (0x02)

Packet Length. Indicates the packet length when fixed length packets are enabled. If
variable length packets are used, this value indicates the maximum length
packets allowed.

### PKTCTRL1 (0x03)

Packet Automation Control. Different bit ranges have different functions.
See CC1110/CC1111 datasheet for more information.

### PKTCTRL0 (0x04)

Packet Automation Control. Different bit ranges have different functions.
See CC1110/CC1111 datasheet for more information.

### ADDR (0x05)

Device Address. Address used for packet filtration. Optional broadcast addresses are 0
(0x00) and 255 (0xFF).

### CHANNR (0x06)

Channel Number. The 8-bit unsigned channel number, which is multiplied by the channel
spacing setting and added to the base frequency.

### FSCTRL1 (0x07)

Frequency Synthesizer Control.

### FSCTRL0 (0x08)

Frequency Synthesizer Control. Frequency offset added to the base frequency before being used by the
FS.

### FREQ2 (0x09)

Frequency Control Word, High Byte.

### FREQ1 (0x0A)

Frequency Control Word, Middle Byte.

### FREQ0 (0x0B)

Frequency Control Word, Low Byte.

### MDMCFG4 (0x0C)

Modem Configuration. Different bit ranges have different functions.
See CC1110/CC1111 datasheet for more information.

### MDMCFG3 (0x0D)

Modem Configuration. Different bit ranges have different functions.
See CC1110/CC1111 datasheet for more information.

### MDMCFG2 (0x0E)

Modem Configuration. Different bit ranges have different functions.
See CC1110/CC1111 datasheet for more information.

### MDMCFG1 (0x0F)

Modem Configuration. Different bit ranges have different functions.
See CC1110/CC1111 datasheet for more information.

### MDMCFG0 (0x10)

Modem Configuration. Different bit ranges have different functions.
See CC1110/CC1111 datasheet for more information.

### DEVIATN (0x11)

Modem Deviation Setting. Different bit ranges have different functions.
See CC1110/CC1111 datasheet for more information.

### MCSM2 (0x12)

Main Radio Control State Machine Configuration. Different bit ranges have
different functions. See CC1110/CC1111 datasheet for more information.

### MCSM1 (0x13)

Main Radio Control State Machine Configuration. Different bit ranges have
different functions. See CC1110/CC1111 datasheet for more information.

### MCSM0 (0x14)

Main Radio Control State Machine Configuration. Different bit ranges have
different functions. See CC1110/CC1111 datasheet for more information.

### FOCCFG (0x15)

Frequency Offset Compensation Configuration. Different bit ranges have
different functions. See CC1110/CC1111 datasheet for more information.

### BSCFG (0x16)

Bit Synchronization Configuration. Different bit ranges have different
functions. See CC1110/CC1111 datasheet for more information.

### AGCCTRL2 (0x17)

AGC Control. Different bit ranges have different functions.
See CC1110/CC1111 datasheet for more information.

### AGCCTRL1 (0x18)

AGC Control. Different bit ranges have different functions.
See CC1110/CC1111 datasheet for more information.

### AGCCTRL0 (0x19)

AGC Control. Different bit ranges have different functions.
See CC1110/CC1111 datasheet for more information.

### FREND1 (0x1A)

Front End RX Configuration. Different bit ranges have different
functions. See CC1110/CC1111 datasheet for more information.

### FREND0 (0x1B)

Front End RX Configuration. Different bit ranges have different
functions. See CC1110/CC1111 datasheet for more information.

### FSCAL3 (0x1C)

Frequency Synthesizer Calibration. Different bit ranges have
different functions. See CC1110/CC1111 datasheet for more information.

### FSCAL2 (0x1D)

Frequency Synthesizer Calibration. Different bit ranges have different
functions. See CC1110/CC1111 datasheet for more information.

### FSCAL1 (0x1E)

Frequency Synthesizer Calibration. Different bit ranges have different
functions. See CC1110/CC1111 datasheet for more information.

### FSCAL0 (0x1F)

Frequency Synthesizer Calibration. Different bit ranges have different
functions. See CC1110/CC1111 datasheet for more information.

### PA_TABLE1 (0x2D)

Power amplifier output power setting 1.

### PA_TABLE0 (0x2E)

Power amplifier output power setting 0.
