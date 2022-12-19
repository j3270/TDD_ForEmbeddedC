
#include <stdint.h>
#include "LedDriver.h"
#include "RuntimeError.h"

static uint16_t * ledsAddress;
static uint16_t ledsImage;

enum {ALL_LEDS_OFF = 0, ALL_LEDS_ON = ~ALL_LEDS_OFF};
enum {FIRST_LED = 1, LAST_LED = 16};

/*****************************************************************************/
static uint16_t convertLedNumberToBit(uint16_t ledNumber)
{
    return (1 << (ledNumber -1));
}

/*****************************************************************************/
static void updateHardware()
{
    *ledsAddress = ledsImage;
}

/*****************************************************************************/
static bool isLedOutOfBounds(int ledNumber)
{
    return ( ((FIRST_LED > ledNumber) || (LAST_LED < ledNumber)) );
}

/*****************************************************************************/
static void setLedImageBit(int ledNumber)
{
    ledsImage |= convertLedNumberToBit(ledNumber);
}

/*****************************************************************************/
static void clearLedImageBit(int ledNumber)
{
    ledsImage &= ~convertLedNumberToBit(ledNumber);
}

/*****************************************************************************/
void LedDriver_Create(uint16_t * address)
{
    ledsAddress = address;
    ledsImage = ALL_LEDS_OFF;
    updateHardware();
}

/*****************************************************************************/
void LedDriver_TurnOn(int ledNumber)
{
    if( isLedOutOfBounds(ledNumber) )
    {
        RUNTIME_ERROR("LED Driver: out-of-bounds LED", ledNumber);
    }
    else
    {
        setLedImageBit(ledNumber);
        updateHardware();
    }
}

/*****************************************************************************/
void LedDriver_TurnOff(int ledNumber)
{
    if( isLedOutOfBounds(ledNumber) )
    {
        RUNTIME_ERROR("LED Driver: out-of-bounds LED", ledNumber);
    }
    else
    {
        clearLedImageBit(ledNumber);
        updateHardware();
    }
}

/*****************************************************************************/
void LedDriver_TurnAllOn()
{
    ledsImage = ALL_LEDS_ON;
    updateHardware();
}

/*****************************************************************************/
void LedDriver_TurnAllOff()
{
    ledsImage = ALL_LEDS_OFF;
    updateHardware();
}

/*****************************************************************************/
bool LedDriver_IsOn(int ledNumber)
{
    return ( isLedOutOfBounds(ledNumber) ? false : ( ledsImage & convertLedNumberToBit(ledNumber) ) );
}

/*****************************************************************************/
bool LedDriver_IsOff(int ledNumber)
{
    return ( isLedOutOfBounds(ledNumber) ? true : !LedDriver_IsOn(ledNumber) );
}