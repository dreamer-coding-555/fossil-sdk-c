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
#include <fossil/xstdio/soap.h> // library under test

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

FOSSIL_TEST(test_fossil_soap_sanitize) {
    char input[] = "This is a test with curse1 and racist_phrase1.";
    char expected[] = "This is a test with *** and ***.";

    fossil_soap_sanitize(input);

    ASSUME_ITS_EQUAL_CSTR(expected, input);
}

FOSSIL_TEST(test_fossil_soap_is_offensive) {
    ASSUME_ITS_TRUE(fossil_soap_is_offensive("curse1"));
    ASSUME_ITS_TRUE(fossil_soap_is_offensive("racist_phrase2"));
    ASSUME_ITS_FALSE(fossil_soap_is_offensive("non_offensive_word"));
}

FOSSIL_TEST(test_fossil_soap_count_offensive) {
    char input[] = "This is a test with curse1 and racist_phrase1.";
    ASSUME_ITS_EQUAL_I32(2, fossil_soap_count_offensive(input));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_soap_group) {
    ADD_TEST(test_fossil_soap_sanitize);
    ADD_TEST(test_fossil_soap_is_offensive);
    ADD_TEST(test_fossil_soap_count_offensive);
}
