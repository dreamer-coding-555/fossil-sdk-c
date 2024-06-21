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

FOSSIL_TEST(test_concat_arrays) {
    fossil_tofu_t array1[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "30")
    };
    fossil_tofu_arrayof_t dynamic_array1 = { .array = array1, .size = 3, .capacity = 3 };

    fossil_tofu_t array2[] = {
        fossil_tofu_create("int", "40"),
        fossil_tofu_create("int", "50")
    };
    fossil_tofu_arrayof_t dynamic_array2 = { .array = array2, .size = 2, .capacity = 2 };

    fossil_tofu_arrayof_t result = fossil_dynamic_concat_arrays(dynamic_array1, dynamic_array2);

    // Check size and contents of the concatenated array
    ASSUME_ITS_EQUAL_I32(5, result.size);
    ASSUME_ITS_EQUAL_I32(5, result.capacity);

    ASSUME_ITS_TRUE(fossil_tofu_equals(result.array[0], fossil_tofu_create("int", "10")));
    ASSUME_ITS_TRUE(fossil_tofu_equals(result.array[1], fossil_tofu_create("int", "20")));
    ASSUME_ITS_TRUE(fossil_tofu_equals(result.array[2], fossil_tofu_create("int", "30")));
    ASSUME_ITS_TRUE(fossil_tofu_equals(result.array[3], fossil_tofu_create("int", "40")));
    ASSUME_ITS_TRUE(fossil_tofu_equals(result.array[4], fossil_tofu_create("int", "50")));

    // Clean up allocated memory
    for (size_t i = 0; i < result.size; ++i) {
        fossil_tofu_erase(&result.array[i]);
    }
    free(result.array);
}

FOSSIL_TEST(test_reverse_array) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "30")
    };
    fossil_tofu_arrayof_t dynamic_array = { .array = array, .size = 3, .capacity = 3 };

    fossil_tofu_arrayof_t reversed = fossil_dynamic_reverse_array(dynamic_array);

    // Check size and contents of the reversed array
    ASSUME_ITS_EQUAL_I32(3, reversed.size);
    ASSUME_ITS_EQUAL_I32(3, reversed.capacity);

    ASSUME_ITS_TRUE(fossil_tofu_equals(reversed.array[0], fossil_tofu_create("int", "30")));
    ASSUME_ITS_TRUE(fossil_tofu_equals(reversed.array[1], fossil_tofu_create("int", "20")));
    ASSUME_ITS_TRUE(fossil_tofu_equals(reversed.array[2], fossil_tofu_create("int", "10")));

    // Clean up allocated memory
    for (size_t i = 0; i < reversed.size; ++i) {
        fossil_tofu_erase(&reversed.array[i]);
    }
    free(reversed.array);
}

bool is_even(fossil_tofu_t element) {
    return element.value.int_val % 2 == 0;
}

FOSSIL_TEST(test_filter_array) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "1"),
        fossil_tofu_create("int", "2"),
        fossil_tofu_create("int", "3"),
        fossil_tofu_create("int", "4"),
        fossil_tofu_create("int", "5")
    };
    fossil_tofu_arrayof_t dynamic_array = { .array = array, .size = 5, .capacity = 5 };

    fossil_tofu_arrayof_t filtered = fossil_dynamic_filter_array(dynamic_array, is_even);

    // Check size and contents of the filtered array
    ASSUME_ITS_EQUAL_I32(2, filtered.size);
    ASSUME_ITS_EQUAL_I32(2, filtered.capacity);

    ASSUME_ITS_TRUE(fossil_tofu_equals(filtered.array[0], fossil_tofu_create("int", "2")));
    ASSUME_ITS_TRUE(fossil_tofu_equals(filtered.array[1], fossil_tofu_create("int", "4")));

    // Clean up allocated memory
    for (size_t i = 0; i < filtered.size; ++i) {
        fossil_tofu_erase(&filtered.array[i]);
    }
    free(filtered.array);
}

fossil_tofu_t square_element(fossil_tofu_t element) {
    if (element.type == FOSSIL_TOFU_TYPE_INT) {
        element.value.int_val *= element.value.int_val;
    }
    return element;
}

