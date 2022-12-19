#include "unity_fixture.h"

TEST_GROUP_RUNNER(Random)
{
    RUN_TEST_CASE(Random, SeedOnce);
    RUN_TEST_CASE(Random, InRange);
    RUN_TEST_CASE(Random, UpperGreaterThanLowerThrowsError);

    
}