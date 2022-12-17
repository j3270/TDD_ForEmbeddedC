/**
 * @file LedDriver.h
 * @brief Example driver from TDD for embedded C book
 * 
 */
#pragma once

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