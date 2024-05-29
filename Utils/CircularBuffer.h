/**
 * @file CircularBuffer.h
 * @author your name (you@domain.com)
 * @brief Circular buffer implementation for ints
 * @version 0.1
 * @date 2024-04-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include <stdbool.h>

struct CircularBuffer;
/**
 * @brief Creates a circular FIFO buffer of size 'size' initialized with a dfault value of 'defaultVal'
 * 
 * @return struct CircularBuffer* 
 */
struct CircularBuffer * CircularBuffer_Create();

bool CircularBuffer_IsEmpty(struct CircularBuffer * self);

bool CircularBuffer_IsFull(struct CircularBuffer * self);

void CircularBuffer_Put(struct CircularBuffer * self, int data);

int CircularBuffer_Get(struct CircularBuffer * self);

/**
 * @brief Frees memory used by circularBuffer
 * 
 * @param circularBuffer - Buffer to destroy
 */
void CircularBuffer_Destroy(struct CircularBuffer * self); 

#endif /* CIRCULAR_BUFFER_H_ */