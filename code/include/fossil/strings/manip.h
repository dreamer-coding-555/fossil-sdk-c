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
#ifndef FOSSIL_STR_STRMANIP_H
#define FOSSIL_STR_STRMANIP_H

/**
 * @brief C String Library Functions
 * 
 * This header file contains functions for manipulating classic C strings, byte strings, and wide strings.
 * 
 * The C string library functions include comparison, copying, concatenation, searching, reversing, splitting,
 * duplication, substring extraction, and memory deallocation.
 * 
 * Byte string library functions provide similar functionalities for byte strings.
 * 
 * Wide string library functions perform the same operations on wide strings.
 * 
 * Usage:
 * 
 * Example:
 * 
 * @code
 * const_cstring str1 = "Hello";
 * const_cstring str2 = "World";
 * int result = fossil_cstr_compare(str1, str2);
 * if (result == 0) {
 *     printf("Strings are equal.\n");
 * } else if (result < 0) {
 *     printf("String 1 is less than String 2.\n");
 * } else {
 *     printf("String 1 is greater than String 2.\n");
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
// String and Strings Management Functions
// =================================================================

/**
 * C string library functions
 */

/**
 * Compare two classic C strings.
 * 
 * Compares the classic C strings 'str1' and 'str2'.
 * Returns 0 if they are equal, a negative value if 'str1' is less than 'str2', and a positive value if 'str1' is greater than 'str2'.
 */
int fossil_cstr_compare(const_cstring str1, const_cstring str2);

/**
 * Copy a classic C string.
 * 
 * Copies the classic C string 'src' to 'dest'.
 * Returns the destination string 'dest'.
 */
cstring fossil_cstr_copy(cstring dest, const_cstring src);

/**
 * Concatenate two classic C strings.
 * 
 * Concatenates the classic C string 'src' to 'dest'.
 * Returns the concatenated string 'dest'.
 */
cstring fossil_cstr_concat(cstring dest, const_cstring src);

/**
 * Find a character in a classic C string.
 * 
 * Finds the first occurrence of 'ch' in 'str'.
 * Returns a pointer to the found character or NULL if not found.
 */
const_cstring fossil_cstr_find(const_cstring str, cletter ch);

/**
 * Reverse a classic C string.
 * 
 * Reverses the classic C string 'str'.
 * Returns the reversed string.
 */
const_cstring fossil_cstr_reverse(const_cstring str);

/**
 * Split a classic C string by delimiter.
 * 
 * Splits the classic C string 'str' by the delimiter 'delimiter'.
 * Returns an array of strings containing the split substrings.
 */
cstrings fossil_cstr_split(const_cstring str, cletter delimiter);

/**
 * Duplicate a classic C string.
 * 
 * Duplicates the classic C string 'str'.
 * Returns a newly allocated string containing a copy of 'str'.
 */
cstring fossil_cstr_strdup(const_cstring str);

/**
 * Extracts a substring from a null-terminated C string.
 * 
 * @param str   The null-terminated C string from which to extract the substring.
 * @param start The starting index of the substring.
 * @param len   The length of the substring to extract.
 * 
 * @return      A dynamically allocated null-terminated C string containing the extracted substring,
 *              or NULL if memory allocation fails or invalid parameters are provided.
 */
cstring fossil_cstr_substr(const_cstring str, size_t start, size_t len);

/**
 * Frees the memory allocated for an array of C strings and the strings it contains.
 * 
 * @param splits An array of C strings to be freed.
 * 
 * @note        After calling this function, the C strings in the array `splits` will be
 *              deallocated and the array itself will be set to NULL.
 */
void fossil_cstr_erase_splits(cstrings splits);

/**
 * Byte string library functions
 */

/**
 * Compare two byte strings.
 * 
 * Compares the byte strings 'str1' and 'str2'.
 * Returns 0 if they are equal, a negative value if 'str1' is less than 'str2', and a positive value if 'str1' is greater than 'str2'.
 */
int fossil_bstr_compare(const_bstring str1, const_bstring str2);

/**
 * Copy a byte string.
 * 
 * Copies the byte string 'src' to 'dest'.
 * Returns the destination string 'dest'.
 */
bstring fossil_bstr_copy(bstring dest, const_bstring src);

/**
 * Concatenate two byte strings.
 * 
 * Concatenates the byte string 'src' to 'dest'.
 * Returns the concatenated string 'dest'.
 */
