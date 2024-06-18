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
#include <fossil/strings/cstring.h>
#include <fossil/strings/bstring.h>
#include <fossil/strings/wstring.h>
#include <fossil/strings/format.h>
#include <fossil/strings/cipher.h>
#include <fossil/strings/manip.h>
#include <fossil/strings/strto.h>
#include <fossil/strings/strfrom.h>

#include <fossil/unittest.h> // basic test tools
#include <fossil/xassume.h>  // extra asserts

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test classic string
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(c_string_fixture);
FOSSIL_SETUP(c_string_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(c_string_fixture) {
    // Teardown code if needed
}

// Test case 1: Test fossil_cstring_create
FOSSIL_TEST(test_fossil_cstring_create) {
    cstring cstring = cnullptr;
    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_cstr_create(cstring));
    fossil_cstr_erase(cstring); // Clean up after creating a cstring
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test wide string
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_FIXTURE(w_string_fixture);
FOSSIL_SETUP(w_string_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(w_string_fixture) {
    // Teardown code if needed
}

// Test case 1: Test fossil_wstring_create
FOSSIL_TEST(test_fossil_wstring_create) {
    wstring wstring = cnullptr;
    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_wstr_create(wstring));
    fossil_wstr_erase(wstring); // Clean up after creating a wstring
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test byte string
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_FIXTURE(b_string_fixture);
FOSSIL_SETUP(b_string_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(b_string_fixture) {
    // Teardown code if needed
}

// Test case 1: Test fossil_bstring_create
FOSSIL_TEST(test_fossil_bstring_create) {
    bstring bstring = cnullptr;
    ASSUME_ITS_EQUAL_I32(FOSSIL_SUCCESS, fossil_bstr_create(bstring));
    fossil_bstr_erase(bstring); // Clean up after creating a bstring
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_strings_tests) {    
    // Classic Strings Fixture
    ADD_TESTF(test_fossil_cstring_create, c_string_fixture);

    // Wide Strings Fixture
    ADD_TESTF(test_fossil_wstring_create, w_string_fixture);

    // Byte Strings Fixture
    ADD_TESTF(test_fossil_bstring_create, b_string_fixture);
} // end of tests
