
#include <iostream>
#include <cstring>
#include <string>
#include "CppUTest/TestHarness.h"

extern "C"
{
    #include <stdio.h>
    #include "Random.h"
    #include "RuntimeErrorStub.h"
}


TEST_GROUP(Random)
{
    void setup()
    {
        RuntimeErrorStub_Reset();
    }

    void teardown()
    {
    }

    void expect()
    {
    }

    void given()
    {
    }
};

TEST(Random, SeedOnce)
{
    LONGS_EQUAL_TEXT(1, Random_Seed(0), "Seed count does not equal one");
    LONGS_EQUAL_TEXT(1, Random_Seed(0), "Seed count does not equal one");
}

TEST(Random, InRange)
{
    const int upper = 100;
    const int lower = -100;

    for(size_t idx = 0; idx < 10000; idx++)
    {
        int random_val = Random_Int_InRange(lower, upper);
        CHECK_TRUE_TEXT( ( lower <= random_val) && (upper >= random_val) , "Random value is out of range" );
    }
}

TEST(Random, UpperGreaterThanLowerThrowsError)
{
    int upper = 0;
    int lower = 1;
    char actual[64];

    std::string expected {"Random: Lower >= Upper. Lower = " + std::to_string(lower) + ", Upper = " + std::to_string(upper) + "\n"};
    Random_Int_InRange(lower, upper);
    memcpy(actual, RuntimeErrorStub_GetLastError(), 64);

    STRCMP_EQUAL(expected.c_str(), actual);
}