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
#ifndef FOSSIL_STR_STRTO_H
#define FOSSIL_STR_STRTO_H

/**
 * @brief String Conversion Functions
 * 
 * This header file contains functions for converting strings to various data types.
 * 
 * The functions support classic C strings, byte strings, and wide strings.
 * 
 * Usage:
 * 
 * Example:
 * 
 * @code
 * const_cstring str = "12345";
 * int num = fossil_cstr_to_int(str);
 * printf("Integer: %d\n", num);
 * @endcode
 */

#include "string/bstring.h"
#include "string/cstring.h"
#include "string/wstring.h"

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// Available functions
// =================================================================

//
// Convert classic C string to equilivent type
//

/**
 * Convert classic C string to integer
 * 
 * Converts the given classic C string 'str' to an integer.
 * Returns the converted integer value.
 */
int fossil_cstr_to_int(const_cstring str);

/**
 * Convert classic C string to floating point number
 * 
 * Converts the given classic C string 'str' to a double precision floating point number.
 * Returns the converted floating point number.
 */
double fossil_cstr_to_double(const_cstring str);

/**
 * Convert classic C string to long integer
 * 
 * Converts the given classic C string 'str' to a long integer.
 * Returns the converted long integer value.
 */
long fossil_cstr_to_long(const_cstring str);

/**
 * Convert classic C string to unsigned long integer
 * 
 * Converts the given classic C string 'str' to an unsigned long integer.
 * Returns the converted unsigned long integer value.
 */
unsigned long fossil_cstr_to_ulong(const_cstring str);

/**
 * Convert classic C string to long long integer
 * 
 * Converts the given classic C string 'str' to a long long integer.
 * Returns the converted long long integer value.
 */
long long fossil_cstr_to_llong(const_cstring str);

/**
 * Convert classic C string to unsigned long long integer
 * 
 * Converts the given classic C string 'str' to an unsigned long long integer.
 * Returns the converted unsigned long long integer value.
 */
unsigned long long fossil_cstr_to_ullong(const_cstring str);

/**
 * Convert classic C string to boolean
 * 
 * Converts the given classic C string 'str' to a boolean value.
 * Returns 1 if 'str' is "true", "yes", "on", or non-zero; otherwise returns 0.
 */
int fossil_cstr_to_bool(const_cstring str);

//
// Convert classic byte string to equilivent type
//

/**
 * Convert byte string to integer
 * 
 * Converts the given byte string 'str' to an integer.
 * Returns the converted integer value.
 */
int fossil_bstr_to_int(const_bstring str);

/**
 * Convert byte string to floating point number
 * 
 * Converts the given byte string 'str' to a double precision floating point number.
 * Returns the converted floating point number.
 */
double fossil_bstr_to_double(const_bstring str);

/**
 * Convert byte string to long integer
 * 
 * Converts the given byte string 'str' to a long integer.
 * Returns the converted long integer value.
 */
long fossil_bstr_to_long(const_bstring str);

/**
 * Convert byte string to unsigned long integer
 * 
 * Converts the given byte string 'str' to an unsigned long integer.
 * Returns the converted unsigned long integer value.
 */
unsigned long fossil_bstr_to_ulong(const_bstring str);

/**
 * Convert byte string to long long integer
 * 
 * Converts the given byte string 'str' to a long long integer.
 * Returns the converted long long integer value.
 */
long long fossil_bstr_to_llong(const_bstring str);

/**
 * Convert byte string to unsigned long long integer
 * 
 * Converts the given byte string 'str' to an unsigned long long integer.
 * Returns the converted unsigned long long integer value.
 */
unsigned long long fossil_bstr_to_ullong(const_bstring str);

/**
 * Convert byte string to boolean
 * 
 * Converts the given byte string 'str' to a boolean value.
 * Returns 1 if 'str' is "true", "yes", "on", or non-zero; otherwise returns 0.
 */
int fossil_bstr_to_bool(const_bstring str);

//
// Convert wisiwig string to equilivent type
//

/**
 * Convert wide string to integer
 * 
 * Converts the given wide string 'str' to an integer.
 * Returns the converted integer value.
 */
int fossil_wstr_to_int(const_wstring str);

/**
 * Convert wide string to floating point number
 * 
 * Converts the given wide string 'str' to a double precision floating point number.
 * Returns the converted floating point number.
 */
double fossil_wstr_to_double(const_wstring str);

/**
 * Convert wide string to long integer
 * 
 * Converts the given wide string 'str' to a long integer.
 * Returns the converted long integer value.
 */
long fossil_wstr_to_long(const_wstring str);

/**
 * Convert wide string to unsigned long integer
 * 
 * Converts the given wide string 'str' to an unsigned long integer.
 * Returns the converted unsigned long integer value.
 */
unsigned long fossil_wstr_to_ulong(const_wstring str);

/**
 * Convert wide string to long long integer
 * 
 * Converts the given wide string 'str' to a long long integer.
 * Returns the converted long long integer value.
 */
long long fossil_wstr_to_llong(const_wstring str);

/**
 * Convert wide string to unsigned long long integer
 * 
 * Converts the given wide string 'str' to an unsigned long long integer.
 * Returns the converted unsigned long long integer value.
 */
unsigned long long fossil_wstr_to_ullong(const_wstring str);

/**
 * Convert wide string to boolean
 * 
 * Converts the given wide string 'str' to a boolean value.
 * Returns 1 if 'str' is "true", "yes", "on", or non-zero; otherwise returns 0.
 */
int fossil_wstr_to_bool(const_wstring str);


#ifdef __cplusplus
}
#endif

#endif
