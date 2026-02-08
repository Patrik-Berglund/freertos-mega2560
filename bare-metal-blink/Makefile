MCU = atmega2560
F_CPU = 16000000UL
BAUD = 115200
PORT = /dev/ttyUSB0

CC = avr-gcc
OBJCOPY = avr-objcopy
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall

TARGET = blink

all: $(TARGET).hex

$(TARGET).elf: main.c
	$(CC) $(CFLAGS) -o $@ $<

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

flash: $(TARGET).hex
	avrdude -c wiring -p $(MCU) -P $(PORT) -b $(BAUD) -D -U flash:w:$<

clean:
	rm -f *.elf *.hex

.PHONY: all flash clean