bstring fossil_bstr_concat(bstring dest, const_bstring src);

/**
 * Find a character in a byte string.
 * 
 * Finds the first occurrence of 'ch' in 'str'.
 * Returns a pointer to the found character or NULL if not found.
 */
const_bstring fossil_bstr_find(const_bstring str, bletter ch);

/**
 * Reverse a byte string.
 * 
 * Reverses the byte string 'str'.
 * Returns the reversed string.
 */
const_bstring fossil_bstr_reverse(const_bstring str);

/**
 * Split a byte string by delimiter.
 * 
 * Splits the byte string 'str' by the delimiter 'delimiter'.
 * Returns an array of strings containing the split substrings.
 */
bstrings fossil_bstr_split(const_bstring str, bletter delimiter);

/**
 * Duplicate a byte string.
 * 
 * Duplicates the byte string 'str'.
 * Returns a newly allocated string containing a copy of 'str'.
 */
bstring fossil_bstr_strdup(const_bstring str);

/**
 * Extracts a substring from a byte string.
 * 
 * @param str   The byte string from which to extract the substring.
 * @param start The starting index of the substring.
 * @param len   The length of the substring to extract.
 * 
 * @return      A dynamically allocated byte string containing the extracted substring,
 *              or NULL if memory allocation fails or invalid parameters are provided.
 */
bstring fossil_bstr_substr(const_bstring str, size_t start, size_t len);

/**
 * Frees the memory allocated for an array of byte strings and the strings it contains.
 * 
 * @param splits An array of byte strings to be freed.
 * 
 * @note        After calling this function, the byte strings in the array `splits` will be
 *              deallocated and the array itself will be set to NULL.
 */
void fossil_bstr_erase_splits(bstrings splits);

/**
 * wysiwyg string library functions
 */

/**
 * Compare two classic C strings.
 * 
 * Compares the classic C strings 'str1' and 'str2'.
 * Returns 0 if they are equal, a negative value if 'str1' is less than 'str2', and a positive value if 'str1' is greater than 'str2'.
 */
int fossil_wstr_compare(const_wstring str1, const_wstring str2);

/**
 * Copy a classic C string.
 * 
 * Copies the classic C string 'src' to 'dest'.
 * Returns the destination string 'dest'.
 */
wstring fossil_wstr_copy(wstring dest, const_wstring src);

/**
 * Concatenate two classic C strings.
 * 
 * Concatenates the classic C string 'src' to 'dest'.
 * Returns the concatenated string 'dest'.
 */
wstring fossil_wstr_concat(wstring dest, const_wstring src);

/**
 * Find a character in a classic C string.
 * 
 * Finds the first occurrence of 'ch' in 'str'.
 * Returns a pointer to the found character or NULL if not found.
 */
const_wstring fossil_wstr_find(const_wstring str, wletter ch);

/**
 * Reverse a classic C string.
 * 
 * Reverses the classic C string 'str'.
 * Returns the reversed string.
 */
const_wstring fossil_wstr_reverse(const_wstring str);

/**
 * Split a classic C string by delimiter.
 * 
 * Splits the classic C string 'str' by the delimiter 'delimiter'.
 * Returns an array of strings containing the split substrings.
 */
wstrings fossil_wstr_split(const_wstring str, wletter delimiter);

/**
 * Duplicate a classic C string.
 * 
 * Duplicates the classic C string 'str'.
 * Returns a newly allocated string containing a copy of 'str'.
 */
wstring fossil_wstr_strdup(const_wstring str);

/**
 * Extracts a substring from a null-terminated C string.
 * 
 * @param str   The null-terminated C string from which to extract the substring.
 * @param start The starting index of the substring.
 * @param len   The length of the substring to extract.
 * 
 * @return      A dynamically allocated null-terminated C string containing the extracted substring,
 *              or NULL if memory allocation fails or invalid parameters are provided.
 */
wstring fossil_wstr_substr(const_wstring str, size_t start, size_t len);

/**
 * Frees the memory allocated for an array of C strings and the strings it contains.
 * 
 * @param splits An array of C strings to be freed.
 * 
 * @note        After calling this function, the C strings in the array `splits` will be
 *              deallocated and the array itself will be set to NULL.
 */
