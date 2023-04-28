#include <msp430.h> // msp430 library
#include "../timerLib/libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

int main(void){

  configureClocks();
  switch_init();
  led_init();
  buzzer_init();
  
  enableWDTInterrupts(); //libTimer
  or_sr(0x18); // CPU off 
}
