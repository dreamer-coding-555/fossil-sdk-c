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
#include <fossil/xalgorithms/greedy.h> // library under test

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

FOSSIL_TEST(test_fossil_greedy_coin_change) {
    // Test case 1: Standard case
    fossil_tofu_t* coins1 = fossil_tofu_create_array(TOFU_INT_TYPE, 4, 1, 2, 5, 10);
    int result1 = fossil_greedy_coin_change(coins1, 13);
    ASSUME_ITS_EQUAL_I32(3, result1);  // Expected result: 3 coins (10 + 2 + 1)

    // Test case 2: Edge case (no coins required)
    fossil_tofu_t* coins2 = fossil_tofu_create_array(TOFU_INT_TYPE, 1, 1);
    int result2 = fossil_greedy_coin_change(coins2, 0);
    ASSUME_ITS_EQUAL_I32(0, result2);  // Expected result: 0 coins

    // Test case 3: Edge case (large amount)
    fossil_tofu_t* coins3 = fossil_tofu_create_array(TOFU_INT_TYPE, 1, 1);
    int result3 = fossil_greedy_coin_change(coins3, 1000);
    ASSUME_ITS_EQUAL_I32(1000, result3);  // Expected result: 1000 coins (each worth 1)

    // Cleanup
    fossil_tofu_erase_array(coins1);
    fossil_tofu_erase_array(coins2);
    fossil_tofu_erase_array(coins3);
}

FOSSIL_TEST(test_fossil_greedy_fractional_knapsack) {
    // Test case 1: Standard case
    fossil_tofu_t* weights1 = fossil_tofu_create_array(TOFU_DOUBLE_TYPE, 3, 10.0, 20.0, 30.0);
    fossil_tofu_t* values1 = fossil_tofu_create_array(TOFU_DOUBLE_TYPE, 3, 60.0, 100.0, 120.0);
    double result1 = fossil_greedy_fractional_knapsack(weights1, values1, 50);
    TEST_ASSUME_DOUBLE_EQUAL(240.0, result1);  // Expected result: Maximum value of 240.0

    // Cleanup
    fossil_tofu_erase_array(weights1);
    fossil_tofu_erase_array(values1);
}

FOSSIL_TEST(test_fossil_greedy_interval_scheduling) {
    // Test case 1: Standard case
    fossil_tofu_t* startTimes1 = fossil_tofu_create_array(TOFU_INT_TYPE, 4, 1, 3, 0, 5);
    fossil_tofu_t* endTimes1 = fossil_tofu_create_array(TOFU_INT_TYPE, 4, 2, 4, 6, 7);
    int result1 = fossil_greedy_interval_scheduling(startTimes1, endTimes1);
    ASSUME_ITS_EQUAL_I32(3, result1);  // Expected result: Maximum number of non-overlapping tasks is 3

    // Cleanup
    fossil_tofu_erase_array(startTimes1);
    fossil_tofu_erase_array(endTimes1);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(greedy_group) {
    ADD_TEST(test_fossil_greedy_coin_change);
    ADD_TEST(test_fossil_greedy_fractional_knapsack);
    ADD_TEST(test_fossil_greedy_interval_scheduling);
} // end of fixture
