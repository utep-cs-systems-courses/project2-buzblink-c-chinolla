#include <msp430.h>
//buzzer.c
<<<<<<< HEAD
#include"libTimer"
#include"buzzer.h"
=======
#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
>>>>>>> 675a16871efd41ddb4364de7329299f496ff55e9

static int period = 4000;
static int rate = 200;

<<<<<<< HEAD
#define MIN 100
#define MAX 8000
=======

#define MIN_PERIOD 100
#define MAX_PERIOD 8000
>>>>>>> 675a16871efd41ddb4364de7329299f496ff55e9

void buzzer_init()
{
  timerAUpmode();
<<<<<<< HEAD
  p3SEL2 &= ~(BIT6 | BIT7):
=======
  p2SEL2 &= ~(BIT6 | BIT7);
>>>>>>> 675a16871efd41ddb4364de7329299f496ff55e9
  p2SEL &= ~BIT7;
  p2SEL |= BIT6;
  p2DIR = BIT6;

  buzzer_execute_frequency();
<<<<<<< HEAD
=======
  

>>>>>>> 675a16871efd41ddb4364de7329299f496ff55e9
}

void buzzer_execute_frequency()
{
  period += rate;
<<<<<<< HEAD
  if((rate > 0 && (period > MAX)) || (rate > 0 && (period < MIN)))
=======
  if((rate > 0 && (period > MAX_PERIOD)) || (rate > 0 && (period < MIN_PERIOD)))
>>>>>>> 675a16871efd41ddb4364de7329299f496ff55e9
    {
      rate = rate + 200;
      period += (rate << 1);
    }
  buzzer_set_period(period);
}

<<<<<<< HEAD
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
=======
void stop_buzzer(){
  buzzer_set_period(0);
}

void resume_buzzer(){
  buzzer_set_period(period);
}


void buzzer_set_period(short cycles)
{
  CCRO = cycles;
>>>>>>> 675a16871efd41ddb4364de7329299f496ff55e9
  CCR1 = cycles >> 1;
}
