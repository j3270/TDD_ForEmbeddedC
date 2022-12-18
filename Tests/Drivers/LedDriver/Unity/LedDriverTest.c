
#include "unity_fixture.h"
#include "LedDriver.h"

static uint16_t virtualLeds;

TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver)
{
    LedDriver_Create(&virtualLeds);
}

TEST_TEAR_DOWN(LedDriver)
{

}

static void expect()
{
}

static void given()
{
    
}

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
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

/**
 * @brief Construct a new TEST object
 * TurnOnLedOne
 * #2
 */
TEST(LedDriver, TurnOnLedOne)
{
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
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
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
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
    TEST_ASSERT_EQUAL_HEX16(0x0108, virtualLeds);
}

/**
 * @brief Construct a new TEST object
 * TurnAllOn
 * #5
 */
TEST(LedDriver, TurnAllOn)
{
    LedDriver_TurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, virtualLeds);
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
    TEST_ASSERT_EQUAL_HEX16(0xFF7F, virtualLeds);
} 