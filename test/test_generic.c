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
#include <fossil/generic/tofu.h>
#include <fossil/generic/arrayof.h>
#include <fossil/generic/mapof.h>
#include <fossil/generic/iterator.h>
#include <fossil/generic/actionof.h>

#include <fossil/unittest.h> // basic test tools
#include <fossil/xassume.h>  // extra asserts

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// Define a transformation function
fossil_tofu_t double_value(fossil_tofu_t tofu) {
    if (tofu.type == FOSSIL_TOFU_TYPE_INT) {
        tofu.value.int_val *= 2;
    }
    return tofu;
}

// Define a predicate function for filtering
bool is_even(fossil_tofu_t tofu) {
    if (tofu.type == FOSSIL_TOFU_TYPE_INT) {
        return tofu.value.int_val % 2 == 0;
    }
    return false;  // For other types, consider them as not matching the predicate
}

// Define a comparison function for sorting
int compare_int(fossil_tofu_t a, fossil_tofu_t b) {
    if (a.type == FOSSIL_TOFU_TYPE_INT && b.type == FOSSIL_TOFU_TYPE_INT) {
        return a.value.int_val - b.value.int_val;
    }
    return 0;  // Consider other types as equal for simplicity
}

// Define a reduction function
fossil_tofu_t sum_function(fossil_tofu_t a, fossil_tofu_t b) {
    if (a.type == FOSSIL_TOFU_TYPE_INT && b.type == FOSSIL_TOFU_TYPE_INT) {
        a.value.int_val += b.value.int_val;
    }
    return a;
}

// Define an accumulation function
fossil_tofu_t sum(fossil_tofu_t a, fossil_tofu_t b) {
    a.value.int_val += b.value.int_val;
    return a;
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Generic ToFu
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(c_tofu_fixture);
FOSSIL_SETUP(c_tofu_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(c_tofu_fixture) {
    // Teardown code if needed
}


// Test case for fossil_tofu_create function
FOSSIL_TEST(test_fossil_tofu_create) {
    // Test creating different types of fossil_tofu_t objects
    fossil_tofu_t tofu_int = fossil_tofu_create("int", "123");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_INT, tofu_int.type);
    ASSUME_ITS_EQUAL_I64(123, tofu_int.value.int_val);

    fossil_tofu_t tofu_float = fossil_tofu_create("float", "3.14");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_FLOAT, tofu_float.type);
    ASSUME_ITS_EQUAL_F32(3.14, tofu_float.value.float_val, FOSSIL_TEST_FLOAT_EPSILON);

    fossil_tofu_t tofu_bstr = fossil_tofu_create("bstr", "Hello");
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_BSTR, tofu_bstr.type);
    ASSUME_ITS_EQUAL_CSTR("Hello", tofu_bstr.value.byte_string_val);
}

// Test case for fossil_tofu_equals function
FOSSIL_TEST(test_fossil_tofu_equals) {
    fossil_tofu_t tofu1 = fossil_tofu_create("int", "100");
    fossil_tofu_t tofu2 = fossil_tofu_create("int", "100");
    ASSUME_ITS_TRUE(fossil_tofu_equals(tofu1, tofu2));

    fossil_tofu_t tofu3 = fossil_tofu_create("float", "3.14");
    ASSUME_ITS_FALSE(fossil_tofu_equals(tofu1, tofu3));
}

