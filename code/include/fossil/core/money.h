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
#ifndef FOSSIL_TOOL_MONEY_H
#define FOSSIL_TOOL_MONEY_H

/**
 * @brief Functions for handling monetary values including creation, addition, subtraction, conversion, and comparison.
 *
 * This file provides functions for creating, manipulating, and comparing monetary values.
 * It includes functions for performing arithmetic operations such as addition, subtraction,
 * multiplication, and division on monetary values. Additionally, it provides functions for
 * rounding monetary values to the nearest whole cent, as well as checking if a monetary value
 * is positive, negative, or zero.
 *
 * Usage:
 *  1. Include "fossil_money.h" in your source code.
 *  2. Use fossil_money_create() to create a monetary value with specified dollars, cents, and currency.
 *  3. Use various arithmetic functions like fossil_money_add(), fossil_money_subtract(),
 *     fossil_money_multiply_scalar(), and fossil_money_divide_scalar() to perform operations on monetary values.
 *  4. Use fossil_money_convert() to convert a monetary value to a different currency.
 *  5. Use comparison functions like fossil_money_compare() to compare two monetary values.
 *  6. Use utility functions like fossil_money_round(), fossil_money_is_positive(), fossil_money_is_negative(),
 *     and fossil_money_is_zero() for additional operations and checks.
 *
 * Example:
 * ```c
 * #include "fossil_money.h"
 * #include <stdio.h>
 *
 * int main() {
 *     // Create monetary values
 *     fossil_money_t m1 = fossil_money_create(10, 50, USD);
 *     fossil_money_t m2 = fossil_money_create(5, 25, USD);
 *
 *     // Perform arithmetic operations
 *     fossil_money_t result = fossil_money_add(m1, m2);
 *
 *     // Display result
 *     fossil_money_display(result);
 *
 *     return 0;
 * }
 * ```
 *
 */

#include "fossil/common/common.h"

// Enum to represent different currency types
typedef enum {
    USD,
    CAD,
    GBP,
    RUB,
    INR,
    JPY
} fossil_currency_t;

// Structure to represent money
typedef struct {
    int32_t dollars;
    int32_t cents;
    fossil_currency_t currency;
} fossil_money_t;

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// Avalable functions
// =================================================================

/**
 * Create a monetary value with the specified dollars, cents, and currency.
 *
 * @param dollars   The amount in dollars.
 * @param cents     The amount in cents.
 * @param currency  The currency of the monetary value.
 * @return          The created monetary value.
 */
fossil_money_t fossil_money_create(int32_t dollars, int32_t cents, fossil_currency_t currency);

/**
 * Add two monetary values.
 *
 * @param m1 The first monetary value.
 * @param m2 The second monetary value.
 * @return   The result of adding the two monetary values.
 */
fossil_money_t fossil_money_add(fossil_money_t m1, fossil_money_t m2);

/**
 * Convert a monetary value to a different currency.
 *
 * @param source         The source monetary value.
 * @param target_currency The target currency for conversion.
 * @return               The converted monetary value.
 */
fossil_money_t fossil_money_convert(fossil_money_t source, fossil_currency_t target_currency);

/**
 * Display the details of a monetary value.
 *
 * @param m The monetary value to display.
 */
void fossil_money_display(fossil_money_t m);

/**
 * Check if a monetary value is valid.
 *
 * @param m The monetary value to check.
 * @return  1 if the monetary value is valid, 0 otherwise.
 */
int32_t fossil_money_is_valid(fossil_money_t m);

/**
 * Compare two monetary values.
 *
 * @param m1 The first monetary value.
 * @param m2 The second monetary value.
 * @return   0 if m1 equals m2, 1 if m1 is greater, -1 if m1 is smaller.
 */
int32_t fossil_money_compare(fossil_money_t m1, fossil_money_t m2);

/**
 * Subtract two monetary values.
 *
 * @param m1 The first monetary value.
 * @param m2 The second monetary value.
 * @return   The result of subtracting the second monetary value from the first.
 */
fossil_money_t fossil_money_subtract(fossil_money_t m1, fossil_money_t m2);

/**
 * Multiply a monetary value by a scalar.
 *
 * @param m      The monetary value.
 * @param scalar The scalar to multiply by.
 * @return       The result of multiplying the monetary value by the scalar.
 */
fossil_money_t fossil_money_multiply_scalar(fossil_money_t m, int32_t scalar);

/**
 * Divide a monetary value by a scalar.
 *
 * @param m       The monetary value.
 * @param divisor The divisor to divide by.
 * @return        The result of dividing the monetary value by the divisor.
 */
fossil_money_t fossil_money_divide_scalar(fossil_money_t m, int32_t divisor);

/**
 * Round a monetary value to the nearest whole cent.
 *
 * @param m The monetary value to round.
 * @return  The rounded monetary value.
 */
fossil_money_t fossil_money_round(fossil_money_t m);

/**
 * Check if a monetary value is positive.
 *
 * @param m The monetary value to check.
 * @return  1 if the monetary value is positive, 0 otherwise.
 */
int32_t fossil_money_is_positive(fossil_money_t m);

/**
 * Check if a monetary value is negative.
 *
 * @param m The monetary value to check.
 * @return  1 if the monetary value is negative, 0 otherwise.
 */
int32_t fossil_money_is_negative(fossil_money_t m);

/**
 * Check if a monetary value is zero.
 *
 * @param m The monetary value to check.
 * @return  1 if the monetary value is zero, 0 otherwise.
 */
int32_t fossil_money_is_zero(fossil_money_t m);

#ifdef __cplusplus
}
#endif

#endif
