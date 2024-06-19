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

// Test case 1: Test fossil_cstring_create with cnullptr
FOSSIL_TEST(test_fossil_cstring_create) {
    cstring var = cnullptr;
    ASSUME_ITS_TRUE(cnullptr == fossil_cstr_create(var));
    fossil_cstr_erase(var); // Clean up after creating a cstring
}

// Test case 2: Test fossil_cstring_create with a string
FOSSIL_TEST(test_fossil_cstring_create_with_value) {
    cstring var = "Pizza time!";
    ASSUME_ITS_EQUAL_CSTR("Pizza time!", fossil_cstr_create(var));
    fossil_cstr_erase(var); // Clean up after creating a cstring
}

// Test case 3: Test fossil_cstring_create with a string and length
FOSSIL_TEST(test_fossil_cstring_create_with_value_and_length) {
    cstring var = "Pizza";
    ASSUME_ITS_EQUAL_CSTR("Pizza", fossil_cstr_create(var));
    ASSUME_ITS_EQUAL_SIZE(5, fossil_cstr_length(var));
    fossil_cstr_erase(var); // Clean up after creating a cstring
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
    wstring var = cnullptr;
    ASSUME_ITS_TRUE(cnullptr == fossil_wstr_create(var));
    fossil_wstr_erase(var); // Clean up after creating a wstring
}

// Test case 2: Test fossil_wstring_create with a string
FOSSIL_TEST(test_fossil_wstring_create_with_value) {
    wstring var = L"Pizza time!";
    ASSUME_ITS_EQUAL_WSTR(L"Pizza time!", fossil_wstr_create(var));
    fossil_wstr_erase(var); // Clean up after creating a wstring
}

// Test case 3: Test fossil_wstring_create with a string and length
FOSSIL_TEST(test_fossil_wstring_create_with_value_and_length) {
    wstring var = L"Pizza";
    ASSUME_ITS_EQUAL_WSTR(L"Pizza", fossil_wstr_create(var));
    ASSUME_ITS_EQUAL_SIZE(5, fossil_wstr_length(var));
    fossil_wstr_erase(var); // Clean up after creating a wstring
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
    bstring var = cnullptr;
    ASSUME_ITS_TRUE(cnullptr == fossil_bstr_create(var));
    fossil_bstr_erase(var); // Clean up after creating a bstring
}

// Test case 2: Test fossil_bstring_create with a string
FOSSIL_TEST(test_fossil_bstring_create_with_value) {
    bstring var = "Pizza time!";
    ASSUME_ITS_EQUAL_BSTR("Pizza time!", fossil_bstr_create(var));
    fossil_bstr_erase(var); // Clean up after creating a bstring
}

// Test case 3: Test fossil_bstring_create with a string and length
FOSSIL_TEST(test_fossil_bstring_create_with_value_and_length) {
    bstring var = "Pizza";
    ASSUME_ITS_EQUAL_BSTR("Pizza", fossil_bstr_create(var));
    ASSUME_ITS_EQUAL_SIZE(5, fossil_bstr_length(var));
    fossil_bstr_erase(var); // Clean up after creating a bstring
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_strings_tests) {    
    // Classic Strings Fixture
    ADD_TESTF(test_fossil_cstring_create, c_string_fixture);
    ADD_TESTF(test_fossil_cstring_create_with_value, c_string_fixture);
    ADD_TESTF(test_fossil_cstring_create_with_value_and_length, c_string_fixture);

    // Wide Strings Fixture
    ADD_TESTF(test_fossil_wstring_create, w_string_fixture);
    ADD_TESTF(test_fossil_wstring_create_with_value, w_string_fixture);
    ADD_TESTF(test_fossil_wstring_create_with_value_and_length, w_string_fixture);

    // Byte Strings Fixture
    ADD_TESTF(test_fossil_bstring_create, b_string_fixture);
    ADD_TESTF(test_fossil_bstring_create_with_value, b_string_fixture);
    ADD_TESTF(test_fossil_bstring_create_with_value_and_length, b_string_fixture);
} // end of tests
