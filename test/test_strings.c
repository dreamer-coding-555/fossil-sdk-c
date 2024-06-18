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
    ASSUME_ITS_TRUE(cnullptr == fossil_cstr_create(cstring));
    fossil_cstr_erase(cstring); // Clean up after creating a cstring
}

// Test case 2: Test fossil_cstring_length
FOSSIL_TEST(test_fossil_cstring_length) {
    cstring cstring = "Hello, World!";
    ASSUME_ITS_TRUE(fossil_cstr_length(cstring) == 13);
}

// Test case 3: Test fossil_cstring_copy
FOSSIL_TEST(test_fossil_cstring_copy) {
    cstring src = "Hello, World!";
    cstring dest = cnullptr;
    fossil_cstr_copy(dest, src);
    ASSUME_ITS_TRUE(fossil_cstr_compare(src, dest) == 0);
    fossil_cstr_erase(dest); // Clean up after copying
}

// Test case 4: Test fossil_cstring_concatenate
FOSSIL_TEST(test_fossil_cstring_concatenate) {
    cstring str1 = "Hello, ";
    cstring str2 = "World!";
    cstring result = fossil_cstr_concat(str1, str2);
    ASSUME_ITS_TRUE(fossil_cstr_compare(result, "Hello, World!") == 0);
    fossil_cstr_erase(result); // Clean up after concatenating
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

// Test case 2: Test fossil_wstring_length
FOSSIL_TEST(test_fossil_wstring_length) {
    wstring var = L"Hello, World!";
    ASSUME_ITS_TRUE(fossil_wstr_length(var) == 13);
}

// Test case 3: Test fossil_wstring_copy
FOSSIL_TEST(test_fossil_wstring_copy) {
    wstring src = L"Hello, World!";
    wstring dest = cnullptr;
    fossil_wstr_copy(dest, src);
    ASSUME_ITS_TRUE(fossil_wstr_compare(src, dest) == 0);
    fossil_wstr_erase(dest); // Clean up after copying
}

// Test case 4: Test fossil_wstring_concatenate
FOSSIL_TEST(test_fossil_wstring_concatenate) {
    wstring str1 = L"Hello, ";
    wstring str2 = L"World!";
    wstring result = fossil_wstr_concat(str1, str2);
    ASSUME_ITS_TRUE(fossil_wstr_compare(result, L"Hello, World!") == 0);
    fossil_wstr_erase(result); // Clean up after concatenating
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

// Test case 2: Test fossil_bstring_length
FOSSIL_TEST(test_fossil_bstring_length) {
    bstring var = FOSSIL_STATIC_CAST(bstring, "Hello, World!");
    ASSUME_ITS_TRUE(fossil_bstr_length(var) == 13);
}

// Test case 3: Test fossil_bstring_copy
FOSSIL_TEST(test_fossil_bstring_copy) {
    bstring src = FOSSIL_STATIC_CAST(bstring, "Hello, World!");
    bstring dest = cnullptr;
    fossil_bstr_copy(dest, src);
    ASSUME_ITS_TRUE(fossil_bstr_compare(src, dest) == 0);
    fossil_bstr_erase(dest); // Clean up after copying
}

// Test case 4: Test fossil_bstring_concatenate
FOSSIL_TEST(test_fossil_bstring_concatenate) {
    bstring str1 = FOSSIL_STATIC_CAST(bstring, "Hello, ");
    bstring str2 = FOSSIL_STATIC_CAST(bstring, "World!");
    bstring result = fossil_bstr_concat(str1, str2);
    ASSUME_ITS_TRUE(fossil_bstr_compare(result, FOSSIL_STATIC_CAST(bstring, "Hello, World!")) == 0);
    fossil_bstr_erase(result); // Clean up after concatenating
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_strings_tests) {    
    // Classic Strings Fixture
    ADD_TESTF(test_fossil_cstring_create, c_string_fixture);
    ADD_TESTF(test_fossil_cstring_length, c_string_fixture);
    ADD_TESTF(test_fossil_cstring_copy, c_string_fixture);
    ADD_TESTF(test_fossil_cstring_concatenate, c_string_fixture);

    // Wide Strings Fixture
    ADD_TESTF(test_fossil_wstring_create, w_string_fixture);
    ADD_TESTF(test_fossil_wstring_length, w_string_fixture);
    ADD_TESTF(test_fossil_wstring_copy, w_string_fixture);
    ADD_TESTF(test_fossil_wstring_concatenate, w_string_fixture);

    // Byte Strings Fixture
    ADD_TESTF(test_fossil_bstring_create, b_string_fixture);
    ADD_TESTF(test_fossil_bstring_length, b_string_fixture);
    ADD_TESTF(test_fossil_bstring_copy, b_string_fixture);
    ADD_TESTF(test_fossil_bstring_concatenate, b_string_fixture);
} // end of tests
