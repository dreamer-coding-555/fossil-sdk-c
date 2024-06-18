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
#ifndef FOSSIL_STR_LETTER_H
#define FOSSIL_STR_LETTER_H

/**
 * @brief Letter Utility Functions for Different Character Types
 * 
 * This header file defines a set of utility functions for working with characters
 * in null-terminated C strings, byte strings, and wide C strings. The functions
 * provide character classification, conversion, and retrieval capabilities.
 * 
 * Supported Character Types:
 * - `cletter`: Standard C characters.
 * - `bletter`: Byte characters.
 * - `wletter`: Wide characters.
 * 
 * Key Features:
 * - Retrieve characters at specified indices.
 * - Check character types (alphabetic, digit, alphanumeric, etc.).
 * - Convert characters between uppercase and lowercase.
 * 
 * Usage:
 * 
 * Example for `cletter`:
 * 
 * @code
 * const_cletter *str = "example";
 * cletter ch = fossil_cletter_at(str, 2);  // Returns 'a'
 * int16_t is_alpha = fossil_cletter_is_alpha(ch);  // Returns non-zero value
 * cletter lower = fossil_cletter_to_lower('A');  // Returns 'a'
 * @endcode
 * 
 * Example for `bletter`:
 * 
 * @code
 * const_bletter *str = (const_bletter *)"example";
 * bletter byte = fossil_bletter_at(str, 2);  // Returns 'a'
 * int16_t is_digit = fossil_bletter_is_digit('5');  // Returns non-zero value
 * bletter upper = fossil_bletter_to_upper('a');  // Returns 'A'
 * @endcode
 * 
 * Example for `wletter`:
 * 
 * @code
 * const_wletter *str = L"example";
 * wletter wchar = fossil_wletter_at(str, 2);  // Returns L'a'
 * int16_t is_alnum = fossil_wletter_is_alnum(L'1');  // Returns non-zero value
 * wletter lower = fossil_wletter_to_lower(L'A');  // Returns L'a'
 * @endcode
 */

#include "fossil/common/common.h"
#include <stddef.h>
#include <wchar.h>
#include <wctype.h>

// ASCII Color Codes
#define FOSSIL_STR_COLOR_BLACK     "\033[0;30m"
#define FOSSIL_STR_COLOR_RED       "\033[0;31m"
#define FOSSIL_STR_COLOR_GREEN     "\033[0;32m"
#define FOSSIL_STR_COLOR_YELLOW    "\033[0;33m"
#define FOSSIL_STR_COLOR_BLUE      "\033[0;34m"
#define FOSSIL_STR_COLOR_MAGENTA   "\033[0;35m"
#define FOSSIL_STR_COLOR_CYAN      "\033[0;36m"
#define FOSSIL_STR_COLOR_WHITE     "\033[0;37m"

// Text Formatting Attributes
#define FOSSIL_STR_ATTR_RESET       "\033[0m"
#define FOSSIL_STR_ATTR_BOLD        "\033[1m"
#define FOSSIL_STR_ATTR_DIM         "\033[2m"
#define FOSSIL_STR_ATTR_UNDERLINE   "\033[4m"
#define FOSSIL_STR_ATTR_BLINK       "\033[5m"
#define FOSSIL_STR_ATTR_REVERSE     "\033[7m"
#define FOSSIL_STR_ATTR_HIDDEN      "\033[8m"

// charecter types for the string types
typedef wchar_t wletter;             // wiswig character
typedef char cletter;                // classic C style character
typedef uint8_t bletter;             // byte letter character
typedef const wchar_t const_wletter; // const wiswig character
typedef const char const_cletter;    // const classic C style character
typedef const uint8_t const_bletter; // const byte letter character

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// Available functions
// =================================================================

/**
 * cletter functions
 */

/**
 * @brief Return the character at the specified index in a null-terminated C string.
 *
 * @param str   The input null-terminated C string.
 * @param index The index of the character to retrieve.
 * @return      The character at the specified index, or '\0' if the index is out of bounds or the string is NULL.
 */
cletter fossil_cletter_at(const_cletter *str, size_t index);

/**
 * Check if the character is an alphabetic character.
 * 
 * Returns a non-zero value if 'ch' is an alphabetic character, otherwise 0.
 */
int16_t fossil_cletter_is_alpha(cletter ch);

/**
 * Check if the character is a digit.
 * 
 * Returns a non-zero value if 'ch' is a digit, otherwise 0.
 */
