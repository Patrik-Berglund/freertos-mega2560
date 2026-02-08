MCU = atmega2560
F_CPU = 16000000UL
PORT = /dev/ttyUSB0
BAUD = 115200

CC = avr-gcc
OBJCOPY = avr-objcopy

FREERTOS = freertos-kernel
PORT_DIR = $(FREERTOS)/portable/ThirdParty/GCC/ATmega

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall \
         -I. \
         -I$(FREERTOS)/include \
         -I$(PORT_DIR)

SRC = main.c \
      $(FREERTOS)/tasks.c \
      $(FREERTOS)/queue.c \
      $(FREERTOS)/list.c \
      $(FREERTOS)/portable/MemMang/heap_4.c \
      $(PORT_DIR)/port.c

TARGET = freertos-blink

all: $(TARGET).hex

$(TARGET).elf: $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@
	avr-size --mcu=$(MCU) -C $<

flash: $(TARGET).hex
	sudo avrdude -c wiring -p $(MCU) -P $(PORT) -b $(BAUD) -D -U flash:w:$<

clean:
	rm -f *.elf *.hex

.PHONY: all flash clean
