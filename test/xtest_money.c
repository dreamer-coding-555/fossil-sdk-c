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
#include "fossil/stdtool/money.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
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

XTEST(test_money_create) {
    fossil_money_t m = fossil_money_create(10, 50, USD);
    ASSUME_ITS_EQUAL_I32(10, m.dollars);
    ASSUME_ITS_EQUAL_I32(50, m.cents);
    ASSUME_ITS_EQUAL_I32(USD, m.currency);
}

XTEST(test_money_add) {
    fossil_money_t m1 = fossil_money_create(10, 50, USD);
    fossil_money_t m2 = fossil_money_create(5, 25, USD);
    fossil_money_t result = fossil_money_add(m1, m2);
    ASSUME_ITS_EQUAL_I32(15, result.dollars);
    ASSUME_ITS_EQUAL_I32(75, result.cents);
    ASSUME_ITS_EQUAL_I32(USD, result.currency);
}

XTEST(test_money_convert) {
    fossil_money_t source = fossil_money_create(10, 50, USD);
    fossil_money_t result = fossil_money_convert(source, CAD);
    ASSUME_ITS_EQUAL_I32(10, result.dollars);
    ASSUME_ITS_EQUAL_I32(50, result.cents);
    ASSUME_ITS_EQUAL_I32(CAD, result.currency);
}

XTEST(test_money_display) {
    fossil_money_t m = fossil_money_create(10, 50, USD);
    fossil_money_display(m); // Just check if it doesn't crash
}

XTEST(test_money_is_valid) {
    fossil_money_t m = fossil_money_create(10, 50, USD);
    ASSUME_ITS_TRUE(fossil_money_is_valid(m));
}

XTEST(test_money_compare) {
    fossil_money_t m1 = fossil_money_create(10, 50, USD);
    fossil_money_t m2 = fossil_money_create(5, 25, USD);
    ASSUME_ITS_EQUAL_I32(1, fossil_money_compare(m1, m2));
}

XTEST(test_money_subtract) {
    fossil_money_t m1 = fossil_money_create(10, 50, USD);
    fossil_money_t m2 = fossil_money_create(5, 25, USD);
    fossil_money_t result = fossil_money_subtract(m1, m2);
    ASSUME_ITS_EQUAL_I32(5, result.dollars);
    ASSUME_ITS_EQUAL_I32(25, result.cents);
    ASSUME_ITS_EQUAL_I32(USD, result.currency);
}

XTEST(test_money_multiply_scalar) {
    fossil_money_t m = fossil_money_create(10, 50, USD);
    fossil_money_t result = fossil_money_multiply_scalar(m, 2);
    ASSUME_ITS_EQUAL_I32(21, result.dollars);
    ASSUME_ITS_EQUAL_I32(0, result.cents);
    ASSUME_ITS_EQUAL_I32(USD, result.currency);
}

XTEST(test_money_divide_scalar) {
    fossil_money_t m = fossil_money_create(10, 50, USD);
    fossil_money_t result = fossil_money_divide_scalar(m, 2);
    ASSUME_ITS_EQUAL_I32(5, result.dollars);
    ASSUME_ITS_EQUAL_I32(25, result.cents);
    ASSUME_ITS_EQUAL_I32(USD, result.currency);
}

XTEST(test_money_round) {
    fossil_money_t m = fossil_money_create(10, 55, USD);
    fossil_money_t result = fossil_money_round(m);
    ASSUME_ITS_EQUAL_I32(10, result.dollars);
    ASSUME_ITS_EQUAL_I32(56, result.cents);
    ASSUME_ITS_EQUAL_I32(USD, result.currency);
}

XTEST(test_money_is_positive) {
    fossil_money_t m = fossil_money_create(10, 50, USD);
    ASSUME_ITS_TRUE(fossil_money_is_positive(m));
}

XTEST(test_money_is_negative) {
    fossil_money_t m = fossil_money_create(-10, -50, USD);
    ASSUME_ITS_TRUE(fossil_money_is_negative(m));
}

XTEST(test_money_is_zero) {
    fossil_money_t m = fossil_money_create(0, 0, USD);
    ASSUME_ITS_TRUE(fossil_money_is_zero(m));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(test_money_group) {
    ADD_TEST(test_money_create);
    ADD_TEST(test_money_add);
    ADD_TEST(test_money_convert);
    ADD_TEST(test_money_display);
    ADD_TEST(test_money_is_valid);
    ADD_TEST(test_money_compare);
    ADD_TEST(test_money_subtract);
    ADD_TEST(test_money_multiply_scalar);
    ADD_TEST(test_money_divide_scalar);
    ADD_TEST(test_money_round);
    ADD_TEST(test_money_is_positive);
    ADD_TEST(test_money_is_negative);
    ADD_TEST(test_money_is_zero);
} // end of function main
