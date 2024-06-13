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
#include "fossil/core/regex.h" // lib source code

#include <fossil/unittest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// placeholder

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Test case for initializing error with a message
FOSSIL_TEST(test_regex_match_and_extract_normal) {
    fossil_regex_t my_regex;
    const char *pattern = "a.*b";
    const char *text = "@A123b!";

    // Initialize regex
    ASSUME_ITS_EQUAL_I32(0, fossil_regex_create(&my_regex, pattern));

    // Match and extract substring
    const char *matched_substring = fossil_regex_match_and_extract(&my_regex, text);

    ASSUME_NOT_CNULL(matched_substring);
    ASSUME_ITS_EQUAL_CSTR("A123b", matched_substring);

    // Reset regex for reuse
    fossil_regex_reset(&my_regex);

    // Match again with a different text
    const char *new_text = "xyab";
    ASSUME_ITS_TRUE(fossil_regex_match(&my_regex, new_text));

    // Clean up
    ASSUME_ITS_EQUAL_CSTR("xyab", fossil_regex_get_matched_substring(&my_regex));
}

FOSSIL_TEST(test_regex_match_and_extract_no_match) {
    fossil_regex_t my_regex;
    const char *pattern_no_match = "x.*y";
    ASSUME_ITS_TRUE(fossil_regex_create(&my_regex, pattern_no_match) == 0);
    ASSUME_ITS_FALSE(fossil_regex_match(&my_regex, "abc") == 1);
}

FOSSIL_TEST(test_regex_match_and_extract_empty_pattern) {
    fossil_regex_t my_regex;
    const char *empty_pattern = "";
    ASSUME_ITS_TRUE(fossil_regex_create(&my_regex, empty_pattern) == 0);
    ASSUME_ITS_TRUE(fossil_regex_match(&my_regex, "abc") == 1);
}

FOSSIL_TEST(test_regex_match_and_extract_single_char_pattern) {
    fossil_regex_t my_regex;
    const char *single_char_pattern = "a";
    ASSUME_ITS_TRUE(fossil_regex_create(&my_regex, single_char_pattern) == 0);
    ASSUME_ITS_TRUE(fossil_regex_match(&my_regex, "abc") == 1);
}

FOSSIL_TEST(test_regex_match_and_extract_star_pattern) {
    fossil_regex_t my_regex;
    const char *star_pattern = "*";
    ASSUME_ITS_TRUE(fossil_regex_create(&my_regex, star_pattern) == 0);
    ASSUME_ITS_TRUE(fossil_regex_match(&my_regex, "abc") == 1);
}

FOSSIL_TEST(test_regex_match_and_extract_dot_star_pattern) {
    fossil_regex_t my_regex;
    const char *dot_star_pattern = ".*";
    ASSUME_ITS_TRUE(fossil_regex_create(&my_regex, dot_star_pattern) == 0);
    ASSUME_ITS_TRUE(fossil_regex_match(&my_regex, "abc") == 1);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_regex_group) {
    ADD_TEST(test_regex_match_and_extract_normal);
    ADD_TEST(test_regex_match_and_extract_no_match);
    ADD_TEST(test_regex_match_and_extract_empty_pattern);
    ADD_TEST(test_regex_match_and_extract_single_char_pattern);
    ADD_TEST(test_regex_match_and_extract_star_pattern);
    ADD_TEST(test_regex_match_and_extract_dot_star_pattern);
} // end of function main
