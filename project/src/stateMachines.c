#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

void button_state(int button){
  switch(button){
  case 1:
    song();
    button = 0;
    break;
  case 2:
    //stuff 2
    button = 0;
    break;
  case 3:
    //stuff 3
    button = 0;
    break;
  case 4:
    //stuff 4
    button = 0;
    break;
  }
}


void song(){
  int notes[] = {1000, 0};
    for(int i = 0; i < 30; i++){
      buzzer_set_period(1000);
      __delay_cycles(2500000);
      buzzer_set_period(0);
      __delay_cycles(2500000);
    }
  buzzer_set_period(0);
}
