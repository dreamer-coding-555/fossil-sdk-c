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
#ifndef FOSSIL_STDIO_SOAP_H
#define FOSSIL_STDIO_SOAP_H

#include <stdint.h>

/**
 * @brief String Offensive Acts Prevention (SOAP)
 * 
 * This library provides functions for string offensive acts prevention (SOAP) in C.
 * It includes functions to sanitize strings by replacing curse words with asterisks,
 * check if a word is offensive, and count the number of offensive words in a string.
 * These functions are useful for filtering and censoring offensive language in text data.
 * 
 * Key Features:
 * - Sanitize strings by replacing curse words with asterisks.
 * - Check if a word is considered offensive.
 * - Count the number of offensive words in a string.
 * 
 * Usage:
 * 
 * 1. Sanitize a string:
 *    @code
 *    char text[] = "You ****!";
 *    fossil_soap_sanitize(text);
 *    @endcode
 * 
 * 2. Check if a word is offensive:
 *    @code
 *    const char *word = "offensive_word";
 *    if (fossil_soap_is_offensive(word)) {
 *        // Word is offensive
 *    }
 *    @endcode
 * 
 * 3. Count offensive words in a string:
 *    @code
 *    const char *text = "This text contains offensive words.";
 *    int32_t count = fossil_soap_count_offensive(text);
 *    @endcode
 * 
 */

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Sanitize a string by replacing curse words with asterisks.
 * This function scans the input string for offensive words and replaces them with asterisks,
 * thereby making the string suitable for use in contexts where offensive language is not allowed.
 * The input string is modified in place.
 *
 * @param input The input string to be sanitized in-place.
 */
void fossil_soap_sanitize(char * restrict input);

/**
 * Check if a word is a curse word or racist phrase.
 * This function checks whether a given word is considered offensive.
 * It compares the word against a predefined list of offensive words and phrases
 * to determine its offensiveness.
 *
 * @param word The word to be checked for offensiveness.
 * @return     True if the word is offensive, false otherwise.
 */
int32_t fossil_soap_is_offensive(const char * restrict word);

/**
 * Get the number of offensive words found in a string.
 * This function counts the number of offensive words found in the input string.
 * It scans the entire string and checks each word against a list of offensive words
 * to determine the count of offensive occurrences.
 *
 * @param input The input string to be checked for offensive words.
 * @return      The number of offensive words found.
 */
int32_t fossil_soap_count_offensive(const char * restrict input);

#ifdef __cplusplus
}
#endif

#endif
