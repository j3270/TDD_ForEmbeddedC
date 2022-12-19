
#include <stdio.h>
#include <string.h>
#include "unity_fixture.h"
#include "Random.h"
#include "RuntimeErrorStub.h"


TEST_GROUP(Random);


TEST_SETUP(Random)
{

}

TEST_TEAR_DOWN(Random)
{

}

TEST(Random, SeedOnce)
{
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, Random_Seed(0), "Seed count does not equal one");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, Random_Seed(0), "Seed count does not equal one");
}

TEST(Random, InRange)
{
    const int upper = 100;
    const int lower = -100;

    for(size_t idx = 0; idx < 10000; idx++)
    {
        int random_val = Random_Int_InRange(lower, upper);
        TEST_ASSERT_TRUE_MESSAGE( ( lower <= random_val) && (upper >= random_val) , "Random value is out of range" );
    }
}

TEST(Random, UpperGreaterThanLowerThrowsError)
{
    int upper = 0;
    int lower = 1;
    char expected[64];
    char actual[64];

    sprintf(expected, "Random: Lower >= Upper. Lower = %d, Upper = %d\n", lower, upper);
    Random_Int_InRange(lower, upper);
    memcpy(actual, RuntimeErrorStub_GetLastError(), 64);

    STRCMP_EQUAL(expected, actual);
}