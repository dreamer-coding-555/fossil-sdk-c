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
#ifndef FOSSIL_STR_STRFROM_H
#define FOSSIL_STR_STRFROM_H

/**
 * @brief String Formatting Functions
 * 
 * This header file contains functions for formatting numeric values into strings.
 * 
 * The functions support conversion between classic C strings, byte strings, and wide strings.
 * 
 * Usage:
 * 
 * Example:
 * 
 * @code
 * int number = 123;
 * cstring str = fossil_cstr_from_int(number);
 * printf("Formatted string: %s\n", str);
 * free(str); // Remember to free the allocated memory
 * @endcode
 */

#include "bstring.h"
#include "cstring.h"
#include "wstring.h"

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// Available functions
// =================================================================

//
// classic C string formatting functions
//

/**
 * Convert integer to classic C string.
 * 
 * @param num The integer to convert to a classic C string.
 * @return A dynamically allocated classic C string representing the integer, or cnullptr on failure.
 */
cstring fossil_cstr_from_int(int num);

/**
 * Convert long to classic C string.
 * 
 * @param num The long integer to convert to a classic C string.
 * @return A dynamically allocated classic C string representing the long integer, or cnullptr on failure.
 */
cstring fossil_cstr_from_long(long num);

/**
 * Convert long long to classic C string.
 * 
 * @param num The long long integer to convert to a classic C string.
 * @return A dynamically allocated classic C string representing the long long integer, or cnullptr on failure.
 */
cstring fossil_cstr_from_llong(long long num);

/**
 * Convert unsigned long to classic C string.
 * 
 * @param num The unsigned long integer to convert to a classic C string.
 * @return A dynamically allocated classic C string representing the unsigned long integer, or cnullptr on failure.
 */
cstring fossil_cstr_from_ulong(unsigned long num);

/**
 * Convert unsigned long long to classic C string.
 * 
 * @param num The unsigned long long integer to convert to a classic C string.
 * @return A dynamically allocated classic C string representing the unsigned long long integer, or cnullptr on failure.
 */
cstring fossil_cstr_from_ullong(unsigned long long num);

/**
 * Convert a double to a C string.
 * 
 * @param num The double number to be converted.
 * @return A dynamically allocated C string representing the double value.
 *         The caller is responsible for freeing the allocated memory.
 */
cstring fossil_cstr_from_double(double num);

//
// byte string formatting functions
//

/**
 * Convert integer to byte string.
 * 
 * @param num The integer to convert to a byte string.
 * @return A dynamically allocated byte string representing the integer, or bnullptr on failure.
 */
bstring fossil_bstr_from_int(int num);

/**
 * Convert long to byte string.
 * 
 * @param num The long integer to convert to a byte string.
 * @return A dynamically allocated byte string representing the long integer, or bnullptr on failure.
 */
bstring fossil_bstr_from_long(long num);

/**
 * Convert long long to byte string.
 * 
 * @param num The long long integer to convert to a byte string.
 * @return A dynamically allocated byte string representing the long long integer, or bnullptr on failure.
 */
bstring fossil_bstr_from_llong(long long num);

/**
 * Convert unsigned long to byte string.
 * 
 * @param num The unsigned long integer to convert to a byte string.
 * @return A dynamically allocated byte string representing the unsigned long integer, or bnullptr on failure.
 */
bstring fossil_bstr_from_ulong(unsigned long num);

/**
 * Convert unsigned long long to byte string.
 * 
 * @param num The unsigned long long integer to convert to a byte string.
 * @return A dynamically allocated byte string representing the unsigned long long integer, or bnullptr on failure.
 */
bstring fossil_bstr_from_ullong(unsigned long long num);

/**
 * Convert a double to a bstring.
 * 
 * @param num The double number to be converted.
 * @return A dynamically allocated bstring representing the double value.
 *         The caller is responsible for freeing the allocated memory.
 */
bstring fossil_bstr_from_double(double num);

//
// Wide string formatting functions
//

/**
 * Convert integer to wide string.
 * 
 * @param num The integer to convert to a wide string.
 * @return A dynamically allocated wide string representing the integer, or cnullptr on failure.
 */
wstring fossil_wstr_from_int(int num);

/**
 * Convert long to wide string.
 * 
 * @param num The long integer to convert to a wide string.
 * @return A dynamically allocated wide string representing the long integer, or cnullptr on failure.
 */