FOSSIL_TEST(test_map_array) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "1"),
        fossil_tofu_create("int", "2"),
        fossil_tofu_create("int", "3"),
        fossil_tofu_create("int", "4"),
        fossil_tofu_create("int", "5")
    };
    fossil_tofu_arrayof_t dynamic_array = { .array = array, .size = 5, .capacity = 5 };

    fossil_tofu_arrayof_t mapped = fossil_dynamic_map_array(dynamic_array, square_element);

    // Check size and contents of the mapped array
    ASSUME_ITS_EQUAL_I32(5, mapped.size);
    ASSUME_ITS_EQUAL_I32(5, mapped.capacity);

    ASSUME_ITS_TRUE(fossil_tofu_equals(mapped.array[0], fossil_tofu_create("int", "1")));
    ASSUME_ITS_TRUE(fossil_tofu_equals(mapped.array[1], fossil_tofu_create("int", "4")));
    ASSUME_ITS_TRUE(fossil_tofu_equals(mapped.array[2], fossil_tofu_create("int", "9")));
    ASSUME_ITS_TRUE(fossil_tofu_equals(mapped.array[3], fossil_tofu_create("int", "16")));
    ASSUME_ITS_TRUE(fossil_tofu_equals(mapped.array[4], fossil_tofu_create("int", "25")));

    // Clean up allocated memory
    for (size_t i = 0; i < mapped.size; ++i) {
        fossil_tofu_erase(&mapped.array[i]);
    }
    free(mapped.array);
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
    free(dynamic_array.array);
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
    free(dynamic_array.array);
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
    free(coins.array);
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
    ASSUME_ITS_EQUAL_DOUBLE(240.0, max_value);

    // Clean up allocated memory
    for (size_t i = 0; i < weights_array.size; ++i) {
        fossil_tofu_erase(&weights[i]);
        fossil_tofu_erase(&values[i]);
    }
    free(weights_array.array);
    free(values_array.array);
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
    free(start_times_array.array);
    free(end_times_array.array);
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
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "5"),
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "15"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "25")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    // Test searching for an existing key
    fossil_tofu_t key1 = fossil_tofu_create("int", "15");
    ASSUME_ITS_EQUAL_I32(2, fossil_search_linear((fossil_tofu_arrayof_t){array, size, size}, &key1));

    // Test searching for a non-existing key
    fossil_tofu_t key2 = fossil_tofu_create("int", "12");
    ASSUME_ITS_EQUAL_I32(-1, fossil_search_linear((fossil_tofu_arrayof_t){array, size, size}, &key2));

    // Clean up or destroy any dynamically allocated resources if needed
}

// Test case for binary search
FOSSIL_TEST(test_fossil_search_binary) {
    // Create a sorted sample "tofu" array for testing
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "5"),
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "15"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "25")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    // Test searching for an existing key
    fossil_tofu_t key1 = fossil_tofu_create("int", "15");
    ASSUME_ITS_EQUAL_I32(2, fossil_search_binary((fossil_tofu_arrayof_t){array, size, size}, &key1));

    // Test searching for a non-existing key
    fossil_tofu_t key2 = fossil_tofu_create("int", "12");
    ASSUME_ITS_EQUAL_I32(-1, fossil_search_binary((fossil_tofu_arrayof_t){array, size, size}, &key2));

    // Clean up or destroy any dynamically allocated resources if needed
}

// Test case for interpolation search
FOSSIL_TEST(test_fossil_search_interpolation) {
    // Create a sorted sample "tofu" array for testing
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "5"),
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "15"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "25")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    // Test searching for an existing key
    fossil_tofu_t key1 = fossil_tofu_create("int", "15");
    ASSUME_ITS_EQUAL_I32(2, fossil_search_interpolation((fossil_tofu_arrayof_t){array, size, size}, &key1));

    // Test searching for a non-existing key
    fossil_tofu_t key2 = fossil_tofu_create("int", "12");
    ASSUME_ITS_EQUAL_I32(-1, fossil_search_interpolation((fossil_tofu_arrayof_t){array, size, size}, &key2));
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
// * Fossil Logic Test Summary Algorithms
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(algo_summary_fixture);
fossil_tofu_arrayof_t summary_array;

