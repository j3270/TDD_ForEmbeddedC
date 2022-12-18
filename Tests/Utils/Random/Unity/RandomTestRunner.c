#include "unity_fixture.h"

TEST_GROUP_RUNNER(RandomUtil)
{
    RUN_TEST_CASE(RandomUtil, SeedOnce);
    RUN_TEST_CASE(RandomUtil, InRange);
}