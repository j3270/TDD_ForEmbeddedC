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