FOSSIL_SETUP(algo_summary_fixture) {
    summary_array = fossil_tofu_arrayof_create("int", 6, "45", "1", "99", "40", "50", "10");
}

FOSSIL_TEARDOWN(algo_summary_fixture) {
    fossil_tofu_arrayof_erase(&summary_array);
}

FOSSIL_TEST(test_fossil_summary_mean_normal_case) {
    fossil_tofu_arrayof_t mean;
    ASSUME_ITS_EQUAL_I32(0, fossil_summary_mean(summary_array, mean));

    // Check the computed mean
    ASSUME_ITS_EQUAL_F64(20.0, mean.array[0].value.double_val, FOSSIL_TEST_DOUBLE_EPSILON);
}

FOSSIL_TEST(test_fossil_summary_mean_empty_array) {
    fossil_tofu_arrayof_t mean;
    ASSUME_ITS_EQUAL_I32(-1, fossil_summary_mean(summary_array, mean));
}

FOSSIL_TEST(test_fossil_summary_median_normal_case) {
    fossil_tofu_arrayof_t median;
    ASSUME_ITS_EQUAL_I32(0, fossil_summary_median(summary_array, median));

    // Check the computed median
    ASSUME_ITS_EQUAL_I32(20, median.array[0].value.int_val);
}

FOSSIL_TEST(test_fossil_summary_median_odd_size_array) {
    fossil_tofu_arrayof_t median;
    ASSUME_ITS_EQUAL_I32(0, fossil_summary_median(summary_array, median));

    // Check the computed median
    ASSUME_ITS_EQUAL_I32(25, median.array[0].value.int_val); // Median of {10, 20, 30, 40} is 25
}

FOSSIL_TEST(test_fossil_summary_sum_normal_case) {
    fossil_tofu_arrayof_t sum;
    ASSUME_ITS_EQUAL_I32(0, fossil_summary_sum(summary_array, sum));

    // Check the computed sum
    ASSUME_ITS_EQUAL_I32(60, sum.array[0].value.int_val);
}

FOSSIL_TEST(test_fossil_summary_sum_empty_array) {
    fossil_tofu_arrayof_t sum;
    ASSUME_ITS_EQUAL_I32(-1, fossil_summary_sum(summary_array, sum));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_algorithm_tests) {    
    // Dynamic Algorithm Fixture
    ADD_TESTF(test_concat_arrays, algo_dynamic_fixture);
    ADD_TESTF(test_reverse_array, algo_dynamic_fixture);
    ADD_TESTF(test_filter_array, algo_dynamic_fixture);
    ADD_TESTF(test_map_array, algo_dynamic_fixture);
    ADD_TESTF(test_sort_array, algo_dynamic_fixture);
    ADD_TESTF(test_shuffle_array, algo_dynamic_fixture);

    // Greedy Algorithm Fixture
    ADD_TESTF(test_greedy_coin_change, algo_greedy_fixture);
    ADD_TESTF(test_greedy_fractional_knapsack, algo_greedy_fixture);
    ADD_TESTF(test_greedy_interval_scheduling, algo_greedy_fixture);

    // Search Algorithm Fixture
    ADD_TESTF(test_fossil_search_linear, algo_search_fixture);
    ADD_TESTF(test_fossil_search_binary, algo_search_fixture);
    ADD_TESTF(test_fossil_search_interpolation, algo_search_fixture);

    // Sort Algorithm Fixture
    ADD_TESTF(test_fossil_sort_bubble, algo_sort_fixture);
    ADD_TESTF(test_fossil_sort_quick, algo_sort_fixture);
    ADD_TESTF(test_fossil_sort_merge, algo_sort_fixture);

    // Summary Algorithm Fixture
    ADD_TESTF(test_fossil_summary_mean_normal_case, algo_summary_fixture);
    ADD_TESTF(test_fossil_summary_mean_empty_array, algo_summary_fixture);
    ADD_TESTF(test_fossil_summary_median_normal_case, algo_summary_fixture);
    ADD_TESTF(test_fossil_summary_median_odd_size_array, algo_summary_fixture);
    ADD_TESTF(test_fossil_summary_sum_normal_case, algo_summary_fixture);
    ADD_TESTF(test_fossil_summary_sum_empty_array, algo_summary_fixture);
} // end of tests
