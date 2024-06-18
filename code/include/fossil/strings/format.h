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
#ifndef FOSSIL_STR_STRFORMAT_H
#define FOSSIL_STR_STRFORMAT_H

/**
 * @brief String Formatting Functions
 * 
 * This header file contains functions to format various types of strings such as dates, times,
 * phone numbers, currencies, percentages, postal codes, and social security numbers.
 * 
 * These functions accept input strings, format them according to predefined patterns, and return
 * the formatted strings. They support both null-terminated C strings (cstring), byte strings (bstring),
 * and wide strings (wstring).
 * 
 * Usage:
 * 
 * Example:
 * 
 * @code
 * cstring formatted_phone = fossil_cstr_format_phone("1234567890"); // Formats a phone number
 * if (formatted_phone != NULL) {
 *     printf("Formatted Phone: %s\n", formatted_phone);
 *     free(formatted_phone);
 * } else {
 *     printf("Error formatting phone number.\n");
 * }
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

/**
 * Format a string.
 * 
 * @param format The format string.
 * @param ... Additional arguments to format.
 * @return The formatted string, or NULL if an error occurred.
 */
cstring fossil_cstr_format(const_cstring format, ...);

/**
 * Format a phone number string.
 * 
 * @param phone The phone number string.
 * @return The formatted phone number string, or NULL if an error occurred.
 */
cstring fossil_cstr_format_phone(const_cstring phone);

/**
 * Format a date string.
 * 
 * @param date The date string.
 * @return The formatted date string, or NULL if an error occurred.
 */
cstring fossil_cstr_format_date(const_cstring date);

/**
 * Format a time string.
 * 
 * @param time The time string.
 * @return The formatted time string, or NULL if an error occurred.
 */
cstring fossil_cstr_format_time(const_cstring time);

/**
 * Format a currency string.
 * 
 * @param currency The currency string.
 * @return The formatted currency string, or NULL if an error occurred.
 */
cstring fossil_cstr_format_currency(const_cstring currency);

/**
 * Format a percentage string.
 * 
 * @param percentage The percentage string.
 * @return The formatted percentage string, or NULL if an error occurred.
 */
cstring fossil_cstr_format_percentage(const_cstring percentage);

/**
 * Format a postal code string.
 * 
 * @param postal_code The postal code string.
 * @return The formatted postal code string, or NULL if an error occurred.
 */
cstring fossil_cstr_format_postal_code(const_cstring postal_code);

/**
 * Format a SSN (Social Security Number) string.
 * 
 * @param ssn The SSN string.
 * @return The formatted SSN string, or NULL if an error occurred.
 */
cstring fossil_cstr_format_ssn(const_cstring ssn);

/**
 * Format a byte string.
 * 
 * @param format The format byte string.
 * @param ... Additional arguments to format.
 * @return The formatted byte string, or NULL if an error occurred.
 */
bstring fossil_bstr_format(const_bstring format, ...);

/**
 * Format a phone number byte string.
 * 
 * @param phone The phone number byte string.
 * @return The formatted phone number byte string, or NULL if an error occurred.
 */
bstring fossil_bstr_format_phone(const_bstring phone);

/**
 * Format a date byte string.
 * 
 * @param date The date byte string.
 * @return The formatted date byte string, or NULL if an error occurred.
 */
bstring fossil_bstr_format_date(const_bstring date);

/**
 * Format a time byte string.
 * 
 * @param time The time byte string.
 * @return The formatted time byte string, or NULL if an error occurred.
 */
bstring fossil_bstr_format_time(const_bstring time);

/**
 * Format a currency byte string.
 * 
 * @param currency The currency byte string.
 * @return The formatted currency byte string, or NULL if an error occurred.
 */
bstring fossil_bstr_format_currency(const_bstring currency);

/**
 * Format a percentage byte string.
 * 
 * @param percentage The percentage byte string.
 * @return The formatted percentage byte string, or NULL if an error occurred.
 */
bstring fossil_bstr_format_percentage(const_bstring percentage);

/**
 * Format a postal code byte string.
 * 
 * @param postal_code The postal code byte string.
 * @return The formatted postal code byte string, or NULL if an error occurred.
 */
bstring fossil_bstr_format_postal_code(const_bstring postal_code);