wstring fossil_wstr_from_long(long num);

/**
 * Convert long long to wide string.
 * 
 * @param num The long long integer to convert to a wide string.
 * @return A dynamically allocated wide string representing the long long integer, or cnullptr on failure.
 */
wstring fossil_wstr_from_llong(long long num);

/**
 * Convert unsigned long to wide string.
 * 
 * @param num The unsigned long integer to convert to a wide string.
 * @return A dynamically allocated wide string representing the unsigned long integer, or cnullptr on failure.
 */
wstring fossil_wstr_from_ulong(unsigned long num);

/**
 * Convert unsigned long long to wide string.
 * 
 * @param num The unsigned long long integer to convert to a wide string.
 * @return A dynamically allocated wide string representing the unsigned long long integer, or cnullptr on failure.
 */
wstring fossil_wstr_from_ullong(unsigned long long num);

/**
 * Convert a double to a wide string.
 * 
 * @param num The double number to be converted.
 * @return A dynamically allocated wide string representing the double value.
 *         The caller is responsible for freeing the allocated memory.
 */
wstring fossil_wstr_from_double(double num);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

namespace fossil {

class StringFromConverter {
public:
    static std::string cstr_from_int(int num) {
        cstring str = fossil_cstr_from_int(num);
        std::string result(str);
        free(str);
        return result;
    }

    static std::string cstr_from_long(long num) {
        cstring str = fossil_cstr_from_long(num);
        std::string result(str);
        free(str);
        return result;
    }

    static std::string cstr_from_llong(long long num) {
        cstring str = fossil_cstr_from_llong(num);
        std::string result(str);
        free(str);
        return result;
    }

    static std::string cstr_from_ulong(unsigned long num) {
        cstring str = fossil_cstr_from_ulong(num);
        std::string result(str);
        free(str);
        return result;
    }

    static std::string cstr_from_ullong(unsigned long long num) {
        cstring str = fossil_cstr_from_ullong(num);
        std::string result(str);
        free(str);
        return result;
    }

    static std::string cstr_from_double(double num) {
        cstring str = fossil_cstr_from_double(num);
        std::string result(str);
        free(str);
        return result;
    }

    static std::string bstr_from_int(int num) {
        bstring str = fossil_bstr_from_int(num);
        std::string result(str);
        free(str);
        return result;
    }

    static std::string bstr_from_long(long num) {
        bstring str = fossil_bstr_from_long(num);
        std::string result(str);
        free(str);
        return result;
    }

    static std::string bstr_from_llong(long long num) {
        bstring str = fossil_bstr_from_llong(num);
        std::string result(str);
        free(str);
        return result;
    }

    static std::string bstr_from_ulong(unsigned long num) {
        bstring str = fossil_bstr_from_ulong(num);
        std::string result(str);
        free(str);
        return result;
    }

    static std::string bstr_from_ullong(unsigned long long num) {
        bstring str = fossil_bstr_from_ullong(num);
        std::string result(str);
        free(str);
        return result;
    }

    static std::string bstr_from_double(double num) {
        bstring str = fossil_bstr_from_double(num);
        std::string result(str);
        free(str);
        return result;
    }

    static std::wstring wstr_from_int(int num) {
        wstring str = fossil_wstr_from_int(num);
        std::wstring result(str);
        free(str);
        return result;
    }

    static std::wstring wstr_from_long(long num) {
        wstring str = fossil_wstr_from_long(num);
        std::wstring result(str);
        free(str);
        return result;
    }

    static std::wstring wstr_from_llong(long long num) {
        wstring str = fossil_wstr_from_llong(num);
        std::wstring result(str);
        free(str);
        return result;
    }

    static std::wstring wstr_from_ulong(unsigned long num) {
        wstring str = fossil_wstr_from_ulong(num);
        std::wstring result(str);
        free(str);
        return result;
    }

    static std::wstring wstr_from_ullong(unsigned long long num) {
        wstring str = fossil_wstr_from_ullong(num);
        std::wstring result(str);
        free(str);
        return result;
    }

    static std::wstring wstr_from_double(double num) {
        wstring str = fossil_wstr_from_double(num);
        std::wstring result(str);
        free(str);
        return result;
    }
};

} // namespace fossil

#endif

#endif