int16_t fossil_cletter_is_digit(cletter ch);

/**
 * Check if the character is an alphanumeric character.
 * 
 * Returns a non-zero value if 'ch' is an alphanumeric character, otherwise 0.
 */
int16_t fossil_cletter_is_alnum(cletter ch);

/**
 * Check if the character is a lowercase letter.
 * 
 * Returns a non-zero value if 'ch' is a lowercase letter, otherwise 0.
 */
int16_t fossil_cletter_is_lower(cletter ch);

/**
 * Check if the character is an uppercase letter.
 * 
 * Returns a non-zero value if 'ch' is an uppercase letter, otherwise 0.
 */
int16_t fossil_cletter_is_upper(cletter ch);

/**
 * Convert the character to lowercase.
 * 
 * Returns the lowercase version of 'ch' if 'ch' is an uppercase letter, otherwise 'ch'.
 */
cletter fossil_cletter_to_lower(cletter ch);

/**
 * Convert the character to uppercase.
 * 
 * Returns the uppercase version of 'ch' if 'ch' is a lowercase letter, otherwise 'ch'.
 */
cletter fossil_cletter_to_upper(cletter ch);

/**
 * Check if the character is a whitespace character.
 * 
 * Returns a non-zero value if 'ch' is a whitespace character, otherwise 0.
 */
int16_t fossil_cletter_is_space(cletter ch);

/**
 * Check if the character is a punctuation character.
 * 
 * Returns a non-zero value if 'ch' is a punctuation character, otherwise 0.
 */
int16_t fossil_cletter_is_punct(cletter ch);

/**
 * Check if the character is a printable character excluding space.
 * 
 * Returns a non-zero value if 'ch' is a printable character excluding space, otherwise 0.
 */
int16_t fossil_cletter_is_graph(cletter ch);

/**
 * Check if the character is a printable character including space.
 * 
 * Returns a non-zero value if 'ch' is a printable character including space, otherwise 0.
 */
int16_t fossil_cletter_is_print(cletter ch);

/**
 * Check if the character is a control character.
 * 
 * Returns a non-zero value if 'ch' is a control character, otherwise 0.
 */
int16_t fossil_cletter_is_cntrl(cletter ch);

/**
 * Check if the character is a hexadecimal digit.
 * 
 * Returns a non-zero value if 'ch' is a hexadecimal digit, otherwise 0.
 */
int16_t fossil_cletter_is_xdigit(cletter ch);


/**
 * bletter functions
 */

/**
 * @brief Return the byte at the specified index in a byte string.
 *
 * @param str   The input byte string.
 * @param index The index of the byte to retrieve.
 * @return      The byte at the specified index, or '\0' if the index is out of bounds or the string is NULL.
 */
bletter fossil_bletter_at(const_bletter *str, size_t index);


/**
 * Check if the character is an alphabetic character.
 * 
 * Returns a non-zero value if 'ch' is an alphabetic character, otherwise 0.
 */
int16_t fossil_bletter_is_alpha(bletter ch);

/**
 * Check if the character is a digit.
 * 
 * Returns a non-zero value if 'ch' is a digit, otherwise 0.
 */
int16_t fossil_bletter_is_digit(bletter ch);

/**
 * Check if the character is an alphanumeric character.
 * 
 * Returns a non-zero value if 'ch' is an alphanumeric character, otherwise 0.
 */
int16_t fossil_bletter_is_alnum(bletter ch);

/**
 * Check if the character is a lowercase letter.
 * 
 * Returns a non-zero value if 'ch' is a lowercase letter, otherwise 0.
 */
int16_t fossil_bletter_is_lower(bletter ch);

/**
 * Check if the character is an uppercase letter.
 * 
 * Returns a non-zero value if 'ch' is an uppercase letter, otherwise 0.
 */
int16_t fossil_bletter_is_upper(bletter ch);

/**
 * Convert the character to lowercase.
 * 
 * Returns the lowercase version of 'ch' if 'ch' is an uppercase letter, otherwise 'ch'.
 */
bletter fossil_bletter_to_lower(bletter ch);

/**
 * Convert the character to uppercase.
 * 
 * Returns the uppercase version of 'ch' if 'ch' is a lowercase letter, otherwise 'ch'.
 */
bletter fossil_bletter_to_upper(bletter ch);

/**
 * Check if the character is a whitespace character.
 * 
 * Returns a non-zero value if 'ch' is a whitespace character, otherwise 0.
 */
