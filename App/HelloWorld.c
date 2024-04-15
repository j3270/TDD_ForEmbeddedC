/**
 * @file HelloWorld.c
 * @author your name (you@domain.com)
 * @brief HelloWorld fns for modules, aka printf testing
 * @version 0.1
 * @date 2024-04-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "HelloWorld.h"
#include "CircularBuffer.h"
#include "Macros.h"
#include "Random.h"


void Random_HelloWorld(void)
{
    const int lower = -100;
    const int upper = 100;
    const size_t max_idx = 10000;
    int random_val, min, max, avg = 0;

    printf("Generate csv file of random numbers.\n");

    FILE * fp;
    fp = fopen("./Random.csv", "w+");
    for(size_t idx = 0; idx < max_idx; idx++)
    {
        random_val = Random_Int_InRange(lower, upper);

        min = MIN(min, random_val);
        max = MAX(max, random_val);
        avg += random_val;

        fprintf(fp, "%zu,%d\n", idx, random_val);
    }
    fclose(fp);

    printf("Min val = %d\n", min);
    printf("Max val = %d\n", max);
    printf("Avg val = %f\n", avg/(max_idx * 1.0f));
}

static void CircularBuffer_PrintStatus(const char * msg, struct CircularBuffer * circularBuffer)
{
    printf("\r\n%s", msg);
    printf("Is circular buffer empty = %s\r\n", CircularBuffer_IsEmpty(circularBuffer) ? "true" : "false");
    printf("Is circular buffer full  = %s\r\n", CircularBuffer_IsFull(circularBuffer) ? "true" : "false");
}

static size_t CircularBuffer_Fill(int * testArray, struct CircularBuffer * circularBuffer)
{
    size_t idx = 0;
    while(!CircularBuffer_IsFull(circularBuffer))
    {
        int testVal = Random_Int_InRange(-1000, 1000);
        testArray[idx++] = testVal;
        CircularBuffer_Put(circularBuffer, testVal);
    }
    return idx;
}

static size_t CircularBuffer_Dump(int * testArray, struct CircularBuffer * circularBuffer)
{
    size_t idx = 0;
    int testVal;

    while(!CircularBuffer_IsEmpty(circularBuffer))
    {
        CircularBuffer_Get(circularBuffer, &testVal);
        printf("Circular buffer value = %d\r\n", testVal);
        printf("Test array val at idx %d= %d\r\n", idx -1, testArray[idx++]);
    }
    return idx;
}

void CircularBuffer_HelloWorld(void)
{
    printf("Test circular buffer\r\n");
    const size_t CIRCULAR_BUFFER_SIZE = 10;
    int testArray[CIRCULAR_BUFFER_SIZE];
    int testVal = 0;
    const size_t MSG_BUF_SIZE = 64;
    char messageBuffer[MSG_BUF_SIZE];
    struct CircularBuffer * circularBuffer = CircularBuffer_Create(CIRCULAR_BUFFER_SIZE, 0xDEADBEEF);

    memset(messageBuffer, 0,MSG_BUF_SIZE);
    snprintf(messageBuffer, MSG_BUF_SIZE, "Circular Buffer status after creation\r\n");
    CircularBuffer_PrintStatus(messageBuffer, circularBuffer);

    if(circularBuffer != NULL)
    {
        int numOps = CircularBuffer_Fill(testArray, circularBuffer);
        memset(messageBuffer, 0,MSG_BUF_SIZE);
        snprintf(messageBuffer, MSG_BUF_SIZE, "Circular Buffer status after %d puts.\r\n", numOps);
        CircularBuffer_PrintStatus(messageBuffer, circularBuffer);

        numOps = CircularBuffer_Dump(testArray, circularBuffer);
        memset(messageBuffer, 0,MSG_BUF_SIZE);
        snprintf(messageBuffer, MSG_BUF_SIZE, "Circular Buffer status after %d gets.\r\n", numOps);
        CircularBuffer_PrintStatus(messageBuffer, circularBuffer);

        // Checks wrap around by removing some after fill and then filling again
        CircularBuffer_Fill(testArray, circularBuffer);
        CircularBuffer_Get(circularBuffer, &testVal);
        CircularBuffer_Get(circularBuffer, &testVal);
        CircularBuffer_Get(circularBuffer, &testVal);
        CircularBuffer_Get(circularBuffer, &testVal);
        CircularBuffer_Get(circularBuffer, &testVal);

        numOps = CircularBuffer_Fill(testArray, circularBuffer);
        memset(messageBuffer, 0,MSG_BUF_SIZE);
        snprintf(messageBuffer, MSG_BUF_SIZE, "Circular Buffer status after %d puts. Should be 5.\r\n", numOps);
        CircularBuffer_PrintStatus(messageBuffer, circularBuffer);

        numOps = CircularBuffer_Dump(testArray, circularBuffer);
        memset(messageBuffer, 0,MSG_BUF_SIZE);
        snprintf(messageBuffer, MSG_BUF_SIZE, "Circular Buffer status after %d gets.\r\n", numOps);
        CircularBuffer_PrintStatus(messageBuffer, circularBuffer);

    }

    CircularBuffer_PrintStatus("Circular Buffer status before destroy\r\n", circularBuffer);
    CircularBuffer_Destroy(circularBuffer);
}
