#include <msp430.h>
#include "../timerLib/libTimer.h"

#define LED_GREEN BIT6
#define LED_RED BIT0
#define LEDS (BIT0 | BIT6)

#define SW1 1
#define SW2 2
#define SW3 4
#define SW4 8

#define SWITCHES 15

static char switch_update_interrupt_sense(){
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}
int switches = 0;

void switch_init(){
  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
}

void switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();
  switches = ~p2val & SWITCHES;
}

void buzzer_init(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

short run = 1;

void wdt_c_handler(){
  
  static int secCount = 0;

  if (switches & SW1){
    secCount++;
    if (secCount >= 1){
      run = 1;
    }
  }
  if (switches & SW2){
    secCount++;
    if (secCount >= 1){
      run = 1;
    }
  }
}

//note frequencies octave 5
float c_3 = 130.81;
float d_3 = 293.66;
float e_3 = 329.63;
float f_3 = 349.23;
float g_3 = 392.00;
float a_3 = 440.00;
float b_3 = 493.88;


void song(){
  float notes[7] = {c_3, d_3, e_3, f_3, g_3, a_3, b_3};
  int i;
  int current_led = 1;
  for(i = 0; i < 7; i++){
    if (switches & SW2){
      if (current_led == 1){
	P1OUT &= ~LED_GREEN;
	P1OUT |= LED_RED;
	current_led = 0;
      } else {
	P1OUT &= ~LED_RED;
	P1OUT |= LED_GREEN;
	current_led = 1;
      }
      buzzer_set_period(notes[i]);
      __delay_cycles(5000000);
    } else {
      break;
    }
  }
  buzzer_set_period(0);
}


void siren(){
  int i;
  for (i = 0; i < 30; i++){
    if (switches & SW1){
      P1OUT |= LED_GREEN;
      buzzer_set_period(1000);
      __delay_cycles(2500000);
      P1OUT &= ~LED_GREEN;
      buzzer_set_period(0);
      __delay_cycles(2500000);
    } else {
      break;
    }  
  }
  buzzer_set_period(0);
}

void main(){
  P1DIR |= LEDS;
  P1OUT &= ~LEDS;
  
  configureClocks();
  switch_init();
  buzzer_init();

  enableWDTInterrupts();
  or_sr(0x8);
  
  while(1){
    if (run){
      run = 0;
      if (switches & SW1){
	//SW1
	siren();
      }
      if (switches & SW2){
	//SW2
        song();
      }
      if (switches & SW3){
	//SW3
      }
    }
    or_sr(0x10);;
  }
}

void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SWITCHES){
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
}


