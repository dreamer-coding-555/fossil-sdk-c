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
#ifndef FOSSIL_STR_STRNUM_H
#define FOSSIL_STR_STRNUM_H

/**
 * @brief String to Numeric Conversion Functions
 * 
 * This header file contains functions for converting strings to numeric values and vice versa.
 * 
 * The functions support conversion between classic C strings, byte strings, and wide strings.
 * 
 * Usage:
 * 
 * Example:
 * 
 * @code
 * cstring number_str = "123";
 * int number = fossil_cstr_to_numeric(number_str);
 * printf("Numeric value: %d\n", number);
 * @endcode
 */

#include <fossil/string/bstring.h>
#include <fossil/string/cstring.h>
#include <fossil/string/wstring.h>

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// Available functions
// =================================================================

/**
 * String to numeric conversion functions
 */

/**
 * Convert classic C string to integer.
 * 
 * Converts the classic C string 'number' to an integer.
 * Returns the converted integer value.
 */
int fossil_cstr_to_numeric(cstring number);

/**
 * Convert byte string to integer.
 * 
 * Converts the byte string 'number' to an integer.
 * Returns the converted integer value.
 */
int fossil_bstr_to_numeric(const_bstring number);

/**
 * Convert classic C string expression to integer.
 * 
 * Evaluates the classic C string 'expression' and converts it to an integer.
 * Returns the evaluated integer value.
 */
int fossil_cstr_expression_to_numeric(cstring expression);

/**
 * Convert byte string expression to integer.
 * 
 * Evaluates the byte string 'expression' and converts it to an integer.
 * Returns the evaluated integer value.
 */
int fossil_bstr_expression_to_numeric(const_bstring expression);

/**
 * Convert integer to classic C string.
 * 
 * Converts the integer 'number' to a classic C string.
 * Returns the converted classic C string.
 */
cstring fossil_cstr_from_numeric(long long number);

/**
 * Convert integer to byte string.
 * 
 * Converts the integer 'number' to a byte string.
 * Returns the converted byte string.
 */
bstring fossil_bstr_from_numeric(long long number);

/**
 * Convert wide string to integer.
 * 
 * Converts the wide string 'number' to an integer.
 * Returns the converted integer value.
 */
int fossil_wstr_to_numeric(const_wstring number);

/**
 * Convert wide string expression to integer.
 * 
 * Evaluates the wide string 'expression' and converts it to an integer.
 * Returns the evaluated integer value.
 */
int fossil_wstr_expression_to_numeric(const_wstring expression);

/**
 * Convert integer to wide string.
 * 
 * Converts the integer 'number' to a wide string.
 * Returns the converted wide string.
 */
wstring fossil_wstr_from_numeric(long long number);

#ifdef __cplusplus
}
#endif

#endif
