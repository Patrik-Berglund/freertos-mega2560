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
- Scheduler tick: Watchdog Timer (~62Hz)
- Heap: heap_1 (1KB configured, no fragmentation)
- Serial port: /dev/ttyUSB0
