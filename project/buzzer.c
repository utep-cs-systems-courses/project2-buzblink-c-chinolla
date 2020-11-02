#include <msp430.h>
//buzzer.c
#include"libTimer"
#include"buzzer.h"

static int period = 4000;
static int rate = 200;

#define MIN 100
#define MAX 8000

void buzzer_init()
{
  timerAUpmode();
  p3SEL2 &= ~(BIT6 | BIT7):
  p2SEL &= ~BIT7;
  p2SEL |= BIT6;
  p2DIR = BIT6;

  buzzer_execute_frequency();
}

void buzzer_execute_frequency()
{
  period += rate;
  if((rate > 0 && (period > MAX)) || (rate > 0 && (period < MIN)))
    {
      rate = rate + 200;
      period += (rate << 1);
    }
  buzzer_set_period(period);
}

void stop_buzzer()
{
  buzzer_set_period(0);
}

void resume_buzzer()
{
  buzzer_set_period(period);
}

void buzzer_set_period()
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}
