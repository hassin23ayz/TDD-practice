#include "CBuffer.h"


#define BUFF_SIZE 4

uint8_t buff[BUFF_SIZE];
uint8_t inIndex = 0;
uint8_t outIndex = 0;


void clear(void)
{
	inIndex = 0;
	outIndex = 0;
}

bool isEmpty(void)
{
	if(inIndex == outIndex)
		{return true;}
	else 
		{return false;}
}

bool isFull(void)
{
	if(((inIndex - outIndex) == 4) || (inIndex < outIndex))
	{
		return true;
	}
	else
	{
		return false;
	}

/*
	if(inIndex == BUFF_SIZE)
		{return true;}
	else
		{return false;}
*/
}

void put(int v)
{
	if(isFull() != true)
	{
		if(inIndex == 4){inIndex = 0;}
		buff[inIndex++] = v;
	}
}

int get(void)
{
	if(isEmpty()){
		return -1;
	}

	return buff[outIndex++];

}