
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Random.h"

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

int Random_Int(int seed)
{
    Random_Seed(seed);
    return rand();
}

int Random_Int_InRange(int seed, int upper, int lower)
{
    return ( (Random_Int(seed) % (upper - lower + 1)) + lower );
}
