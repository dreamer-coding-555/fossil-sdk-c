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
#include "fossil/structures/vector.h" // lib source code

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

FOSSIL_TEST(test_vector_create_and_erase) {
    fossil_vector_t vector = fossil_vector_create(TOFU_INT_TYPE);
    
    // Check if the vector is created with the expected values
    ASSUME_ITS_EQUAL_I32(TOFU_INT_TYPE, vector.expected_type);
    ASSUME_ITS_CNULL(vector.data);
    ASSUME_ITS_EQUAL_U32(0, vector.size);
    ASSUME_ITS_EQUAL_U32(INITIAL_CAPACITY, vector.capacity);

    fossil_vector_erase(&vector);

    // Check if the vector is erased
    ASSUME_ITS_CNULL(vector.data);
    ASSUME_ITS_EQUAL_U32(0, vector.size);
    ASSUME_ITS_EQUAL_U32(0, vector.capacity);
}

FOSSIL_TEST(test_vector_push_back) {
    fossil_vector_t vector = fossil_vector_create(TOFU_INT_TYPE);

    // Push back some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_vector_push_back(&vector, element1);
    fossil_vector_push_back(&vector, element2);
    fossil_vector_push_back(&vector, element3);

    // Check if the elements are added correctly
    ASSUME_ITS_EQUAL_U32(3, vector.size);
    ASSUME_ITS_EQUAL_I32(42, vector.data[0].data.int_type);
    ASSUME_ITS_EQUAL_I32(10, vector.data[1].data.int_type);
    ASSUME_ITS_EQUAL_I32(5, vector.data[2].data.int_type);

    fossil_vector_erase(&vector);
}

FOSSIL_TEST(test_vector_search) {
    fossil_vector_t vector = fossil_vector_create(TOFU_INT_TYPE);

    // Push back some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_vector_push_back(&vector, element1);
    fossil_vector_push_back(&vector, element2);
    fossil_vector_push_back(&vector, element3);

    // Search for elements
    ASSUME_ITS_EQUAL_I32(0, fossil_vector_search(&vector, element1));
    ASSUME_ITS_EQUAL_I32(1, fossil_vector_search(&vector, element2));
    ASSUME_ITS_EQUAL_I32(2, fossil_vector_search(&vector, element3));

    // Search for non-existing element
    fossil_tofu_t nonExistingElement = { TOFU_INT_TYPE, { .int_type = 100 } };
    ASSUME_ITS_EQUAL_I32(-1, fossil_vector_search(&vector, nonExistingElement));

    fossil_vector_erase(&vector);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_vector_group) {
    ADD_TEST(test_vector_create_and_erase);
    ADD_TEST(test_vector_push_back);
    ADD_TEST(test_vector_search);
} // end of func
