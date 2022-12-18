
#include <stdint.h>
#include "LedDriver.h"

static uint16_t * ledsAddress;

enum {ALL_LEDS_OFF = 0, ALL_LEDS_ON = ~ALL_LEDS_OFF};

static uint16_t convertLedNumberToBit(uint16_t ledNumber)
{
    return (1 << (ledNumber -1));
}

void LedDriver_Create(uint16_t * address)
{
    ledsAddress = address;
    *ledsAddress = ALL_LEDS_OFF;
}

void LedDriver_TurnOn(int ledNumber)
{
    *ledsAddress |= convertLedNumberToBit(ledNumber);
}

void LedDriver_TurnOff(int ledNumber)
{
    *ledsAddress &= ~convertLedNumberToBit(ledNumber);
}

void LedDriver_TurnAllOn()
{
    *ledsAddress = ALL_LEDS_ON;
}