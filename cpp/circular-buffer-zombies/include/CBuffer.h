#ifndef CBUFFER_H_   /* Include guard */
#define CBUFFER_H_

#include <stdbool.h>
#include <stdlib.h> 
 
typedef struct CircularBufferStruct CircularBuffer;
 
CircularBuffer* CircularBuffer_Create(int, int);
void CircularBuffer_Destroy(CircularBuffer*);
bool CircularBuffer_IsEmpty(CircularBuffer*);
bool CircularBuffer_IsFull(CircularBuffer*);
bool CircularBuffer_Put(CircularBuffer* , int);
int CircularBuffer_Get(CircularBuffer*);
int CircularBuffer_Capacity(CircularBuffer*);
void fillItUp(CircularBuffer* buffer);

#endif // LED_DRIVER_H_
