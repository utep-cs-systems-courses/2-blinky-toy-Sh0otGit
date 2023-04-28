
#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init(){
  P1DIR |= LEDS; //leds output
  P1OUT &= ~LEDS;
  switch_state_changed = 1;
  led_update();
}

void led_update(){
  if (switch_state_changed){
    char ledFlags = 0;

    ledFlags |= switch_state_down ? LED_GREEN : 0;
    ledFlags |= switch_state_down ? 0 : LED_RED;

    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;                 // set bits for on leds
     
  }
  switch_state_changed = 0;
}
