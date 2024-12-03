#include <avr/io.h>

int main() {
  DDRB |= (1 << PB0); // set PB0 as output pin
  PORTB |= (1 << PB0); // turn on PB0
  return 0;
}
/*
https://developerhelp.microchip.com/xwiki/bin/view/products/mcu-mpu/8-bit-avr/getting-started/led-on/
 */