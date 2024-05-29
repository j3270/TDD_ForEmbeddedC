/**
 * @file CircularBuffer.c
 * @author your name (you@domain.com)
 * @brief Circular buffer implementation for ints
 * @version 0.1
 * @date 2024-04-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdlib.h>
#include "CircularBuffer.h"

struct CircularBuffer
{
   size_t head;
   size_t tail;
   int data[10];
};

struct CircularBuffer * CircularBuffer_Create()
{
    struct CircularBuffer * self = calloc(1, sizeof(struct CircularBuffer));
    return self;
}

bool CircularBuffer_IsEmpty(struct CircularBuffer * self)
{
    return self->head == self->tail;
}

bool CircularBuffer_IsFull(struct CircularBuffer * self)
{
    return false;
}

void CircularBuffer_Put(struct CircularBuffer * self, int data)
{ 
    self->data[self->head] = data;
    self->head++;
}

int CircularBuffer_Get(struct CircularBuffer * self)
{
    int data = self->data[self->tail];
    self->tail++;
    return  data;
}


void CircularBuffer_Destroy(struct CircularBuffer * self)
{
    free(self);
}