// Test case for fossil_tofu_copy function
FOSSIL_TEST(test_fossil_tofu_copy) {
    fossil_tofu_t tofu_orig = fossil_tofu_create("bstr", "Original");
    fossil_tofu_t tofu_copy = fossil_tofu_copy(tofu_orig);

    ASSUME_ITS_EQUAL_I32(tofu_orig.type, tofu_copy.type);
    ASSUME_ITS_EQUAL_CSTR(tofu_orig.value.byte_string_val, tofu_copy.value.byte_string_val);
    ASSUME_ITS_EQUAL_I32(tofu_orig.is_cached, tofu_copy.is_cached);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test ToFu ArrayOf
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(c_tofu_arrayof_fixture);
FOSSIL_SETUP(c_tofu_arrayof_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(c_tofu_arrayof_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_fossil_tofu_arrayof_create) {
    fossil_tofu_arrayof_t array = fossil_tofu_arrayof_create("int", 3, "10", "20", "30");
    ASSUME_ITS_EQUAL_I32(3, fossil_tofu_arrayof_size(&array));
    ASSUME_ITS_EQUAL_I32(10, array.array[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(20, array.array[1].value.int_val);
    ASSUME_ITS_EQUAL_I32(30, array.array[2].value.int_val);
    fossil_tofu_arrayof_erase(&array);
}

FOSSIL_TEST(test_fossil_tofu_arrayof_add) {
    fossil_tofu_arrayof_t array = fossil_tofu_arrayof_create("int", 0);
    fossil_tofu_t tofu1 = fossil_tofu_create("int", "10");
    fossil_tofu_t tofu2 = fossil_tofu_create("int", "20");
    fossil_tofu_arrayof_add(&array, tofu1);
    fossil_tofu_arrayof_add(&array, tofu2);
    ASSUME_ITS_EQUAL_I32(2, fossil_tofu_arrayof_size(&array));
    ASSUME_ITS_EQUAL_I32(10, array.array[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(20, array.array[1].value.int_val);
    fossil_tofu_arrayof_erase(&array);
}

FOSSIL_TEST(test_fossil_tofu_arrayof_get) {
    fossil_tofu_arrayof_t array = fossil_tofu_arrayof_create("int", 3, "10", "20", "30");
    fossil_tofu_t tofu = fossil_tofu_arrayof_get(&array, 1);
    ASSUME_ITS_EQUAL_I32(20, tofu.value.int_val);
    fossil_tofu_arrayof_erase(&array);
}

FOSSIL_TEST(test_fossil_tofu_arrayof_size) {
    fossil_tofu_arrayof_t array = fossil_tofu_arrayof_create("int", 2, "10", "20");
    ASSUME_ITS_EQUAL_I32(2, fossil_tofu_arrayof_size(&array));
    fossil_tofu_arrayof_erase(&array);
}

FOSSIL_TEST(test_fossil_tofu_arrayof_is_empty) {
    fossil_tofu_arrayof_t array = fossil_tofu_arrayof_create("int", 0);
    ASSUME_ITS_TRUE(fossil_tofu_arrayof_is_empty(&array));
    fossil_tofu_arrayof_erase(&array);
}

FOSSIL_TEST(test_fossil_tofu_arrayof_clear) {
    fossil_tofu_arrayof_t array = fossil_tofu_arrayof_create("int", 3, "10", "20", "30");
    fossil_tofu_arrayof_clear(&array);
    ASSUME_ITS_EQUAL_I32(0, fossil_tofu_arrayof_size(&array));
    ASSUME_ITS_TRUE(fossil_tofu_arrayof_is_empty(&array));
    fossil_tofu_arrayof_erase(&array);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test ToFu MapOf
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(c_tofu_mapof_fixture);
FOSSIL_SETUP(c_tofu_mapof_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(c_tofu_mapof_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_fossil_tofu_mapof_create) {
    fossil_tofu_mapof_t map = fossil_tofu_mapof_create(2);
    ASSUME_ITS_EQUAL_I32(0, fossil_tofu_mapof_size(&map));
    fossil_tofu_mapof_erase(&map);
}

FOSSIL_TEST(test_fossil_tofu_mapof_add_and_get) {
    fossil_tofu_mapof_t map = fossil_tofu_mapof_create(2);
    fossil_tofu_t key = fossil_tofu_create("int", "1");
    fossil_tofu_t value = fossil_tofu_create("int", "100");
    fossil_tofu_mapof_add(&map, key, value);
    fossil_tofu_t retrieved = fossil_tofu_mapof_get(&map, key);
    ASSUME_ITS_EQUAL_I32(100, retrieved.value.int_val);
    fossil_tofu_mapof_erase(&map);
}

FOSSIL_TEST(test_fossil_tofu_mapof_contains) {
    fossil_tofu_mapof_t map = fossil_tofu_mapof_create(2);
    fossil_tofu_t key = fossil_tofu_create("int", "1");
    fossil_tofu_t value = fossil_tofu_create("int", "100");
    fossil_tofu_mapof_add(&map, key, value);
    ASSUME_ITS_TRUE(fossil_tofu_mapof_contains(&map, key));
    fossil_tofu_mapof_erase(&map);
}

FOSSIL_TEST(test_fossil_tofu_mapof_remove) {
    fossil_tofu_mapof_t map = fossil_tofu_mapof_create(2);
    fossil_tofu_t key = fossil_tofu_create("int", "1");
    fossil_tofu_t value = fossil_tofu_create("int", "100");
    fossil_tofu_mapof_add(&map, key, value);
    fossil_tofu_mapof_remove(&map, key);
    ASSUME_ITS_FALSE(fossil_tofu_mapof_contains(&map, key));
    fossil_tofu_mapof_erase(&map);
}

FOSSIL_TEST(test_fossil_tofu_mapof_size) {
    fossil_tofu_mapof_t map = fossil_tofu_mapof_create(2);
    fossil_tofu_t key1 = fossil_tofu_create("int", "1");
    fossil_tofu_t value1 = fossil_tofu_create("int", "100");
    fossil_tofu_t key2 = fossil_tofu_create("int", "2");
    fossil_tofu_t value2 = fossil_tofu_create("int", "200");
    fossil_tofu_mapof_add(&map, key1, value1);
    fossil_tofu_mapof_add(&map, key2, value2);
    ASSUME_ITS_EQUAL_I32(2, fossil_tofu_mapof_size(&map));
    fossil_tofu_mapof_erase(&map);
}

FOSSIL_TEST(test_fossil_tofu_mapof_is_empty) {
    fossil_tofu_mapof_t map = fossil_tofu_mapof_create(2);
    ASSUME_ITS_TRUE(fossil_tofu_mapof_is_empty(&map));
    fossil_tofu_t key = fossil_tofu_create("int", "1");
    fossil_tofu_t value = fossil_tofu_create("int", "100");
    fossil_tofu_mapof_add(&map, key, value);
    ASSUME_ITS_FALSE(fossil_tofu_mapof_is_empty(&map));
    fossil_tofu_mapof_erase(&map);
}

FOSSIL_TEST(test_fossil_tofu_mapof_clear) {
    fossil_tofu_mapof_t map = fossil_tofu_mapof_create(2);
    fossil_tofu_t key = fossil_tofu_create("int", "1");
    fossil_tofu_t value = fossil_tofu_create("int", "100");
    fossil_tofu_mapof_add(&map, key, value);
    fossil_tofu_mapof_clear(&map);
    ASSUME_ITS_EQUAL_I32(0, fossil_tofu_mapof_size(&map));
    ASSUME_ITS_TRUE(fossil_tofu_mapof_is_empty(&map));
    fossil_tofu_mapof_erase(&map);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test ToFu IteratorOf
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(c_tofu_iterof_fixture);
FOSSIL_SETUP(c_tofu_iterof_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(c_tofu_iterof_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_fossil_tofu_iteratorof_create) {
    fossil_tofu_t array[2] = {
        fossil_tofu_create("int", "1"),
        fossil_tofu_create("int", "2")
    };
    fossil_tofu_iteratorof_t iterator = fossil_tofu_iteratorof_create(array, 2);
    ASSUME_ITS_EQUAL_I32(0, iterator.current_index);
    ASSUME_ITS_EQUAL_I32(2, iterator.size);
}

FOSSIL_TEST(test_fossil_tofu_iteratorof_has_next) {
    fossil_tofu_t array[2] = {
        fossil_tofu_create("int", "1"),
        fossil_tofu_create("int", "2")
    };
    fossil_tofu_iteratorof_t iterator = fossil_tofu_iteratorof_create(array, 2);
    ASSUME_ITS_TRUE(fossil_tofu_iteratorof_has_next(&iterator));
    iterator.current_index = 2;
    ASSUME_ITS_FALSE(fossil_tofu_iteratorof_has_next(&iterator));
}

FOSSIL_TEST(test_fossil_tofu_iteratorof_next) {
    fossil_tofu_t array[2] = {
        fossil_tofu_create("int", "1"),
        fossil_tofu_create("int", "2")
    };
    fossil_tofu_iteratorof_t iterator = fossil_tofu_iteratorof_create(array, 2);
    fossil_tofu_t first = fossil_tofu_iteratorof_next(&iterator);
    ASSUME_ITS_EQUAL_I32(1, first.value.int_val);
    fossil_tofu_t second = fossil_tofu_iteratorof_next(&iterator);
    ASSUME_ITS_EQUAL_I32(2, second.value.int_val);
    fossil_tofu_t third = fossil_tofu_iteratorof_next(&iterator);
    ASSUME_ITS_EQUAL_I32(FOSSIL_TOFU_TYPE_GHOST, third.type);
}

FOSSIL_TEST(test_fossil_tofu_iteratorof_reset) {
    fossil_tofu_t array[2] = {
        fossil_tofu_create("int", "1"),
        fossil_tofu_create("int", "2")
    };
    fossil_tofu_iteratorof_t iterator = fossil_tofu_iteratorof_create(array, 2);
    fossil_tofu_iteratorof_next(&iterator);
    fossil_tofu_iteratorof_reset(&iterator);
    ASSUME_ITS_EQUAL_I32(0, iterator.current_index);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test ToFu ActionOf
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(c_tofu_actof_fixture);
FOSSIL_SETUP(c_tofu_actof_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(c_tofu_actof_fixture) {
    // Teardown code if needed
}

// Test for transform function
FOSSIL_TEST(test_transform) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "30")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_actionof_transform(array, size, double_value);

    // Assertions using Unity framework
    ASSUME_ITS_EQUAL_I32(20, array[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(40, array[1].value.int_val);
    ASSUME_ITS_EQUAL_I32(60, array[2].value.int_val);
}

// Test for accumulate function
FOSSIL_TEST(test_accumulate) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "30")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_t init = fossil_tofu_create("int", "0");

    fossil_tofu_t result = fossil_tofu_actionof_accumulate(array, size, init, sum);

    // Assertions using Unity framework
    ASSUME_ITS_EQUAL_I32(60, result.value.int_val);
}

// Test for filter function
FOSSIL_TEST(test_filter) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "30")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    size_t filtered_size = fossil_tofu_actionof_filter(array, size, is_even);

    // Assertions using Unity framework
    ASSUME_ITS_EQUAL_I32(2, filtered_size);
    ASSUME_ITS_EQUAL_I32(20, array[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(30, array[1].value.int_val);
}

// Test for sort function
FOSSIL_TEST(test_sort) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "30"),
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_actionof_sort(array, size, compare_int);

    // Assertions using Unity framework
    ASSUME_ITS_EQUAL_I32(10, array[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(20, array[1].value.int_val);
    ASSUME_ITS_EQUAL_I32(30, array[2].value.int_val);
}

// Test for reverse function
FOSSIL_TEST(test_reverse) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "30")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_actionof_reverse(array, size);

    // Assertions using Unity framework
    ASSUME_ITS_EQUAL_I32(30, array[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(20, array[1].value.int_val);
    ASSUME_ITS_EQUAL_I32(10, array[2].value.int_val);
}

// Test for swap function
FOSSIL_TEST(test_swap) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "30")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_actionof_swap(array, 0, 2);

    // Assertions using Unity framework
    ASSUME_ITS_EQUAL_I32(30, array[0].value.int_val);
    ASSUME_ITS_EQUAL_I32(20, array[2].value.int_val);
}

// Test for reduce function
FOSSIL_TEST(test_reduce) {
    fossil_tofu_t array[] = {
        fossil_tofu_create("int", "10"),
        fossil_tofu_create("int", "20"),
        fossil_tofu_create("int", "30")
    };
    size_t size = sizeof(array) / sizeof(array[0]);

    fossil_tofu_t result = fossil_tofu_actionof_reduce(array, size, sum_function);

    // Assertions using Unity framework
    ASSUME_ITS_EQUAL_I32(60, result.value.int_val);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_generic_tests) {    
    // Generic ToFu Fixture
    ADD_TESTF(test_fossil_tofu_create, c_tofu_fixture);
    ADD_TESTF(test_fossil_tofu_equals, c_tofu_fixture);
    ADD_TESTF(test_fossil_tofu_copy, c_tofu_fixture);

    // Generic ToFu ArrayOf Fixture
    ADD_TESTF(test_fossil_tofu_arrayof_create, c_tofu_arrayof_fixture);
    ADD_TESTF(test_fossil_tofu_arrayof_add, c_tofu_arrayof_fixture);
    ADD_TESTF(test_fossil_tofu_arrayof_get, c_tofu_arrayof_fixture);
    ADD_TESTF(test_fossil_tofu_arrayof_size, c_tofu_arrayof_fixture);
    ADD_TESTF(test_fossil_tofu_arrayof_is_empty, c_tofu_arrayof_fixture);
    ADD_TESTF(test_fossil_tofu_arrayof_clear, c_tofu_arrayof_fixture);

    // Generic ToFu MapOf Fixture
    ADD_TESTF(test_fossil_tofu_mapof_create, c_tofu_mapof_fixture);
    ADD_TESTF(test_fossil_tofu_mapof_add_and_get, c_tofu_mapof_fixture);
    ADD_TESTF(test_fossil_tofu_mapof_contains, c_tofu_mapof_fixture);
    ADD_TESTF(test_fossil_tofu_mapof_remove, c_tofu_mapof_fixture);
    ADD_TESTF(test_fossil_tofu_mapof_size, c_tofu_mapof_fixture);
    ADD_TESTF(test_fossil_tofu_mapof_is_empty, c_tofu_mapof_fixture);
    ADD_TESTF(test_fossil_tofu_mapof_clear, c_tofu_mapof_fixture);

    // Generic ToFu IteratorOf Fixture
    ADD_TESTF(test_fossil_tofu_iteratorof_create, c_tofu_iterof_fixture);
    ADD_TESTF(test_fossil_tofu_iteratorof_has_next, c_tofu_iterof_fixture);
    ADD_TESTF(test_fossil_tofu_iteratorof_next, c_tofu_iterof_fixture);
    ADD_TESTF(test_fossil_tofu_iteratorof_reset, c_tofu_iterof_fixture);

    // Generic ToFu ActionOf Fixture
    ADD_TESTF(test_transform, c_tofu_actof_fixture);
    ADD_TESTF(test_accumulate, c_tofu_actof_fixture);
    ADD_TESTF(test_filter, c_tofu_actof_fixture);
    ADD_TESTF(test_sort, c_tofu_actof_fixture);
    ADD_TESTF(test_reverse, c_tofu_actof_fixture);
    ADD_TESTF(test_swap, c_tofu_actof_fixture);
    ADD_TESTF(test_reduce, c_tofu_actof_fixture);
} // end of tests
