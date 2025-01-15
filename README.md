# AVR Pin Control Library

A lightweight and efficient library for controlling pins on AVR microcontrollers using macros and inline functions. This library allows direct manipulation of pin states and modes, making it ideal for low-level hardware control.

## Difference Between Using Arduino Functions and Macros

When working with AVR microcontrollers, developers often use the Arduino framework for convenience. While Arduino functions like `digitalWrite()`, `pinMode()`, and `digitalRead()` are easy to use and abstract the hardware details, they come with some trade-offs compared to using macros or direct register manipulation.

### Arduino Functions

1. **Ease of Use**:
   - Functions like `digitalWrite(pin, HIGH)` are intuitive and readable.
   - No need to know about registers or bit manipulation.

2. **Portability**:
   - Code written with Arduino functions can work across multiple microcontrollers supported by Arduino without modification.

3. **Performance**:
   - These functions have additional overhead as they include checks, validation, and abstractions.
   - On an AVR running at 16 MHz, `digitalWrite()` can take approximately 50 clock cycles or more to execute.

### Macros and Direct Register Manipulation

1. **Efficiency**:
   - Macros like `SET_PIN_HIGH(PORTB, PB0)` directly manipulate the hardware registers, resulting in near-instant execution (usually within 1-2 clock cycles).
   - Critical for time-sensitive applications such as high-frequency toggling or precise timing.

2. **Low-Level Control**:
   - Provides direct access to microcontroller features without unnecessary abstraction.
   - Ideal for scenarios where performance and resource usage are priorities.

3. **Complexity**:
   - Requires understanding of AVR registers (`PORTx`, `DDRx`, `PINx`) and bitwise operations.
   - Less portable as the code is tightly coupled with the specific microcontroller’s hardware.

### Comparison Table

| Feature                     | Arduino Functions      | AVR Macros/Direct Registers    |
|-----------------------------|------------------------|---------------------------------|
| **Ease of Use**             | High                  | Low                             |
| **Performance**             | Moderate (High Overhead)| High (Low Overhead)            |
| **Portability**             | High                  | Low                             |
| **Timing Critical Applications** | Not Ideal          | Ideal                           |
| **Abstraction**             | High                  | Low                             |

### Conclusion

If you're working on a simple project where timing and performance are not critical, Arduino functions are a great choice for their ease of use and abstraction. However, for time-sensitive tasks or when maximum efficiency is required, using this library's macros for direct control of pins is the better option.

## Features

- **Set, Clear, Toggle, and Read Pins** with simple macros.
- **Configure Pins as Input or Output** easily.
- **Inline Functions** for type safety and more readable code.
- Minimal overhead for performance-critical applications.
- Portable across different AVR microcontrollers.

## Getting Started

### Prerequisites

- AVR microcontroller (e.g., ATmega328P, ATmega16, etc.).
- AVR development environment:
  - `avr-gcc` for compilation.
  - `avrdude` for uploading the firmware.
- Basic understanding of AVR register manipulation.

### Installation

1. Download the `pin_control.h` file and include it in your project directory.
2. Add `#include "pin_control.h"` in your source files to use the library.

## Usage

### Example Code

```c
#include <avr/io.h>
#include <util/delay.h>
#include "pin_control.h"

#define LED_PIN  PB0
#define BUTTON_PIN PB1

int main(void) {
    // Configure LED_PIN as output
    SET_PIN_OUTPUT(DDRB, LED_PIN);

    // Configure BUTTON_PIN as input
    SET_PIN_INPUT(DDRB, BUTTON_PIN);

    while (1) {
        // Read button state and set LED state accordingly
        if (READ_PIN(PINB, BUTTON_PIN)) {
            SET_PIN_HIGH(PORTB, LED_PIN);
        } else {
            SET_PIN_LOW(PORTB, LED_PIN);
        }

        _delay_ms(100); // Small delay to debounce
    }
    return 0;
}
```

### Macros

| Macro                     | Description                                       |
|---------------------------|---------------------------------------------------|
| `SET_PIN_HIGH(port, pin)` | Set the specified pin high.                       |
| `SET_PIN_LOW(port, pin)`  | Set the specified pin low.                        |
| `TOGGLE_PIN(port, pin)`   | Toggle the specified pin.                         |
| `READ_PIN(port, pin)`     | Read the state of the specified pin.              |
| `SET_PIN_OUTPUT(ddr, pin)`| Configure the pin as an output.                   |
| `SET_PIN_INPUT(ddr, pin)` | Configure the pin as an input.                    |

### Inline Functions

| Function                          | Description                                       |
|-----------------------------------|---------------------------------------------------|
| `configure_pin_as_output()`       | Configure the pin as an output.                  |
| `configure_pin_as_input()`        | Configure the pin as an input.                   |
| `set_pin_high()`                  | Set the pin high.                                |
| `set_pin_low()`                   | Set the pin low.                                 |
| `toggle_pin()`                    | Toggle the pin state.                            |
| `read_pin()`                      | Read the state of the pin.                       |

## Compilation

Use the following commands to compile and upload your program:

```bash
# Compile the program
avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os -o main.elf main.c

# Convert to hex file
avr-objcopy -O ihex -R .eeprom main.elf main.hex

# Upload to the microcontroller
avrdude -c usbasp -p m328p -U flash:w:main.hex
```

Replace `atmega328p` and `usbasp` with your microcontroller and programmer settings, respectively.
