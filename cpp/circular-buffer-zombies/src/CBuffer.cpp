#include "CBuffer.h"

struct CircularBufferStruct
{
    int index;
    int outdex;
    int capacity;
    int count;
    int defaultValue;
    int values[];
};
 
CircularBuffer* CircularBuffer_Create(int capacity, int defaultValue)
{
    int size = sizeof(CircularBuffer) + capacity * sizeof(int);
    CircularBuffer* self = (CircularBuffer*)malloc(size);
    self->capacity = capacity;
    self->index = 0;
    self->outdex = 0;
    self->count = 0;
    self-> defaultValue = defaultValue;
    return self;
}
 
void CircularBuffer_Destroy(CircularBuffer* self)
{
    free(self);
}
 
bool CircularBuffer_IsEmpty(CircularBuffer* self)
{
    return self->count == 0;
}
 
bool CircularBuffer_IsFull(CircularBuffer* self)
{
    return self->count == self->capacity;
}

static unsigned int nextIndex(CircularBuffer * self, unsigned int dex)
{
    dex++;
    if (dex >= self->capacity)
        dex = 0;
    return dex;
}

bool CircularBuffer_Put(CircularBuffer* self , int value)
{
	if(CircularBuffer_IsFull(self))
		return false;

	self->count++;
    self->values[self->index] = value;
    self->index = nextIndex(self, self->index);	
    return true;
}

int CircularBuffer_Get(CircularBuffer* self)
{
	if(CircularBuffer_IsEmpty(self))
		return self->defaultValue;;

    int value;
    self->count--;
    value = self->values[self->outdex];
    self->outdex = nextIndex(self, self->outdex);
 
    return value;
}

int CircularBuffer_Capacity(CircularBuffer* self)
{
	return self->capacity;
}

void fillItUp(CircularBuffer* buffer)
{
    for (int i = 0; i < CircularBuffer_Capacity(buffer); i++)
        CircularBuffer_Put(buffer, i);
}
