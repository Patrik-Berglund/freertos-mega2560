# freertos-mega2560

FreeRTOS V11.2.0 on Arduino Mega 2560 (ATmega2560) using bare-metal AVR toolchain.

## Requirements

```bash
sudo apt install gcc-avr avr-libc binutils-avr avrdude
```

## Projects

### bare-metal-blink
Simple LED blink without RTOS - verifies toolchain and hardware.

### freertos-blink
FreeRTOS task blinking the onboard LED (PB7/pin 13).

## Build & Flash

```bash
cd freertos-blink
curl -L -o freertos.zip "https://github.com/FreeRTOS/FreeRTOS-Kernel/archive/refs/tags/V11.2.0.zip"
unzip -q freertos.zip && mv FreeRTOS-Kernel-11.2.0 freertos-kernel && rm freertos.zip
make
make flash
```

## Configuration

- MCU: ATmega2560 @ 16MHz
- Scheduler tick: Watchdog Timer (WDTO_15MS, ~15ms/tick)
- Heap: heap_1 (1KB configured, no fragmentation)
- Serial port: /dev/ttyUSB0

## Reference

- [PINMAP.md](PINMAP.md) - Arduino to ATmega2560 pin mapping
- [ATmega2560 Datasheet](https://ww1.microchip.com/downloads/en/devicedoc/atmel-2549-8-bit-avr-microcontroller-atmega640-1280-1281-2560-2561_datasheet.pdf)

## Programming Interface

The board can be programmed via:

1. **USB Bootloader** (default, what we use)
   - Uses UART0: PE0 (RX0), PE1 (TX0) - Arduino pins 0/1
   - ATmega16U2 chip handles USB-to-serial conversion
   - Auto-reset via DTR line
   - Command: `avrdude -c wiring`

2. **ICSP Header** (6-pin, for direct ISP programming)
   - PB1 (SCK) - Arduino pin 52
   - PB2 (MOSI) - Arduino pin 51
   - PB3 (MISO) - Arduino pin 50
   - RESET
   - VCC, GND
   - Command: `avrdude -c stk500v2` or `-c usbasp`
