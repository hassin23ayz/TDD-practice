#ifndef LED_DRIVER_H_   /* Include guard */
#define LED_DRIVER_H_

#include <stdint.h>

void ledDriver_create(uint16_t* bcktStatus);
void ledDriver_destroy(void);
void ledDriver_turnOn(int ledNumber);
void ledDriver_turnOff(int ledNumber);
void ledDriver_turnAllOn(void);

#endif // LED_DRIVER_H_
