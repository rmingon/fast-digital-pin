#include "pin_control.h"

void configure_pin_as_output(volatile uint8_t *ddr, uint8_t pin) {
    *ddr |= (1 << pin);
}

void configure_pin_as_input(volatile uint8_t *ddr, uint8_t pin) {
    *ddr &= ~(1 << pin);
}

void set_pin_high(volatile uint8_t *port, uint8_t pin) {
    *port |= (1 << pin);
}

void set_pin_low(volatile uint8_t *port, uint8_t pin) {
    *port &= ~(1 << pin);
}

void toggle_pin(volatile uint8_t *port, uint8_t pin) {
    *port ^= (1 << pin);
}

uint8_t read_pin(volatile uint8_t *pin_reg, uint8_t pin) {
    return (*pin_reg & (1 << pin)) >> pin;
}
