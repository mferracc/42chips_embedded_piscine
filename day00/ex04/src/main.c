#include <avr/io.h>
#include <util/delay.h>

#define LED1 PB0
#define LED2 PB1
#define LED3 PB2
#define LED4 PB4
#define SW1 PD2
#define SW2 PD4
#define DEBOUNCE_DELAY 50

void set_leds() {
    DDRB |= (1 << LED1) | (1 << LED2) | (1 << LED3) | (1 << LED4);
}

void set_buttons() {
    DDRD &= ~(1 << SW1);
    DDRD &= ~(1 << SW2);

    PORTD |= (1 << SW1);
    PORTD |= (1 << SW2);
}

void switch_on(uint8_t led) {
    PORTB |= (1 << led); // turn on led
}

void switch_off(uint8_t led) {
    PORTB &= ~(1 << led); // turn off led
}

void display_value(const uint8_t value) {

    uint8_t leds[] = {LED1, LED2, LED3, LED4};

    for (int i = 0; i < 4; i++) {
        if (value & (1 << i)) {
            switch_on(leds[i]);
        } else {
            switch_off(leds[i]);
        }
    }
}

int main() {

    uint8_t value = 0; // init value to zero
    uint8_t prev_sw1 = 1, prev_sw2 = 1;

    set_leds();
    set_buttons();

    while (1) {
        uint8_t sw1_pressed = !((PIND) & (1 << SW1));
        uint8_t sw2_pressed = !((PIND) & (1 << SW2));

         if (sw1_pressed && !prev_sw1 && value < 15) {
            value++;
         } else if (sw2_pressed && !prev_sw2 && value > 0) {
            value--;
         }
         prev_sw1 = sw1_pressed;
         prev_sw2 = sw2_pressed;

         display_value(value);

         _delay_ms(DEBOUNCE_DELAY); // wait to debounce
    }
    return 0;
}
