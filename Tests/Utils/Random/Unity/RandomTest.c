
#include "unity_fixture.h"
#include "Random.h"

TEST_GROUP(RandomUtil);


TEST_SETUP(RandomUtil)
{

}

TEST_TEAR_DOWN(RandomUtil)
{

}

TEST(RandomUtil, SeedOnce)
{
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, Random_Seed(0), "Seed count does not equal one");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, Random_Seed(0), "Seed count does not equal one");
}

TEST(RandomUtil, InRange)
{
    const int upper = 100;
    const int lower = -100;

    for(size_t idx = 0; idx < 10000; idx++)
    {
        int random_val = Random_Int_InRange(0, upper, lower);
        TEST_ASSERT_TRUE_MESSAGE( ( lower <= random_val) && (upper >= random_val) , "Random value is out of range" );
    }
}