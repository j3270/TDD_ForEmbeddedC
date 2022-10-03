
#include <cstdio>
#include <cstring>
#include "CppUTest/TestHarness.h"

TEST_GROUP(sprintf)
{
    char output[100];
    const char * expected;

    void setup()
    {
        memset(output, 0xaa, sizeof output);
        expected = "";
    }

    void teardown()
    {

    }

    void expect(const char * s)
    {
        expected = s;
    }

    void given(int charsWritten)
    {
        LONGS_EQUAL(strlen(expected), charsWritten);
        STRCMP_EQUAL(expected, output);
        BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);
    }

    void failing_given(int charsWritten)
    {
        // Adding 1 to strlen causes failure
        LONGS_EQUAL(strlen(expected) + 1, charsWritten);
        STRCMP_EQUAL(expected, output);
        BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);
    }
};

TEST(sprintf, NoFormatOperations)
{
    expect("Hey");
    given(sprintf(output, "Hey"));
}

TEST(sprintf, InsertString)
{
    expect("Hello World\n");
    given(sprintf(output, "Hello %s\n", "World"));
}

TEST(sprintf, NoFormatOperationsFail)
{
    expect("Hey");
    failing_given(sprintf(output, "Hey"));
}