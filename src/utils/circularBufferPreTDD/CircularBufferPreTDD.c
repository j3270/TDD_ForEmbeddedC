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

#include <string.h>
#include "CircularBuffer.h"

typedef struct CircularBuffer
{
    bool isFull;
    bool isEmpty;
    int head;
    int tail;
    size_t size;
    int * buffer;
}CircularBuffer_t;

struct CircularBuffer * CircularBuffer_Create(size_t size, int defaultVal)
{
    CircularBuffer_t * circularBuffer = (CircularBuffer_t *) calloc(1, sizeof(CircularBuffer_t));
    if(circularBuffer != NULL)
    {
        circularBuffer->buffer = (int *) calloc(size, sizeof(int));
        memset(circularBuffer->buffer, defaultVal, size);
        circularBuffer->size = size;
        circularBuffer->head = 0;
        circularBuffer->tail = 0;
        circularBuffer->isEmpty = true;
        circularBuffer->isFull = false;
    }
    return circularBuffer;
}

bool CircularBuffer_IsEmpty(struct CircularBuffer * circularBuffer)
{
    return (!circularBuffer->isFull && (circularBuffer->head == circularBuffer->tail));
}

bool CircularBuffer_IsFull(struct CircularBuffer * circularBuffer)
{
    return circularBuffer->isFull;
}

bool CircularBuffer_Put(struct CircularBuffer * circularBuffer, int data)
{
    if(!circularBuffer->isFull)
    {
        circularBuffer->head = ((circularBuffer->head + 1) == circularBuffer->size) ? 0 : (circularBuffer->head + 1);
        circularBuffer->buffer[circularBuffer->head] = data;
        circularBuffer->isEmpty = false;
        circularBuffer->isFull = (circularBuffer->head == circularBuffer->tail);
        return true;
    }
    return false;
}

bool CircularBuffer_Get(struct CircularBuffer * circularBuffer, int * data)
{
    if(!circularBuffer->isEmpty)
    {
        circularBuffer->tail = ((circularBuffer->tail + 1) == circularBuffer->size) ? 0 : (circularBuffer->tail + 1);
        *data = circularBuffer->buffer[circularBuffer->tail];
        circularBuffer->isFull = false;
        circularBuffer->isEmpty = (circularBuffer->head == circularBuffer->tail);
        return true;
    }
    return false;
}

void CircularBuffer_Destroy(struct CircularBuffer * circularBuffer)
{
    if(circularBuffer != NULL)
    {
        free(circularBuffer);
    }
}