/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-12-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include "Random.h"
#include "Macros.h"

int main(int argc, char * argv[])
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

        fprintf(fp, "%d,%d\n", idx, random_val);
    }
    fclose(fp);

    printf("Min val = %d\n", min);
    printf("Max val = %d\n", max);
    printf("Avg val = %f\n", avg/(max_idx * 1.0f));
    return 0;
}