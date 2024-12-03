#include <msp430.h>
#include <libTimer.h>
#include "buzzer.h"

void buzzer_init()
{
  timerAUpmode();  
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;  
}

void buzzer_set_period(short cycles)   // buzzer clock = 2Mhz 
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;   // One half cycle
}
