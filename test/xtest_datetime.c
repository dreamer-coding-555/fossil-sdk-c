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
#include "fossil/core/datetime.h" // lib source code

#include <fossil/unittest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_DATA(FormatTestData) {
    fossil_datetime_t datetime;
} format;

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Test cases for datetime_get_current_parse_military function.
FOSSIL_TEST(datetime_let_parse_military_success) {
    const char *input = "2023-09-28 15:30:00 +0300";
    ASSUME_ITS_TRUE(fossil_datetime_get_current_parse_military(input, &format.datetime));
}

FOSSIL_TEST(datetime_let_parse_military_failure) {
    const char *input = "invalid_datetime_string";
    ASSUME_ITS_FALSE(fossil_datetime_get_current_parse_military(input, &format.datetime));
}

// Test cases for datetime_get_current_parse_12_hour function.
FOSSIL_TEST(datetime_let_parse_12_hour_success) {
    const char *input = "2023-09-28 03:30 PM +0300";
    ASSUME_ITS_TRUE(fossil_datetime_get_current_parse_12_hour(input, &format.datetime));
}

FOSSIL_TEST(datetime_let_parse_12_hour_failure) {
    const char *input = "invalid_datetime_string";
    ASSUME_ITS_FALSE(fossil_datetime_get_current_parse_12_hour(input, &format.datetime));
}

// Test cases for datetime_get_current_parse_human_readable function.
FOSSIL_TEST(datetime_let_parse_human_readable_success) {
    const char *input = "28-Sep-2023, 3:30 PM";
    ASSUME_ITS_TRUE(fossil_datetime_get_current_parse_human_readable(input, &format.datetime));
}

FOSSIL_TEST(datetime_let_parse_human_readable_failure) {
    const char *input = "invalid_datetime_string";
    ASSUME_ITS_FALSE(fossil_datetime_get_current_parse_human_readable(input, &format.datetime));
}

// Test case for an empty input string
FOSSIL_TEST(datetime_edge_parse_military_empty) {
    const char *input = "";
    ASSUME_ITS_FALSE(fossil_datetime_get_current_parse_military(input, &format.datetime));
}

// Test case for an invalid time zone
FOSSIL_TEST(datetime_edge_parse_military_invalid_timezone) {
    const char *input = "2023-09-28 15:30:00 invalid_timezone";
    ASSUME_ITS_FALSE(fossil_datetime_get_current_parse_military(input, &format.datetime));
}

// Test case for an invalid input format
FOSSIL_TEST(datetime_edge_parse_military_invalid_format) {
    const char *input = "invalid_format";
    ASSUME_ITS_FALSE(fossil_datetime_get_current_parse_military(input, &format.datetime));
}

// Test case for an empty input string
FOSSIL_TEST(datetime_edge_parse_12_hour_empty) {
    const char *input = "";
    ASSUME_ITS_FALSE(fossil_datetime_get_current_parse_12_hour(input, &format.datetime));
}

// Test case for an invalid time zone
FOSSIL_TEST(datetime_edge_parse_12_hour_invalid_timezone) {
    const char *input = "2023-09-28 03:30 PM invalid_timezone";
    ASSUME_ITS_FALSE(fossil_datetime_get_current_parse_12_hour(input, &format.datetime));
}

// Test case for an invalid input format
FOSSIL_TEST(datetime_edge_parse_12_hour_invalid_format) {
    const char *input = "invalid_format";
    ASSUME_ITS_FALSE(fossil_datetime_get_current_parse_12_hour(input, &format.datetime));
}

// Test case for an empty input string
FOSSIL_TEST(datetime_edge_parse_human_readable_empty) {
    const char *input = "";
    ASSUME_ITS_FALSE(fossil_datetime_get_current_parse_human_readable(input, &format.datetime));
}

// Test case for an invalid input format
FOSSIL_TEST(datetime_edge_parse_human_readable_invalid_format) {
    const char *input = "invalid_format";
    ASSUME_ITS_FALSE(fossil_datetime_get_current_parse_human_readable(input, &format.datetime));
}

// Define the test cases
FOSSIL_TEST(test_trilo_xcore_get_current_datetime) {
    fossil_datetime_t current_datetime;
    
    // Call the function to get the current date and time
    fossil_datetime_get_current(&current_datetime);

    // Assuming the function worked correctly, you can check individual components
    ASSUME_ITS_TRUE(current_datetime.year >= 2023);  // Replace 2023 with the current year
    ASSUME_ITS_TRUE(current_datetime.month >= 1 && current_datetime.month <= 12);
    ASSUME_ITS_TRUE(current_datetime.day >= 1 && current_datetime.day <= 31);
    ASSUME_ITS_TRUE(current_datetime.hour >= 0 && current_datetime.hour <= 23);
    ASSUME_ITS_TRUE(current_datetime.minute >= 0 && current_datetime.minute <= 59);
    ASSUME_ITS_TRUE(current_datetime.second >= 0 && current_datetime.second <= 59);
    ASSUME_ITS_EQUAL_I32(-1, current_datetime.ampm);  // Assuming ampm is set to -1 as specified in the function
    // You can add additional assertions based on your specific requirements
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_datetiime_group) {
    ADD_TEST(test_trilo_xcore_get_current_datetime);
    ADD_TEST(datetime_let_parse_12_hour_failure);
    ADD_TEST(datetime_let_parse_12_hour_success);
    ADD_TEST(datetime_let_parse_human_readable_failure);
    ADD_TEST(datetime_let_parse_human_readable_success);
    ADD_TEST(datetime_let_parse_military_failure);
    ADD_TEST(datetime_let_parse_military_success);
    ADD_TEST(datetime_edge_parse_military_empty);
    ADD_TEST(datetime_edge_parse_military_invalid_timezone);
    ADD_TEST(datetime_edge_parse_military_invalid_format);
    ADD_TEST(datetime_edge_parse_12_hour_empty);
    ADD_TEST(datetime_edge_parse_12_hour_invalid_timezone);
    ADD_TEST(datetime_edge_parse_12_hour_invalid_format);
    ADD_TEST(datetime_edge_parse_human_readable_empty);
    ADD_TEST(datetime_edge_parse_human_readable_invalid_format);
} // end of function main
