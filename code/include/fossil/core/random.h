/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#ifndef FOSSIL_TOOL_RANDOM_H
#define FOSSIL_TOOL_RANDOM_H

/**
 * @brief Library for platform-independent random number generation.
 *
 * This library provides functions for generating random numbers of various types,
 * including unsigned integers of different sizes, integers within specified ranges,
 * floating-point numbers between 0 and 1, and random binary, hexadecimal, and octal
 * numbers with customizable bit lengths. It also includes a function to yield a seed
 * value based on various entropy sources.
 *
 * The library supports both non-threaded and threaded modes. In threaded mode,
 * thread safety is ensured using mutex locks for concurrent access to the random
 * number generator.
 *
 * Usage:
 *  1. Include "fossil/core/random.h" in your source code.
 *  2. Initialize the random number generator using fossil_random_seed().
 *  3. Use various functions to generate random numbers as needed.
 *  4. Optionally, use fossil_random_yield_seed() to obtain a seed value.
 *
 * Example:
 * ```c
 * #include "fossil/core/random.h"
 * #include <stdio.h>
 *
 * int main() {
 *     fossil_random_t rng;
 *     fossil_random_seed(&rng, 12345);
 *     printf("Random uint32: %u\n", fossil_random_uint32(&rng));
 *     printf("Random float: %f\n", fossil_random_float(&rng));
 *     return 0;
 * }
 * ```
 */


#include "fossil/common/common.h"

typedef struct {
    uint32_t current_seed;
} fossil_random_t;

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// Avalable functions
// =================================================================

/**
 * @brief Initialize the random number generator with a specified seed.
 *
 * This function sets the initial seed for the random number generator.
 * If threading support is enabled, it also initializes a mutex for
 * ensuring thread safety.
 *
 * @param rng Pointer to the fossil_random_t struct to be initialized.
 * @param seed The seed value to initialize the generator.
 */
void fossil_random_seed(fossil_random_t* rng, uint32_t seed);

/**
 * @brief Generate a random 8-bit unsigned integer.
 *
 * This function returns a random 8-bit unsigned integer
 * using the internal state of the random number generator.
 *
 * @param rng Pointer to the fossil_random_t struct.
 * @return A random 8-bit unsigned integer.
 */
uint8_t fossil_random_uint8(fossil_random_t* rng);

/**
 * @brief Generate a random 16-bit unsigned integer.
 *
 * This function returns a random 16-bit unsigned integer
 * using the internal state of the random number generator.
 *
 * @param rng Pointer to the fossil_random_t struct.
 * @return A random 16-bit unsigned integer.
 */
uint16_t fossil_random_uint16(fossil_random_t* rng);

/**
 * @brief Generate a random 32-bit unsigned integer.
 *
 * This function returns a random 32-bit unsigned integer
 * using the internal state of the random number generator.
 *
 * @param rng Pointer to the fossil_random_t struct.
 * @return A random 32-bit unsigned integer.
 */
uint32_t fossil_random_uint32(fossil_random_t* rng);

/**
 * @brief Generate a random 64-bit unsigned integer.
 *
 * This function returns a random 64-bit unsigned integer
 * using the internal state of the random number generator.
 *
 * @param rng Pointer to the fossil_random_t struct.
 * @return A random 64-bit unsigned integer.
 */
uint64_t fossil_random_uint64(fossil_random_t* rng);

/**
 * @brief Generate a random integer within a specified range.
 *
 * This function returns a random integer between the specified
 * minimum and maximum values (inclusive) using the internal state
 * of the random number generator.
 *
 * @param rng Pointer to the fossil_random_t struct.
 * @param min The minimum value of the range.
 * @param max The maximum value of the range.
 * @return A random integer within the specified range.
 */
int32_t fossil_random_int_range(fossil_random_t* rng, int32_t min, int32_t max);

/**
 * @brief Generate a random float between 0 and 1.
 *
 * This function returns a random floating-point number
 * between 0 (inclusive) and 1 (exclusive) using the internal
 * state of the random number generator.
 *
 * @param rng Pointer to the fossil_random_t struct.
 * @return A random float between 0 and 1.
 */
float fossil_random_float(fossil_random_t* rng);

/**
 * @brief Generate a random double between 0 and 1.
 *
 * This function returns a random double-precision floating-point
 * number between 0 (inclusive) and 1 (exclusive) using the internal
 * state of the random number generator.
 *
 * @param rng Pointer to the fossil_random_t struct.
 * @return A random double between 0 and 1.
 */
double fossil_random_double(fossil_random_t* rng);

/**
 * @brief Generate a random hexadecimal number with a specific number of bits.
 *
 * This function returns a random hexadecimal number with the specified
 * number of bits using the internal state of the random number generator.
 *
 * @param rng Pointer to the fossil_random_t struct.
 * @param num_bits The number of bits for the hexadecimal number.
 * @return A random hexadecimal number with the specified number of bits.
 */
uint32_t fossil_random_hex(fossil_random_t* rng, int32_t num_bits);

/**
 * @brief Generate a random octal number with a specific number of bits.
 *
 * This function returns a random octal number with the specified
 * number of bits using the internal state of the random number generator.
 *
 * @param rng Pointer to the fossil_random_t struct.
 * @param num_bits The number of bits for the octal number.
 * @return A random octal number with the specified number of bits.
 */
uint32_t fossil_random_oct(fossil_random_t* rng, int32_t num_bits);

/**
 * @brief Generate a random binary number with a specific number of bits.
 *
 * This function returns a random binary number with the specified
 * number of bits using the internal state of the random number generator.
 *
 * @param rng Pointer to the fossil_random_t struct.
 * @param num_bits The number of bits for the binary number.
 * @return A random binary number with the specified number of bits.
 */
uint32_t fossil_random_binary(fossil_random_t* rng, int32_t num_bits);

/**
 * @brief Yield a seed value based on various entropy sources.
 *
 * This function generates a seed value by combining various entropy
 * sources such as the current time, process ID, high-resolution timer,
 * and clock cycles.
 *
 * @return A seed value generated from entropy sources.
 */
uint32_t fossil_random_yield_seed(void);

#ifdef __cplusplus
}
#endif

#endif