int16_t fossil_bletter_is_space(bletter ch);

/**
 * Check if the character is a punctuation character.
 * 
 * Returns a non-zero value if 'ch' is a punctuation character, otherwise 0.
 */
int16_t fossil_bletter_is_punct(bletter ch);

/**
 * Check if the character is a printable character excluding space.
 * 
 * Returns a non-zero value if 'ch' is a printable character excluding space, otherwise 0.
 */
int16_t fossil_bletter_is_graph(bletter ch);

/**
 * Check if the character is a printable character including space.
 * 
 * Returns a non-zero value if 'ch' is a printable character including space, otherwise 0.
 */
int16_t fossil_bletter_is_print(bletter ch);

/**
 * Check if the character is a control character.
 * 
 * Returns a non-zero value if 'ch' is a control character, otherwise 0.
 */
int16_t fossil_bletter_is_cntrl(bletter ch);

/**
 * Check if the character is a hexadecimal digit.
 * 
 * Returns a non-zero value if 'ch' is a hexadecimal digit, otherwise 0.
 */
int16_t fossil_bletter_is_xdigit(bletter ch);

/**
 * wletter functions
 */

/**
 * @brief Return the wide character at the specified index in a null-terminated wide C string.
 *
 * @param str   The input null-terminated wide C string.
 * @param index The index of the wide character to retrieve.
 * @return      The wide character at the specified index, or L'\0' if the index is out of bounds or the string is NULL.
 */
wletter fossil_wletter_at(const_wletter *str, size_t index);

/**
 * Check if the wletter is an alphabetic character.
 * 
 * Returns a non-zero value if 'ch' is an alphabetic character, otherwise 0.
 */
int16_t fossil_wletter_is_alpha(wletter ch);

/**
 * Check if the wletter is a digit.
 * 
 * Returns a non-zero value if 'ch' is a digit, otherwise 0.
 */
int16_t fossil_wletter_is_digit(wletter ch);

/**
 * Check if the wletter is an alphanumeric character.
 * 
 * Returns a non-zero value if 'ch' is an alphanumeric character, otherwise 0.
 */
int16_t fossil_wletter_is_alnum(wletter ch);

/**
 * Check if the wletter is a lowercase letter.
 * 
 * Returns a non-zero value if 'ch' is a lowercase letter, otherwise 0.
 */
int16_t fossil_wletter_is_lower(wletter ch);

/**
 * Check if the wletter is an uppercase letter.
 * 
 * Returns a non-zero value if 'ch' is an uppercase letter, otherwise 0.
 */
int16_t fossil_wletter_is_upper(wletter ch);

/**
 * Convert the wletter to lowercase.
 * 
 * Returns the lowercase version of 'ch' if 'ch' is an uppercase letter, otherwise 'ch'.
 */
wletter fossil_wletter_to_lower(wletter ch);

/**
 * Convert the wletter to uppercase.
 * 
 * Returns the uppercase version of 'ch' if 'ch' is a lowercase letter, otherwise 'ch'.
 */
wletter fossil_wletter_to_upper(wletter ch);

/**
 * Check if the wletter is a whitespace character.
 * 
 * Returns a non-zero value if 'ch' is a whitespace character, otherwise 0.
 */
int16_t fossil_wletter_is_space(wletter ch);

/**
 * Check if the wletter is a punctuation character.
 * 
 * Returns a non-zero value if 'ch' is a punctuation character, otherwise 0.
 */
int16_t fossil_wletter_is_punct(wletter ch);

/**
 * Check if the wletter is a printable character excluding space.
 * 
 * Returns a non-zero value if 'ch' is a printable character excluding space, otherwise 0.
 */
int16_t fossil_wletter_is_graph(wletter ch);

/**
 * Check if the wletter is a printable character including space.
 * 
 * Returns a non-zero value if 'ch' is a printable character including space, otherwise 0.
 */
int16_t fossil_wletter_is_print(wletter ch);

/**
 * Check if the wletter is a control character.
 * 
 * Returns a non-zero value if 'ch' is a control character, otherwise 0.
 */
int16_t fossil_wletter_is_cntrl(wletter ch);

/**
 * Check if the wletter is a hexadecimal digit.
 * 
 * Returns a non-zero value if 'ch' is a hexadecimal digit, otherwise 0.
 */
