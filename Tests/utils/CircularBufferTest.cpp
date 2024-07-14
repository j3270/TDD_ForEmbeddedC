

#include "CppUTest/TestHarness.h"

extern "C"
{
    #include "CircularBuffer.h"
}


TEST_GROUP(CircularBuffer)
{
    CircularBuffer * buffer;

    void setup()
    {
        buffer = CircularBuffer_Create();
    }

    void teardown()
    {
        CircularBuffer_Destroy(buffer);
    }
};

TEST(CircularBuffer, is_empty_after_create)
{
    CHECK(CircularBuffer_IsEmpty(buffer));
}

TEST(CircularBuffer, is_not_full_after_create)
{
    CHECK_FALSE(CircularBuffer_IsFull(buffer));
}

TEST(CircularBuffer, is_not_empty_after_put)
{
    CircularBuffer_Put(buffer, 42);
    CHECK_FALSE(CircularBuffer_IsEmpty(buffer));
}

TEST(CircularBuffer, is_empty_after_put_then_get)
{
    CircularBuffer_Put(buffer, 42);
    CircularBuffer_Get(buffer);
    CHECK(CircularBuffer_IsEmpty(buffer));
}

TEST(CircularBuffer, get_equals_put_for_one_value)
{
    CircularBuffer_Put(buffer, 42);
    LONGS_EQUAL(42, CircularBuffer_Get(buffer));
}

TEST(CircularBuffer, get_equals_put_for_fifo)
{
    CircularBuffer_Put(buffer, 42);
    CircularBuffer_Put(buffer, 43);
    CircularBuffer_Put(buffer, 44);
    LONGS_EQUAL(42, CircularBuffer_Get(buffer));
    LONGS_EQUAL(43, CircularBuffer_Get(buffer));
    LONGS_EQUAL(44, CircularBuffer_Get(buffer));
}
