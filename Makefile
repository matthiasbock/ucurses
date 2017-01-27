
#
# Makefile for nRF51 projects
#
# Author: Matthias Bock <mail@matthiasbock.net>
# License: GNU GPLv3
#

 
#
# Toolchain
#
TOOLCHAIN_PATH   = /usr/bin/
TOOLCHAIN_PREFIX = arm-none-eabi
AS      = $(TOOLCHAIN_PATH)$(TOOLCHAIN_PREFIX)-as
CC      = $(TOOLCHAIN_PATH)$(TOOLCHAIN_PREFIX)-gcc
LD      = $(TOOLCHAIN_PATH)$(TOOLCHAIN_PREFIX)-ld
OBJCOPY = $(TOOLCHAIN_PATH)$(TOOLCHAIN_PREFIX)-objcopy
OBJDUMP = $(TOOLCHAIN_PATH)$(TOOLCHAIN_PREFIX)-objdump
SIZE    = $(TOOLCHAIN_PATH)$(TOOLCHAIN_PREFIX)-size
GDB     = $(TOOLCHAIN_PATH)$(TOOLCHAIN_PREFIX)-gdb

newlib  = /usr/lib/arm-none-eabi/newlib/libc.a

#
# Compiler and Linker
#
CFLAGS += -std=gnu99 -Wall -Wextra -g
CFLAGS += -mcpu=cortex-m0 -mthumb -mabi=aapcs -mfloat-abi=soft
CFLAGS += -ffreestanding
# keep every function in separate section. This will allow linker to dump unused functions
CFLAGS += -ffunction-sections -fdata-sections -fno-strict-aliasing
CFLAGS += -fno-builtin --short-enums
CFLAGS += -I arm/
CFLAGS += -I nordic/
CFLAGS += -I sdk/

# TODO: auto-detect chip revision
CHIP_REVISION = aa

LINKER_SCRIPT = sdk/linker/nrf51-blank-xx$(CHIP_REVISION).ld
LDFLAGS += -T $(LINKER_SCRIPT)
LDFLAGS += -L /usr/lib/gcc/arm-none-eabi/4.8/armv6-m/
LDFLAGS += -L /usr/lib/arm-none-eabi/newlib/armv6-m/
LDFLAGS += -static
LDFLAGS += -nostartfiles -nostdlib
LDFLAGS += --start-group
LDFLAGS += -lgcc

# required for semihosting 
CFLAGS  += --specs=rdimon.specs
LDFLAGS += -lrdimon 

# filename of used softdevice (full path)  
SOFTDEVICE = nordic/softdevice/s110_nrf51822_7.3.0_softdevice.hex


#
# Build targets
#

all: main.elf

main.elf: sdk/nrf51_startup.o nordic/system_nrf51.o sdk/strings.o sdk/fifo.o sdk/uart.o sdk/delay.o main.o 
	$(LD) $(LDFLAGS) $^ -o $@

test.elf: test.c box.c slider.c io.c
	colorgcc -Wall -std=gnu11 $^ -o test.elf


define LOAD_SOFTDEVICE_COMMAND
target remote localhost:3333
monitor reset halt
load
endef
export LOAD_SOFTDEVICE_COMMAND

# Flash the SoftDevice HEX-file into the chip
softdevice:
	echo "$$LOAD_SOFTDEVICE_COMMAND" | $(GDB) $(SOFTDEVICE)

%.o: %.c %s
	$(CC) $(CFLAGS) -c $< -o $@

%.hex: %.elf
	$(OBJCOPY) -Oihex $< $@

%.bin: %.elf
	$(OBJCOPY) -Obinary $< $@

clean:
	rm -f *.o */*.o *.out *.bin *.elf *.hex *.map


#
# Debugger
#
OPENOCD_CFG_DIR = sdk/debug/
# workaround: problems because the folder is named like the target in the subfolder's Makefile
.PHONY: debug
include sdk/debug/Makefile