void fossil_wstr_erase_splits(wstrings splits);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace fossil
{
    class StringManip {
    public:
        /**
         * Compare two classic C strings.
         * 
         * @param str1 The first classic C string to compare.
         * @param str2 The second classic C string to compare.
         * @return int 0 if the strings are equal, a negative value if the first string is less than the second string, and a positive value if the first string is greater than the second string.
         */
        static int compare(const_cstring str1, const_cstring str2) {
            return fossil_cstr_compare(str1, str2);
        }

        /**
         * Copy a classic C string.
         * 
         * @param dest The destination string to copy to.
         * @param src  The source string to copy from.
         * @return cstring The destination string.
         */
        static cstring copy(cstring dest, const_cstring src) {
            return fossil_cstr_copy(dest, src);
        }

        /**
         * Concatenate two classic C strings.
         * 
         * @param dest The destination string to concatenate to.
         * @param src  The source string to concatenate from.
         * @return cstring The concatenated string.
         */
        static cstring concat(cstring dest, const_cstring src) {
            return fossil_cstr_concat(dest, src);
        }

        /**
         * Find a character in a classic C string.
         * 
         * @param str The classic C string to search.
         * @param ch  The character to find.
         * @return const_cstring A pointer to the found character or NULL if not found.
         */
        static const_cstring find(const_cstring str, cletter ch) {
            return fossil_cstr_find(str, ch);
        }

        /**
         * Reverse a classic C string.
         * 
         * @param str The classic C string to reverse.
         * @return const_cstring The reversed string.
         */
        static const_cstring reverse(const_cstring str) {
            return fossil_cstr_reverse(str);
        }

        /**
         * Split a classic C string by delimiter.
         * 
         * @param str       The classic C string to split.
         * @param delimiter The delimiter character to split by.
         * @return cstrings An array of strings containing the split substrings.
         */
        static cstrings split(const_cstring str, cletter delimiter) {
            return fossil_cstr_split(str, delimiter);
        }

        /**
         * Duplicate a classic C string.
         * 
         * @param str The classic C string to duplicate.
         * @return cstring A newly allocated string containing a copy of the input string.
         */
        static cstring strdup(const_cstring str) {
            return fossil_cstr_strdup(str);
        }

        /**
         * Extracts a substring from a null-terminated C string.
         * 
         * @param str   The null-terminated C string from which to extract the substring.
         * @param start The starting index of the substring.
         * @param len   The length of the substring to extract.
         * @return cstring A dynamically allocated null-terminated C string containing the extracted substring, or NULL if memory allocation fails or invalid parameters are provided.
         */
        static cstring substr(const_cstring str, size_t start, size_t len) {
            return fossil_cstr_substr(str, start, len);
        }

        /**
         * Frees the memory allocated for an array of C strings and the strings it contains.
         * 
         * @param splits An array of C strings to be freed.
         * 
         * @note After calling this function, the C strings in the array `splits` will be deallocated and the array itself will be set to NULL.
         */
        static void erase_splits(cstrings splits) {
            fossil_cstr_erase_splits(splits);
        }

        /**
         * Compare two byte strings.
         * 
         * @param str1 The first byte string to compare.
         * @param str2 The second byte string to compare.
         * @return int 0 if the strings are equal, a negative value if the first string is less than the second string, and a positive value if the first string is greater than the second string.
         */
        static int compare(const_bstring str1, const_bstring str2) {
            return fossil_bstr_compare(str1, str2);
        }

        /**
         * Copy a byte string.
         * 
         * @param dest The destination string to copy to.
         * @param src  The source string to copy from.
         * @return bstring The destination string.
         */
        static bstring copy(bstring dest, const_bstring src) {
            return fossil_bstr_copy(dest, src);
        }

        /**
         * Concatenate two byte strings.
         * 
         * @param dest The destination string to concatenate to.
         * @param src  The source string to concatenate from.
         * @return bstring The concatenated string.
         */
        static bstring concat(bstring dest, const_bstring src) {
            return fossil_bstr_concat(dest, src);
        }

        /**
         * Find a character in a byte string.
         * 
         * @param str The byte string to search.
         * @param ch  The character to find.
         * @return const_bstring A pointer to the found character or NULL if not found.
         */
        static const_bstring find(const_bstring str, bletter ch) {
            return fossil_bstr_find(str, ch);
        }

        /**
         * Reverse a byte string.
         * 
         * @param str The byte string to reverse.
         * @return const_bstring The reversed string.
         */
        static const_bstring reverse(const_bstring str) {
            return fossil_bstr_reverse(str);
        }

        /**
         * Split a byte string by delimiter.
         * 
         * @param str       The byte string to split.
         * @param delimiter The delimiter character to split by.
         * @return bstrings An array of strings containing the split substrings.
         */
        static bstrings split(const_bstring str, bletter delimiter) {
            return fossil_bstr_split(str, delimiter);
        }

        /**
         * Duplicate a byte string.
         * 
         * @param str The byte string to duplicate.
         * @return bstring A newly allocated string containing a copy of the input string.
         */
        static bstring strdup(const_bstring str) {
            return fossil_bstr_strdup(str);
        }

        /**
         * Extracts a substring from a byte string.
         * 
         * @param str   The byte string from which to extract the substring.
         * @param start The starting index of the substring.
         * @param len   The length of the substring to extract.
         * @return bstring A dynamically allocated byte string containing the extracted substring, or NULL if memory allocation fails or invalid parameters are provided.
         */
        static bstring substr(const_bstring str, size_t start, size_t len) {
            return fossil_bstr_substr(str, start, len);
        }

        /**
         * Frees the memory allocated for an array of byte strings and the strings it contains.
         * 
         * @param splits An array of byte strings to be freed.
         * 
         * @note After calling this function, the byte strings in the array `splits` will be deallocated and the array itself will be set to NULL.
         */
        static void erase_splits(bstrings splits) {
            fossil_bstr_erase_splits(splits);
        }

        /**
         * Compare two classic C strings.
         * 
         * @param str1 The first classic C string to compare.
         * @param str2 The second classic C string to compare.
         * @return int 0 if the strings are equal, a negative value if the first string is less than the second string, and a positive value if the first string is greater than the second string.
         */
        static int compare(const_wstring str1, const_wstring str2) {
            return fossil_wstr_compare(str1, str2);
        }

        /**
         * Copy a classic C string.
         * 
         * @param dest The destination string to copy to.
         * @param src  The source string to copy from.
         * @return wstring The destination string.
         */
        static wstring copy(wstring dest, const_wstring src) {
            return fossil_wstr_copy(dest, src);
        }

        /**
         * Concatenate two classic C strings.
         * 
         * @param dest The destination string to concatenate to.
         * @param src  The source string to concatenate from.
         * @return wstring The concatenated string.
         */
        static wstring concat(wstring dest, const_wstring src) {
            return fossil_wstr_concat(dest, src);
        }

        /**
         * Find a character in a classic C string.
         * 
         * @param str The classic C string to search.
         * @param ch  The character to find.
         * @return const_wstring A pointer to the found character or NULL if not found.
         */
        static const_wstring find(const_wstring str, wletter ch) {
            return fossil_wstr_find(str, ch);
        }

        /**
         * Reverse a classic C string.
         * 
         * @param str The classic C string to reverse.
         * @return const_wstring The reversed string.
         */
        static const_wstring reverse(const_wstring str) {
            return fossil_wstr_reverse(str);
        }

        /**
         * Split a classic C string by delimiter.
         * 
         * @param str       The classic C string to split.
         * @param delimiter The delimiter character to split by.
         * @return wstrings An array of strings containing the split substrings.
         */
        static wstrings split(const_wstring str, wletter delimiter) {
            return fossil_wstr_split(str, delimiter);
        }

        /**
         * Duplicate a classic C string.
         * 
         * @param str The classic C string to duplicate.
         * @return wstring A newly allocated string containing a copy of the input string.
         */
        static wstring strdup(const_wstring str) {
            return fossil_wstr_strdup(str);
        }

        /**
         * Extracts a substring from a null-terminated C string.
         * 
         * @param str   The null-terminated C string from which to extract the substring.
         * @param start The starting index of the substring.
         * @param len   The length of the substring to extract.
         * @return wstring A dynamically allocated null-terminated C string containing the extracted substring, or NULL if memory allocation fails or invalid parameters are provided.
         */
        static wstring substr(const_wstring str, size_t start, size_t len) {
            return fossil_wstr_substr(str, start, len);
        }

        /**
         * Frees the memory allocated for an array of C strings and the strings it contains.
         * 
         * @param splits An array of C strings to be freed.
         * 
         * @note After calling this function, the C strings in the array `splits` will be deallocated and the array itself will be set to NULL.
         */
        static void erase_splits(wstrings splits) {
            fossil_wstr_erase_splits(splits);
        }

    };
}
#endif

#endif
