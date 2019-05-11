#include "LedDriver.h"

static uint16_t* bkctledStatus_all;
void ledDriver_create(uint16_t* bcktStatus)
{
	bkctledStatus_all = bcktStatus;
	*bkctledStatus_all = 0;
}

void ledDriver_destroy(void)
{
	
}

void ledDriver_turnOn(int ledNumber)
{
	*bkctledStatus_all = 1;
}

void ledDriver_turnOff(int ledNumber)
{
	*bkctledStatus_all = 0;
}