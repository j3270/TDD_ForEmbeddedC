/**
 * @file LedDriver.h
 * @brief Example driver from TDD for embedded C book
 * 
 */

#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <stdbool.h>

/**
 * @brief Initializes LEDs ensuring they are turned off
 * 
 * @param address - memeory mapped IO controlling LEDs
 */
void LedDriver_Create(uint16_t * address);

/**
 * @brief Turns on given LED
 * 
 * @param ledNumber - LED to turn on
 */
void LedDriver_TurnOn(int ledNumber);

/**
 * @brief Turns off given LED
 * 
 * @param ledNumber - LED to turn off
 */
void LedDriver_TurnOff(int ledNumber);

/**
 * @brief Turns all LEDs on
 * 
 */
void LedDriver_TurnAllOn();

/**
 * @brief Turn all LEDs off
 * 
 */
void LedDriver_TurnAllOff();

/**
 * @brief Check if LED is on
 * 
 * @param ledNumber - number of lED to check
 * @return true - LED is on
 * @return false - LED isn't on
 */
bool LedDriver_IsOn(int ledNumber);

/**
 * @brief Check if LED is off
 * 
 * @param ledNumber - number of lED to check
 * @return true - LED is off
 * @return false - LED isn't off
 */
bool LedDriver_IsOff(int ledNumber);

#endif