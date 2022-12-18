
#include <stdint.h>
#include "LedDriver.h"

static uint16_t * ledsAddress;

static uint16_t convertLedNumberToBit(uint16_t ledNumber)
{
    return (1 << (ledNumber -1));
}

void LedDriver_Create(uint16_t * address)
{
    ledsAddress = address;
    *address = 0;
}

void LedDriver_TurnOn(int ledNumber)
{
    *ledsAddress |= convertLedNumberToBit(ledNumber);
}

void LedDriver_TurnOff(int ledNumber)
{
    *ledsAddress &= ~convertLedNumberToBit(ledNumber);
}