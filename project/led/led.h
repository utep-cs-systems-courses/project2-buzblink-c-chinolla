#ifndef led_included
#define led_included
#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (BITS0 | BIT6)

void led_initialized();
void led_update();

extern unsigned char leds_changed;
extern unsigned char green_on, red_on;

#endif
