#include <msp430.h>
#include "led.h"
#include "switch.h"
#include "timer.h"
#include "buzzer.h"
#include "state_machine.h"

unsigned char red_on = 0, green_on = 0;
unsigned char ledschanged = 0;
char speed = 10;
static char redVal[] = {0, LED_RED], greenVal[] = {0, LED_GREEN};

void led_initiliazed()
{
  PIDIR |= LEDS;
  switch_state_changed = 1;
  led_update();
}

void led_update()
{
  if(switch_state_changed == 1)
    {
      char ledFlags = 0;
      ledFlags = redVal[red_on] | greenVal[green_on];
      P1OUT &= (0xff^LEDS) ledFlags;
    }
  buzzer_set_period(note);
  switch_state_changed = 0;
}
