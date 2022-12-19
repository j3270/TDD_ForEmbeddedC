
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "Random.h"
#include "RuntimeError.h"

int Random_Seed(int seed)
{
    // Design for test
    static int seed_cnt = 0;

    if ( seed_cnt == 0 )
    {
        seed_cnt++;
        time_t t;
        ( seed != 0 ) ? srand(seed) : srand((unsigned int) time(&t));
    }

    return seed_cnt;
}

int Random_Int(void)
{
    Random_Seed(0);
    return rand();
}

int Random_Int_InRange(int lower, int upper)
{
    if(lower >= upper)
    {
        char message[64];
        sprintf(message, "Random: Lower >= Upper. Lower = %d, Upper = %d\n", lower, upper);
        RUNTIME_ERROR(message, (upper - lower));
        return 0;
    }
    else
    {
        return ( (Random_Int() % (upper - lower + 1)) + lower );
    }
}
