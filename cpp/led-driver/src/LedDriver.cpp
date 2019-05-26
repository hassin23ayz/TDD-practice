#include "LedDriver.h"

static uint16_t* bkctledStatus_all;

enum{
	ALL_LEDS_ON = ~0,
	ALL_LEDS_OFF = ~ALL_LEDS_ON
};

static uint16_t convertLedNumberToBit(int ledNumber)
{
	return (1 << (ledNumber-1));
}

void ledDriver_create(uint16_t* bcktStatus)
{
	bkctledStatus_all = bcktStatus;
	*bkctledStatus_all = ALL_LEDS_OFF;
}

void ledDriver_destroy(void)
{
	
}

void ledDriver_turnOn(int ledNumber)
{
	*bkctledStatus_all |= convertLedNumberToBit(ledNumber);
}

void ledDriver_turnOff(int ledNumber)
{
	*bkctledStatus_all &= ~(convertLedNumberToBit(ledNumber));
}

void ledDriver_turnAllOn(void)
{
	*bkctledStatus_all = ALL_LEDS_ON;	
}

