#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"


//Note Frequencies (Octave 5)
float c = 523.25;
float d = 587.33;
float e = 659.26;
float f = 698.46;
float g = 783.99;
float a = 880;
float b = 987.77;

void button_state(int button){
  switch(button){
  case 1:
    siren();
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


void siren(){
  int notes[] = {1000, 0};
    for(int i = 0; i < 30; i++){
      buzzer_set_period(1000);
      __delay_cycles(2500000);
      buzzer_set_period(0);
      __delay_cycles(2500000);
    }
  buzzer_set_period(0);
}

void mary_lamb(){
  buzzer_set_period(e);
  __delay_cycles(2500000);
  buzzer_set_period(d);
  __delay_cycles(2500000);
  buzzer_set_period(c);
  __delay_cycles(2500000);
  buzzer_set_period(d);
  __delay_cycles(2500000);
  buzzer_set_period(e);
  __delay_cycles(2500000);
  buzzer_set_period(e);
  __delay_cycles(2500000);
  buzzer_set_period(e);
  __delay_cycles(2500000);
  buzzer_set_period(d);
  __delay_cycles(2500000);
  buzzer_set_period(d);
  __delay_cycles(2500000);
  buzzer_set_period(d);
  __delay_cycles(2500000);
  buzzer_set_period(e);
  __delay_cycles(2500000);
  buzzer_set_period(a);
  __delay_cycles(2500000);
  buzzer_set_period(a);
  
  
}
