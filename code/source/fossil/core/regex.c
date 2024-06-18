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
#include "fossil/core/regex.h"
#include "fossil/common/common.h"
#include <ctype.h>

// Function prototypes
int32_t is_match(const char *text, const char *pattern);
int32_t match_group(const char *text, const char *pattern);

int32_t fossil_regex_create(fossil_regex_t *preg, const char*  pattern) {
    // Input validation: Check if preg or pattern is NULL
    if (preg == cnullptr || pattern == cnullptr) {
        return FOSSIL_REGEX_STATUS_FAILURE;
    }

    // Validate pattern length to prevent buffer overflow
    size_t pattern_len = strlen(pattern);
    if (pattern_len == 0 || pattern_len >= FOSSIL_REGEX_LIMIT_PATTERN_LENGTH) {
        return FOSSIL_REGEX_STATUS_FAILURE;
    }

    preg->pattern = pattern;
    preg->matched_substring = cnullptr;

    return FOSSIL_REGEX_STATUS_SUCCESS;
}

int32_t fossil_regex_match(fossil_regex_t *preg, const char*  text) {
    if (preg == cnullptr || text == cnullptr) {
        return FOSSIL_REGEX_STATUS_FAILURE;
    }

    // Call the actual matching function
    int result = is_match(text, preg->pattern);

    preg->matched_substring = result ? text : cnullptr;

    return result ? FOSSIL_REGEX_STATUS_SUCCESS : FOSSIL_REGEX_STATUS_FAILURE;
}

void fossil_regex_reset(fossil_regex_t *preg) {
    if (preg == cnullptr) {
        return;
    }

    preg->pattern = cnullptr;
    preg->matched_substring = cnullptr;
}

const char *fossil_regex_get_matched_substring(fossil_regex_t *preg) {
    if (preg == cnullptr) {
        return cnullptr;
    }
    return preg->matched_substring;
}

const char *fossil_regex_match_and_extract(fossil_regex_t *preg, const char*  text) {
    if (preg == cnullptr || text == cnullptr) {
        return cnullptr;
    }

    if (fossil_regex_match(preg, text) == FOSSIL_REGEX_STATUS_SUCCESS) {
        return fossil_regex_get_matched_substring(preg);
    } else {
        return cnullptr;
    }
}

// Actual regex matching function
int32_t is_match(const char *text, const char *pattern) {
    if (*pattern == '\0') {
        return *text == '\0';
    }

    if (*(pattern + 1) == '*') {
        return is_match(text, pattern + 2) || (*text != '\0' && (*pattern == '.' || *text == *pattern) && is_match(text + 1, pattern));
    } else {
        return (*text != '\0' && (*pattern == '.' || *text == *pattern) && is_match(text + 1, pattern + 1));
    }
}