int16_t fossil_wletter_is_xdigit(wletter ch);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace fossil {
    
    class CLetter {
    public:
        static cletter at(const_cletter* str, size_t index) {
            return fossil_cletter_at(str, index);
        }

        static int16_t is_alpha(cletter ch) {
            return fossil_cletter_is_alpha(ch);
        }

        static int16_t is_digit(cletter ch) {
            return fossil_cletter_is_digit(ch);
        }

        static int16_t is_alnum(cletter ch) {
            return fossil_cletter_is_alnum(ch);
        }

        static int16_t is_lower(cletter ch) {
            return fossil_cletter_is_lower(ch);
        }

        static int16_t is_upper(cletter ch) {
            return fossil_cletter_is_upper(ch);
        }

        static cletter to_lower(cletter ch) {
            return fossil_cletter_to_lower(ch);
        }

        static cletter to_upper(cletter ch) {
            return fossil_cletter_to_upper(ch);
        }

        static int16_t is_space(cletter ch) {
            return fossil_cletter_is_space(ch);
        }

        static int16_t is_punct(cletter ch) {
            return fossil_cletter_is_punct(ch);
        }

        static int16_t is_graph(cletter ch) {
            return fossil_cletter_is_graph(ch);
        }

        static int16_t is_print(cletter ch) {
            return fossil_cletter_is_print(ch);
        }

        static int16_t is_cntrl(cletter ch) {
            return fossil_cletter_is_cntrl(ch);
        }

        static int16_t is_xdigit(cletter ch) {
            return fossil_cletter_is_xdigit(ch);
        }
    };

    class BLetter {
    public:
        static bletter at(const_bletter* str, size_t index) {
            return fossil_bletter_at(str, index);
        }

        static int16_t is_alpha(bletter ch) {
            return fossil_bletter_is_alpha(ch);
        }

        static int16_t is_digit(bletter ch) {
            return fossil_bletter_is_digit(ch);
        }

        static int16_t is_alnum(bletter ch) {
            return fossil_bletter_is_alnum(ch);
        }

        static int16_t is_lower(bletter ch) {
            return fossil_bletter_is_lower(ch);
        }

        static int16_t is_upper(bletter ch) {
            return fossil_bletter_is_upper(ch);
        }

        static bletter to_lower(bletter ch) {
            return fossil_bletter_to_lower(ch);
        }

        static bletter to_upper(bletter ch) {
            return fossil_bletter_to_upper(ch);
        }

        static int16_t is_space(bletter ch) {
            return fossil_bletter_is_space(ch);
        }

        static int16_t is_punct(bletter ch) {
            return fossil_bletter_is_punct(ch);
        }

        static int16_t is_graph(bletter ch) {
            return fossil_bletter_is_graph(ch);
        }

        static int16_t is_print(bletter ch) {
            return fossil_bletter_is_print(ch);
        }

        static int16_t is_cntrl(bletter ch) {
            return fossil_bletter_is_cntrl(ch);
        }

        static int16_t is_xdigit(bletter ch) {
            return fossil_bletter_is_xdigit(ch);
        }
    };

    class WLetter {
    public:
        static wletter at(const_wletter* str, size_t index) {
            return fossil_wletter_at(str, index);
        }

        static int16_t is_alpha(wletter ch) {
            return fossil_wletter_is_alpha(ch);
        }

        static int16_t is_digit(wletter ch) {
            return fossil_wletter_is_digit(ch);
        }

        static int16_t is_alnum(wletter ch) {
            return fossil_wletter_is_alnum(ch);
        }

        static int16_t is_lower(wletter ch) {
            return fossil_wletter_is_lower(ch);
        }

        static int16_t is_upper(wletter ch) {
            return fossil_wletter_is_upper(ch);
        }

        static wletter to_lower(wletter ch) {
            return fossil_wletter_to_lower(ch);
        }

        static wletter to_upper(wletter ch) {
            return fossil_wletter_to_upper(ch);
        }

        static int16_t is_space(wletter ch) {
            return fossil_wletter_is_space(ch);
        }

        static int16_t is_punct(wletter ch) {
            return fossil_wletter_is_punct(ch);
        }

        static int16_t is_graph(wletter ch) {
            return fossil_wletter_is_graph(ch);
        }

        static int16_t is_print(wletter ch) {
            return fossil_wletter_is_print(ch);
        }

        static int16_t is_cntrl(wletter ch) {
            return fossil_wletter_is_cntrl(ch);
        }

        static int16_t is_xdigit(wletter ch) {
            return fossil_wletter_is_xdigit(ch);
        }
    };

}
#endif

#endif
