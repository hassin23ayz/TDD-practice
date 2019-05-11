#include "CBuffer.h"

uint8_t buff[4];
uint8_t pushIndex = 0;
uint8_t popIndex = 0;


void clear(void)
{
	pushIndex = 0;
	popIndex = 0;
}

bool isEmpty(void)
{
	if((pushIndex == 0) && (popIndex == 0))
		{return true;}
	else 
		{return false;}
}

void put(int v)
{
	if((v >= 0) && (v <= 255))
	{
		buff[pushIndex] = v;
		pushIndex++;
		if(pushIndex == 4){
			pushIndex = 0;
		}		
	} 
}

int get(void)
{
	if(isEmpty()){
		return -1;
	}
	if(popIndex == 4){
		popIndex = 0;
	}
    if(popIndex == pushIndex)
    {
    	return -1;
    }
	return buff[popIndex++];
}