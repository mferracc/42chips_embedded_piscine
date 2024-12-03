#include <avr/io.h>

int main() {

    DDRB |= (1 << PB0); // set PB0 as output pin
    DDRB &= ~(1 << PD2); // clear PD2 to set as input
    PORTD |= (1 << PD2); // enable pull-up resistor on PD2

    uint8_t prev_button_state = 1; // init state at not pressed (high)

    while (1) {
         uint8_t current_button_state = PIND & (1 << PD2);
         // PIND = register that tells us the current state of pins on Port D
         // sets the 2nd pin to 1 within Port D

         if (prev_button_state && !current_button_state) {
            PORTB ^= (1 << PB0); // Toggle the state of PB0
         }
         prev_button_state = current_button_state;
    }
    return 0;
}
