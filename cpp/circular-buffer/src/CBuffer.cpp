#include "CBuffer.h"


#define BUFF_SIZE 4

uint8_t buff[BUFF_SIZE];
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

bool isFull(void)
{
	if(pushIndex == BUFF_SIZE)
		{return true;}
	else
		{return false;}
}

void put(int v)
{
	if(isFull() != true)
	{
		buff[pushIndex++] = v;
	}
}

int get(void)
{
	if(isEmpty()){
		return -1;
	}
	if((popIndex == (BUFF_SIZE-1)) && (isFull() == true))
	{
		uint8_t v = buff[popIndex];
		clear();
		return v;
	}
	else if(popIndex < pushIndex)
	{
		return buff[popIndex++];
	}
	else
	{
		return -1;
	}
}