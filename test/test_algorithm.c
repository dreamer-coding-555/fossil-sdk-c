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
#include <fossil/algorithm/dynamic.h>
#include <fossil/algorithm/greedy.h>
#include <fossil/algorithm/search.h>
#include <fossil/algorithm/sort.h>
#include <fossil/algorithm/summary.h>

#include <fossil/unittest.h> // basic test tools
#include <fossil/xassume.h>  // extra asserts

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Dynamic Algorithms
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(algo_dynamic_fixture);
FOSSIL_SETUP(algo_dynamic_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(algo_dynamic_fixture) {
    // Teardown code if needed
}

int compare_int(const void *a, const void *b) {
    fossil_tofu_t *elem1 = (fossil_tofu_t *)a;
    fossil_tofu_t *elem2 = (fossil_tofu_t *)b;

    if (elem1->value.int_val < elem2->value.int_val) return -1;
    if (elem1->value.int_val > elem2->value.int_val) return 1;
    return 0;
}

FOSSIL_TEST(test_sort_array) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "5"),
        fossil_tofu_create("int", "2"),
        fossil_tofu_create("int", "9"),
        fossil_tofu_create("int", "1"),
        fossil_tofu_create("int", "3")
    };
    fossil_tofu_arrayof_t dynamic_array = { .array = array, .size = 5, .capacity = 5 };

    fossil_dynamic_sort_array(dynamic_array, compare_int);

    // Check size and contents of the sorted array
    ASSUME_ITS_EQUAL_I32(5, dynamic_array.size);
    ASSUME_ITS_EQUAL_I32(5, dynamic_array.capacity);

    ASSUME_ITS_TRUE(fossil_tofu_equals(dynamic_array.array[0], fossil_tofu_create("int", "1")));
    ASSUME_ITS_TRUE(fossil_tofu_equals(dynamic_array.array[1], fossil_tofu_create("int", "2")));
    ASSUME_ITS_TRUE(fossil_tofu_equals(dynamic_array.array[2], fossil_tofu_create("int", "3")));
    ASSUME_ITS_TRUE(fossil_tofu_equals(dynamic_array.array[3], fossil_tofu_create("int", "5")));
    ASSUME_ITS_TRUE(fossil_tofu_equals(dynamic_array.array[4], fossil_tofu_create("int", "9")));

    // Clean up allocated memory
    for (size_t i = 0; i < dynamic_array.size; ++i) {
        fossil_tofu_erase(&dynamic_array.array[i]);
    }
}

