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

#include <stdlib.h>
#include <stdbool.h>


/**
 * @brief Creates a circular FIFO buffer of size 'size' initialized with a dfault value of 'defaultVal'
 * 
 * @param size - size of circularBuffer to create
 * @param defaultVal - default value of elements in circularBuffer.
 * @return struct CircularBuffer* 
 */
struct CircularBuffer * CircularBuffer_Create(size_t size, int defaultVal);

/**
 * @brief Checks if circularBuffer is empty
 * 
 * @param circularBuffer - Buffer to check
 * @return true 
 * @return false 
 */
bool CircularBuffer_IsEmpty(struct CircularBuffer * circularBuffer);

/**
 * @brief Checks if circularBuffer is full
 * 
 * @param circularBuffer - Buffer to check
 * @return true 
 * @return false 
 */
bool CircularBuffer_IsFull(struct CircularBuffer * circularBuffer);

/**
 * @brief Puts integer into circularBuffer at head location if not full
 * 
 * @param circularBuffer - Buffer to put integer into
 * @param[in] data - integer to inset into head location of circularBuffer
 * @return true 
 * @return false 
 */
bool CircularBuffer_Put(struct CircularBuffer * circularBuffer, int data);

/**
 * @brief Gets integer from circularBuffer at tail location if not empty
 * 
 * @param circularBuffer - Buffer to get integer from
 * @param[out] data - integer at tail location of circularBuffer
 * @return true 
 * @return false 
 */
bool CircularBuffer_Get(struct CircularBuffer * circularBuffer, int * data);

/**
 * @brief Frees memory used by circularBuffer
 * 
 * @param circularBuffer - Buffer to destroy
 */
void CircularBuffer_Destroy(struct CircularBuffer * circularBuffer); 

#endif /* CIRCULAR_BUFFER_H_ */