/**
 * Format a SSN (Social Security Number) byte string.
 * 
 * @param ssn The SSN byte string.
 * @return The formatted SSN byte string, or NULL if an error occurred.
 */
bstring fossil_bstr_format_ssn(const_bstring ssn);

/**
 * Format a wide string.
 * 
 * @param format The format wide string.
 * @param ... Additional arguments to format.
 * @return The formatted wide string, or NULL if an error occurred.
 */
wstring fossil_wstr_format(const_wstring format, ...);

/**
 * Format a phone number wide string.
 * 
 * @param phone The phone number wide string.
 * @return The formatted phone number wide string, or NULL if an error occurred.
 */
wstring fossil_wstr_format_phone(const_wstring phone);

/**
 * Format a date wide string.
 * 
 * @param date The date wide string.
 * @return The formatted date wide string, or NULL if an error occurred.
 */
wstring fossil_wstr_format_date(const_wstring date);

/**
 * Format a time wide string.
 * 
 * @param time The time wide string.
 * @return The formatted time wide string, or NULL if an error occurred.
 */
wstring fossil_wstr_format_time(const_wstring time);

/**
 * Format a currency wide string.
 * 
 * @param currency The currency wide string.
 * @return The formatted currency wide string, or NULL if an error occurred.
 */
wstring fossil_wstr_format_currency(const_wstring currency);

/**
 * Format a percentage wide string.
 * 
 * @param percentage The percentage wide string.
 * @return The formatted percentage wide string, or NULL if an error occurred.
 */
wstring fossil_wstr_format_percentage(const_wstring percentage);

/**
 * Format a postal code wide string.
 * 
 * @param postal_code The postal code wide string.
 * @return The formatted postal code wide string, or NULL if an error occurred.
 */
wstring fossil_wstr_format_postal_code(const_wstring postal_code);

/**
 * Format a SSN (Social Security Number) wide string.
 * 
 * @param ssn The SSN wide string.
 * @return The formatted SSN wide string, or NULL if an error occurred.
 */
wstring fossil_wstr_format_ssn(const_wstring ssn);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <stdexcept>

namespace fossil {
    class StringFormatter {
    public:
        /**
         * Format a string.
         * 
         * @param format The format string.
         * @param ... Additional arguments to format.
         * @return The formatted string, or NULL if an error occurred.
         */
        static cstring format(const_cstring format, ...) {
            try {
                return fossil_cstr_format(format);
            } catch (const std::exception& e) {
                // Handle exception here
                // Print error message or perform any necessary actions
                return cnullptr;
            }
        }

        /**
         * Format a phone number string.
         * 
         * @param phone The phone number string.
         * @return The formatted phone number string, or NULL if an error occurred.
         */
        static cstring format_phone(const_cstring phone) {
            try {
                return fossil_cstr_format_phone(phone);
            } catch (const std::exception& e) {
                // Handle exception here
                // Print error message or perform any necessary actions
                return cnullptr;
            }
        }

        /**
         * Format a date string.
         * 
         * @param date The date string.
         * @return The formatted date string, or NULL if an error occurred.
         */
        static cstring format_date(const_cstring date) {
            try {
                return fossil_cstr_format_date(date);
            } catch (const std::exception& e) {
                // Handle exception here
                // Print error message or perform any necessary actions
                return cnullptr;
            }
        }

        /**
         * Format a time string.
         * 
         * @param time The time string.
         * @return The formatted time string, or NULL if an error occurred.
         */
        static cstring format_time(const_cstring time) {
            try {
                return fossil_cstr_format_time(time);
            } catch (const std::exception& e) {
                // Handle exception here
                // Print error message or perform any necessary actions
                return cnullptr;
            }
        }

        /**
         * Format a currency string.
         * 
         * @param currency The currency string.
         * @return The formatted currency string, or NULL if an error occurred.
         */
        static cstring format_currency(const_cstring currency) {
            try {
                return fossil_cstr_format_currency(currency);
            } catch (const std::exception& e) {
                // Handle exception here
                // Print error message or perform any necessary actions
                return cnullptr;
            }
        }

        /**
         * Format a percentage string.
         * 
         * @param percentage The percentage string.
         * @return The formatted percentage string, or NULL if an error occurred.
         */
        static cstring format_percentage(const_cstring percentage) {
            try {
                return fossil_cstr_format_percentage(percentage);
            } catch (const std::exception& e) {
                // Handle exception here
                // Print error message or perform any necessary actions
                return cnullptr;
            }
        }

