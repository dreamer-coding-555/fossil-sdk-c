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
#include "fossil/xstructures/map.h" // lib source code

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

FOSSIL_TEST(test_map_create_and_erase) {
    cmap* map = fossil_map_create(TOFU_INT_TYPE);

    // Check if the map is created with the expected values
    ASSUME_NOT_CNULL(map);
    TEST_ASSUME_EQUAL_UINT(0, map->size);

    fossil_map_erase(map);

    // Check if the map is erased
    TEST_ASSUME_EQUAL_UINT(0, map->size);
    ASSUME_ITS_CNULL(map);
}

FOSSIL_TEST(test_map_insert_and_size) {
    cmap* map = fossil_map_create(TOFU_INT_TYPE);

    // Insert some key-value pairs
    fossil_tofu_t key1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t value1 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t key2 = { TOFU_INT_TYPE, { .int_type = 5 } };
    fossil_tofu_t value2 = { TOFU_INT_TYPE, { .int_type = 20 } };

    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_map_insert(map, key1, value1));
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_map_insert(map, key2, value2));

    // Check if the size is correct
    TEST_ASSUME_EQUAL_UINT(2, fossil_map_size(map));

    fossil_map_erase(map);
}

FOSSIL_TEST(test_map_remove) {
    cmap* map = fossil_map_create(TOFU_INT_TYPE);

    // Insert some key-value pairs
    fossil_tofu_t key1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t value1 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t key2 = { TOFU_INT_TYPE, { .int_type = 5 } };
    fossil_tofu_t value2 = { TOFU_INT_TYPE, { .int_type = 20 } };

    fossil_map_insert(map, key1, value1);
    fossil_map_insert(map, key2, value2);

    // Remove a key-value pair
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_map_remove(map, key1));

    // Check if the size is correct
    TEST_ASSUME_EQUAL_UINT(1, fossil_map_size(map));

    fossil_map_erase(map);
}

FOSSIL_TEST(test_map_getter_and_setter) {
    cmap* map = fossil_map_create(TOFU_INT_TYPE);

    // Insert a key-value pair
    fossil_tofu_t key = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t value = { TOFU_INT_TYPE, { .int_type = 10 } };

    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_map_insert(map, key, value));

    // Get the value for a key
    fossil_tofu_t retrievedValue;
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_map_getter(map, key, &retrievedValue));

    // Check if the retrieved value is correct
    ASSUME_ITS_EQUAL_I32(10, retrievedValue.data.int_type);

    // Update the value for a key
    fossil_tofu_t updatedValue = { TOFU_INT_TYPE, { .int_type = 50 } };
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_map_setter(map, key, updatedValue));

    // Get the updated value for the key
    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_map_getter(map, key, &retrievedValue));

    // Check if the retrieved value is correct after update
    ASSUME_ITS_EQUAL_I32(50, retrievedValue.data.int_type);

    fossil_map_erase(map);
}

FOSSIL_TEST(test_map_contains) {
    cmap* map = fossil_map_create(TOFU_INT_TYPE);

    // Insert a key-value pair
    fossil_tofu_t key = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t value = { TOFU_INT_TYPE, { .int_type = 10 } };

    TEST_ASSUME_EQUAL(FOSSIL_TOFU_ERROR_OK, fossil_map_insert(map, key, value));

    // Check if the map contains the key
    TEST_ASSUME_TRUE(fossil_map_contains(map, key));

    // Check for a non-existing key
    fossil_tofu_t nonExistingKey = { TOFU_INT_TYPE, { .int_type = 100 } };
    TEST_ASSUME_FALSE(fossil_map_contains(map, nonExistingKey));

    fossil_map_erase(map);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_map_group) {
    ADD_TEST(test_map_create_and_erase);
    ADD_TEST(test_map_insert_and_size);
    ADD_TEST(test_map_remove);
    ADD_TEST(test_map_getter_and_setter);
    ADD_TEST(test_map_contains);
} // end of func