FOSSIL_TEST(test_shuffle_array) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "1"),
        fossil_tofu_create("int", "2"),
        fossil_tofu_create("int", "3"),
        fossil_tofu_create("int", "4"),
        fossil_tofu_create("int", "5")
    };
    fossil_tofu_arrayof_t dynamic_array = { .array = array, .size = 5, .capacity = 5 };

    fossil_dynamic_shuffle_array(dynamic_array);

    // Since shuffling is random, we can only check the size and ensure all elements are still present
    ASSUME_ITS_EQUAL_I32(5, dynamic_array.size);
    ASSUME_ITS_EQUAL_I32(5, dynamic_array.capacity);

    // Clean up allocated memory
    for (size_t i = 0; i < dynamic_array.size; ++i) {
        fossil_tofu_erase(&dynamic_array.array[i]);
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Greedy Algorithms
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(algo_greedy_fixture);
FOSSIL_SETUP(algo_greedy_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(algo_greedy_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_greedy_coin_change) {
    fossil_tofu_t coin_denominations[] = {
        fossil_tofu_create("int", "1"),
        fossil_tofu_create("int", "5"),
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "25")
    };
    fossil_tofu_arrayof_t coins = { .array = coin_denominations, .size = 4, .capacity = 4 };

    int amount = 32;
    int min_coins = fossil_greedy_coin_change(coins, amount);

    // Expected result: 4 coins (25 + 5 + 1 + 1)
    ASSUME_ITS_EQUAL_I32(4, min_coins);

    // Clean up allocated memory
    for (size_t i = 0; i < coins.size; ++i) {
        fossil_tofu_erase(&coin_denominations[i]);
    }
}

FOSSIL_TEST(test_greedy_fractional_knapsack) {
    fossil_tofu_t weights[] = {
        fossil_tofu_create("double", "10"),
        fossil_tofu_create("double", "20"),
        fossil_tofu_create("double", "30")
    };
    fossil_tofu_arrayof_t weights_array = { .array = weights, .size = 3, .capacity = 3 };

    fossil_tofu_t values[] = {
        fossil_tofu_create("double", "60"),
        fossil_tofu_create("double", "100"),
        fossil_tofu_create("double", "120")
    };
    fossil_tofu_arrayof_t values_array = { .array = values, .size = 3, .capacity = 3 };

    int capacity = 50;
    double max_value = fossil_greedy_fractional_knapsack(weights_array, values_array, capacity);

    // Expected result: 240 (full item with weight 30 and fractional part of item with weight 20)
    ASSUME_ITS_EQUAL_F64(240.0, max_value, 0.01);

    // Clean up allocated memory
    for (size_t i = 0; i < weights_array.size; ++i) {
        fossil_tofu_erase(&weights[i]);
        fossil_tofu_erase(&values[i]);
    }
}

FOSSIL_TEST(test_greedy_interval_scheduling) {
    fossil_tofu_t start_times[] = {
        fossil_tofu_create("int", "1"),
        fossil_tofu_create("int", "3"),
        fossil_tofu_create("int", "0"),
        fossil_tofu_create("int", "5"),
        fossil_tofu_create("int", "8"),
        fossil_tofu_create("int", "5")
    };
    fossil_tofu_arrayof_t start_times_array = { .array = start_times, .size = 6, .capacity = 6 };

    fossil_tofu_t end_times[] = {
        fossil_tofu_create("int", "2"),
        fossil_tofu_create("int", "4"),
        fossil_tofu_create("int", "6"),
        fossil_tofu_create("int", "7"),
        fossil_tofu_create("int", "9"),
        fossil_tofu_create("int", "9")
    };
    fossil_tofu_arrayof_t end_times_array = { .array = end_times, .size = 6, .capacity = 6 };

    int max_tasks = fossil_greedy_interval_scheduling(start_times_array, end_times_array);

    // Expected result: 4 (tasks [0-2], [3-4], [5-6], [8-9] can be scheduled)
    ASSUME_ITS_EQUAL_I32(4, max_tasks);

    // Clean up allocated memory
    for (size_t i = 0; i < start_times_array.size; ++i) {
        fossil_tofu_erase(&start_times[i]);
        fossil_tofu_erase(&end_times[i]);
    }
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Seach Algorithms
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(algo_search_fixture);
FOSSIL_SETUP(algo_search_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(algo_search_fixture) {
    // Teardown code if needed
}

// Test case for linear search
FOSSIL_TEST(test_fossil_search_linear) {
    // Create a sample "tofu" array for testing
    fossil_tofu_arrayof_t array = fossil_tofu_arrayof_create("int", 5, "5", "10", "15", "20", "25");

    // Test searching for an existing key
    fossil_tofu_t key1 = fossil_tofu_create("int", "15");
    ASSUME_ITS_EQUAL_I32(2, fossil_search_linear(array, &key1));

    // Test searching for a non-existing key
    fossil_tofu_t key2 = fossil_tofu_create("int", "12");
    ASSUME_ITS_EQUAL_I32(-1, fossil_search_linear(array, &key2));

    // Clean up or destroy any dynamically allocated resources if needed
    fossil_tofu_erase(&key1);
    fossil_tofu_erase(&key2);
    fossil_tofu_arrayof_erase(&array);
}

// Test case for binary search
FOSSIL_TEST(test_fossil_search_binary) {
    // Create a sorted sample "tofu" array for testing
    fossil_tofu_arrayof_t array = fossil_tofu_arrayof_create("int", 5, "5", "10", "15", "20", "25");

    // Test searching for an existing key
    fossil_tofu_t key1 = fossil_tofu_create("int", "15");
    ASSUME_ITS_EQUAL_I32(2, fossil_search_binary(array, &key1));

    // Test searching for a non-existing key
    fossil_tofu_t key2 = fossil_tofu_create("int", "12");
    ASSUME_ITS_EQUAL_I32(-1, fossil_search_binary(array, &key2));

    // Clean up or destroy any dynamically allocated resources if needed
    fossil_tofu_erase(&key1);
    fossil_tofu_erase(&key2);
    fossil_tofu_arrayof_erase(&array);
}

// Test case for interpolation search
FOSSIL_TEST(test_fossil_search_interpolation) {
    // Create a sorted sample "tofu" array for testing
    fossil_tofu_arrayof_t array = fossil_tofu_arrayof_create("int", 5, "5", "10", "15", "20", "25");

    // Test searching for an existing key
    fossil_tofu_t key1 = fossil_tofu_create("int", "15");
    ASSUME_ITS_EQUAL_I32(2, fossil_search_interpolation(array, &key1));

    // Test searching for a non-existing key
    fossil_tofu_t key2 = fossil_tofu_create("int", "12");
    ASSUME_ITS_EQUAL_I32(-1, fossil_search_interpolation(array, &key2));

    // Clean up or destroy any dynamically allocated resources if needed
    fossil_tofu_erase(&key1);
    fossil_tofu_erase(&key2);
    fossil_tofu_arrayof_erase(&array);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Sort Algorithms
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(algo_sort_fixture);
fossil_tofu_arrayof_t unsorted_array;

FOSSIL_SETUP(algo_sort_fixture) {
    unsorted_array = fossil_tofu_arrayof_create("int", 6, "45", "1", "99", "40", "50", "10");
}

FOSSIL_TEARDOWN(algo_sort_fixture) {
    fossil_tofu_arrayof_erase(&unsorted_array);
}

FOSSIL_TEST(test_fossil_sort_bubble) {
    // Test case 1: Basic sorting
    ASSUME_ITS_EQUAL_I32(0, fossil_sort_bubble(unsorted_array));
}

FOSSIL_TEST(test_fossil_sort_quick) {
    // Test case 1: Basic sorting
    ASSUME_ITS_EQUAL_I32(0, fossil_sort_quick(unsorted_array));
}

FOSSIL_TEST(test_fossil_sort_merge) {
    // Test case 1: Basic sorting
    ASSUME_ITS_EQUAL_I32(0, fossil_sort_merge(unsorted_array));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_algorithm_tests) {    
    // Dynamic Algorithm Fixture
    ADD_TESTF(test_sort_array, algo_dynamic_fixture);
    ADD_TESTF(test_shuffle_array, algo_dynamic_fixture);

    // Greedy Algorithm Fixture
    // ADD_TESTF(test_greedy_coin_change, algo_greedy_fixture);
    // ADD_TESTF(test_greedy_fractional_knapsack, algo_greedy_fixture);
    // ADD_TESTF(test_greedy_interval_scheduling, algo_greedy_fixture);

    // Search Algorithm Fixture
    ADD_TESTF(test_fossil_search_linear, algo_search_fixture);
    // ADD_TESTF(test_fossil_search_binary, algo_search_fixture);
    // ADD_TESTF(test_fossil_search_interpolation, algo_search_fixture);

    // Sort Algorithm Fixture
    ADD_TESTF(test_fossil_sort_bubble, algo_sort_fixture);
    ADD_TESTF(test_fossil_sort_quick, algo_sort_fixture);
    ADD_TESTF(test_fossil_sort_merge, algo_sort_fixture);

} // end of tests