        /**
         * Format a postal code string.
         * 
         * @param postal_code The postal code string.
         * @return The formatted postal code string, or NULL if an error occurred.
         */
        static cstring format_postal_code(const_cstring postal_code) {
            try {
                return fossil_cstr_format_postal_code(postal_code);
            } catch (const std::exception& e) {
                // Handle exception here
                // Print error message or perform any necessary actions
                return cnullptr;
            }
        }

        /**
         * Format a SSN (Social Security Number) string.
         * 
         * @param ssn The SSN string.
         * @return The formatted SSN string, or NULL if an error occurred.
         */
        static cstring format_ssn(const_cstring ssn) {
            try {
                return fossil_cstr_format_ssn(ssn);
            } catch (const std::exception& e) {
                // Handle exception here
                // Print error message or perform any necessary actions
                return cnullptr;
            }
        }

        /**
         * Format a byte string.
         * 
         * @param format The format byte string.
         * @param ... Additional arguments to format.
         * @return The formatted byte string, or NULL if an error occurred.
         */
        static bstring format(const_bstring format, ...) {
            try {
                return fossil_bstr_format(format);
            } catch (const std::exception& e) {
                // Handle exception here
                // Print error message or perform any necessary actions
                return cnullptr;
            }
        }

        /**
         * Format a phone number byte string.
         * 
         * @param phone The phone number byte string.
         * @return The formatted phone number byte string, or NULL if an error occurred.
         */
        static bstring format_phone(const_bstring phone) {
            try {
                return fossil_bstr_format_phone(phone);
            } catch (const std::exception& e) {
                // Handle exception here
                // Print error message or perform any necessary actions
                return cnullptr;
            }
        }

        /**
         * Format a date byte string.
         * 
         * @param date The date byte string.
         * @return The formatted date byte string, or NULL if an error occurred.
         */
        static bstring format_date(const_bstring date) {
            try {
                return fossil_bstr_format_date(date);
            } catch (const std::exception& e) {
                // Handle exception here
                // Print error message or perform any necessary actions
                return cnullptr;
            }
        }

        /**
         * Format a time byte string.
         * 
         * @param time The time byte string.
         * @return The formatted time byte string, or NULL if an error occurred.
         */
        static bstring format_time(const_bstring time) {
            try {
                return fossil_bstr_format_time(time);
            } catch (const std::exception& e) {
                // Handle exception here
                // Print error message or perform any necessary actions
                return cnullptr;
            }
        }

        /**
         * Format a currency byte string.
         * 
         * @param currency The currency byte string.
         * @return The formatted currency byte string, or NULL if an error occurred.
         */
        static bstring format_currency(const_bstring currency) {
            try {
                return fossil_bstr_format_currency(currency);
            } catch (const std::exception& e) {
                // Handle exception here
                // Print error message or perform any necessary actions
                return cnullptr;
            }
        }

        /**
         * Format a percentage byte string.
         * 
         * @param percentage The percentage byte string.
         * @return The formatted percentage byte string, or NULL if an error occurred.
         */
        static bstring format_percentage(const_bstring percentage) {
            try {
                return fossil_bstr_format_percentage(percentage);
            } catch (const std::exception& e) {
                // Handle exception here
                // Print error message or perform any necessary actions
                return cnullptr;
            }
        }

        /**
         * Format a postal code byte string.
         * 
         * @param postal_code The postal code byte string.
         * @return The formatted postal code byte string, or NULL if an error occurred.
         */
        static bstring format_postal_code(const_bstring postal_code) {
            try {
                return fossil_bstr_format_postal_code(postal_code);
            } catch (const std::exception& e) {
                // Handle exception here
                // Print error message or perform any necessary actions
                return cnullptr;
            }
        }

        /**
         * Format a SSN (Social Security Number) byte string.
         * 
         * @param ssn The SSN byte string.
         * @return The formatted SSN byte string, or NULL if an error occurred.
         */
        static bstring format_ssn(const_bstring ssn) {
            try {
                return fossil_bstr_format_ssn(ssn);
            } catch (const std::exception& e) {
                // Handle exception here
                // Print error message or perform any necessary actions
                return cnullptr;
            }
        }
    };
} // namespace fossil

#endif

#endif
