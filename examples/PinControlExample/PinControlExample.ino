#include "pin_control.h"

// Define pins for LED and Button
#define LED_PIN  PB0 // Arduino Pin 8 on ATmega328P
#define BUTTON_PIN PB1 // Arduino Pin 9 on ATmega328P

void setup() {
    // Configure LED_PIN as output
    configure_pin_as_output(&DDRB, LED_PIN);

    // Configure BUTTON_PIN as input
    configure_pin_as_input(&DDRB, BUTTON_PIN);
}

void loop() {
    // Read the state of the button and control the LED
    if (read_pin(&PINB, BUTTON_PIN)) {
        set_pin_high(&PORTB, LED_PIN);
    } else {
        set_pin_low(&PORTB, LED_PIN);
    }

    delay(100); // Small delay to debounce
}
