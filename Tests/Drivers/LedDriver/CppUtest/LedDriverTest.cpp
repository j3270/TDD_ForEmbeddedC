/**
 * @file LedDriverTest.cpp
 * @brief 
 */

#include "CppUTest/TestHarness.h"
extern "C"
{
    #include "LedDriver.h"
    #include "RuntimeErrorStub.h"
} 

static uint16_t virtualLeds;

TEST_GROUP(LedDriver)
{
    void setup()
    {
        RuntimeErrorStub_Reset();
        LedDriver_Create(&virtualLeds);
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

/**
 * @brief Construct a new TEST object
 * LedsOffAfterCreate
 * #1
 * 
 */
TEST(LedDriver, LedsOffAfterCreate)
{
    //TEST_FAIL_MESSAGE("Start here");
    virtualLeds = 0xffff;
    LedDriver_Create(&virtualLeds);
    LONGS_EQUAL(0, virtualLeds);
}

/**
 * @brief Construct a new TEST object
 * TurnOnLedOne
 * #2
 */
TEST(LedDriver, TurnOnLedOne)
{
    LedDriver_TurnOn(1);
    LONGS_EQUAL(1, virtualLeds);
}

/**
 * @brief Construct a new TEST object
 * TurnOffLedOne
 * #3
 */
TEST(LedDriver, TurnOffLedOne)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    LONGS_EQUAL(0, virtualLeds);
}

/**
 * @brief Construct a new TEST object
 * TurnOnMultipleLeds
 * #4
 */
TEST(LedDriver, TurnOnMultipleLeds)
{
    LedDriver_TurnOn(9);
    LedDriver_TurnOn(4);
    LONGS_EQUAL(0x0108, virtualLeds);
}

/**
 * @brief Construct a new TEST object
 * TurnAllOn
 * #5
 */
TEST(LedDriver, TurnAllOn)
{
    LedDriver_TurnAllOn();
    LONGS_EQUAL(0xFFFF, virtualLeds);
}

/**
 * @brief Construct a new TEST object
 * TurnOffAnyLed
 * #6
 */
TEST(LedDriver, TurnOffAnyLed)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(8);
    LONGS_EQUAL(0xFF7F, virtualLeds);
} 

/**
 * @brief Construct a new TEST object
 * LedMemoryIsNotReadable
 * #7
 */
TEST(LedDriver, LedMemoryIsNotReadable)
{
    virtualLeds = 0xffff;
    LedDriver_TurnOn(8);
    LONGS_EQUAL(0x0080, virtualLeds);
}

/**
 * @brief Construct a new TEST object
 * UpperAndLowerBounds
 * #8
 */
TEST(LedDriver, UpperAndLowerBounds)
{
    LedDriver_TurnOn(1);
    LedDriver_TurnOn(16);
    LONGS_EQUAL(0x8001, virtualLeds);
}

/**
 * @brief Construct a new TEST object
 * OutOfBoundsTurnOnDoesNoHarm
 * #9
 */
TEST(LedDriver, OutOfBoundsTurnOnDoesNoHarm)
{
    LedDriver_TurnOn(-1);
    LedDriver_TurnOn(0);
    LedDriver_TurnOn(17);
    LedDriver_TurnOn(3141);
    LONGS_EQUAL(0, virtualLeds);
}

/**
 * @brief Construct a new TEST object
 * OutOfBoundsTurnOffDoesNoHarm
 * #10
 */
TEST(LedDriver, OutOfBoundsTurnOffDoesNoHarm)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(-1);
    LedDriver_TurnOff(0);
    LedDriver_TurnOff(17);
    LedDriver_TurnOff(3141);
    LONGS_EQUAL(0xFFFF, virtualLeds);
}

/**
 * @brief Construct a new TEST object
 * OutOfBoundsTurnOnProducesRuntimeError
 * #11
 */
TEST(LedDriver, OutOfBoundsTurnOnProducesRuntimeError)
{
    LedDriver_TurnOn(-1);
    STRCMP_EQUAL("LED Driver: out-of-bounds LED", RuntimeErrorStub_GetLastError());
    LONGS_EQUAL(-1, RuntimeErrorStub_GetLastParameter());
}

/**
 * @brief Construct a new TEST object
 * OutOfBoundsTurnOffProducesRuntimeError
 * #12
 */
TEST(LedDriver, OutOfBoundsTurnOffProducesRuntimeError)
{
    LedDriver_TurnOff(-1);
    STRCMP_EQUAL("LED Driver: out-of-bounds LED", RuntimeErrorStub_GetLastError());
    LONGS_EQUAL(-1, RuntimeErrorStub_GetLastParameter());
}

/**
 * @brief Construct a new ignore test object
 * OutOfBoundsToDo
 * #13
 */
IGNORE_TEST(LedDriver, OutOfBoundsToDo)
{
    /* TODO: what should we do during runtime? */
}

/**
 * @brief Construct a new TEST object
 * IsOn
 * #14
 */
TEST(LedDriver, IsOn)
{
    CHECK_FALSE(LedDriver_IsOn(11));
    LedDriver_TurnOn(11);
    CHECK_TRUE(LedDriver_IsOn(11));
}

/**
 * @brief Construct a new TEST object
 * OutOfBoundsLedsAreAlwaysOff
 * #15
 */
TEST(LedDriver, OutOfBoundsLedsAreAlwaysOff)
{
    CHECK_FALSE(LedDriver_IsOn(0));
    CHECK_FALSE(LedDriver_IsOn(17));
}

/**
 * @brief Construct a new TEST object
 * IsOff
 * #16
 */
TEST(LedDriver, IsOff)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(10);
    CHECK_TRUE(LedDriver_IsOff(10));
}

/**
 * @brief Construct a new TEST object
 * TurnOffMultipleLeds
 * #17
 */
TEST(LedDriver, TurnOffMultipleLeds)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnOff(10);
    LedDriver_TurnOff(9);
    LONGS_EQUAL(0xFCFF, virtualLeds);
}

/**
 * @brief Construct a new TEST object
 * TurnAllOff
 * #18
 */
TEST(LedDriver, TurnAllOff)
{
    LedDriver_TurnAllOn();
    LONGS_EQUAL(0xFFFF, virtualLeds);
    LedDriver_TurnAllOff();
    LONGS_EQUAL(0, virtualLeds);
}
