#ifndef PIN_CONTROL_H
#define PIN_CONTROL_H

#include <avr/io.h>

// Macros for setting, clearing, toggling, and reading pins
#define SET_PIN_HIGH(port, pin) ((port) |= (1 << (pin)))
#define SET_PIN_LOW(port, pin)  ((port) &= ~(1 << (pin)))
#define TOGGLE_PIN(port, pin)   ((port) ^= (1 << (pin)))
#define READ_PIN(port, pin)     (((port) & (1 << (pin))) >> (pin))

// Macros for setting pin direction
#define SET_PIN_OUTPUT(ddr, pin) ((ddr) |= (1 << (pin)))
#define SET_PIN_INPUT(ddr, pin)  ((ddr) &= ~(1 << (pin)))

// Inline functions for better type safety and additional utilities
static inline void configure_pin_as_output(volatile uint8_t *ddr, uint8_t pin) {
    *ddr |= (1 << pin);
}

static inline void configure_pin_as_input(volatile uint8_t *ddr, uint8_t pin) {
    *ddr &= ~(1 << pin);
}

static inline void set_pin_high(volatile uint8_t *port, uint8_t pin) {
    *port |= (1 << pin);
}

static inline void set_pin_low(volatile uint8_t *port, uint8_t pin) {
    *port &= ~(1 << pin);
}

static inline void toggle_pin(volatile uint8_t *port, uint8_t pin) {
    *port ^= (1 << pin);
}

static inline uint8_t read_pin(volatile uint8_t *pin_reg, uint8_t pin) {
    return (*pin_reg & (1 << pin)) >> pin;
}

#endif // PIN_CONTROL_H
