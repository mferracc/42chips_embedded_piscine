#include <avr/io.h>

int main() {

  DDRB |= (1 << PB0); // set PB0 as output pin
  while (1) {
    if (!(PIND & (1 << PD2))) {
      PORTB |= (1 << PB0); // turn on PB0
     } else {
       PORTB &= ~(1 << PB0); // turn off PB0
     }
  }
  return 0;
}
/*
https://developerhelp.microchip.com/xwiki/bin/view/products/mcu-mpu/8-bit-avr/getting-started/led-on/
 */