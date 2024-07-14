/**
 * @file Random.h
 * @brief 
 * 
 */

#ifndef RANDOM_H
#define RANDOM_H

/**
 * @brief Seeds Cs rand with seed if non-zero, otherwise uses time
 * 
 * @param seed - seed value to use other than time (floating adc input ?)
 * @return int - Number of times srand has been called, should always return 1 (design for test)
 */
int Random_Seed(int seed);

/**
 * @brief Gets a random integer
 * 
 * @return int - Random Integer
 */
int Random_Int(void);

/**
 * @brief Returns a random integer that is >= lower and <= upper
 * 
 * @param upper - Upper limit of range
 * @param lower - Lower limit of range
 * @return int 
 */
int Random_Int_InRange(int lower, int upper);

#endif

