
//Alternate LEDs from Off, Green, and Red
#include <stdio.h>
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS; //specifies which bits of P1 are for output. bits that are 1 light the corresponding LED

  /* When P1OUT is not set, P1.0 LED lights, even when it is not set. */

  //show green LED
  // P1OUT &= ~LED_RED;
  //P1OUT |= LED_GREEN;

  //show red LED
  // P1OUT &= ~LED_GREEN;
  // P1OUT |= LED_RED;

  //show both LEDs
  P1OUT |= LEDS;
  
  or_sr(0x18);/* CPU off, GIE on */
}
