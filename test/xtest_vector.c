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
#include "fossil/xstructures/vector.h" // lib source code

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

XTEST(test_vector_create_and_erase) {
    cvector vector = fossil_vector_create(TOFU_INT_TYPE);
    
    // Check if the vector is created with the expected values
    TEST_ASSUME_EQUAL(TOFU_INT_TYPE, vector.expected_type);
    TEST_ASSUME_CNULLPTR(vector.data);
    TEST_ASSUME_EQUAL_UINT(0, vector.size);
    TEST_ASSUME_EQUAL_UINT(INITIAL_CAPACITY, vector.capacity);

    fossil_vector_erase(&vector);

    // Check if the vector is erased
    TEST_ASSUME_CNULLPTR(vector.data);
    TEST_ASSUME_EQUAL_UINT(0, vector.size);
    TEST_ASSUME_EQUAL_UINT(0, vector.capacity);
}

XTEST(test_vector_push_back) {
    cvector vector = fossil_vector_create(TOFU_INT_TYPE);

    // Push back some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_vector_push_back(&vector, element1);
    fossil_vector_push_back(&vector, element2);
    fossil_vector_push_back(&vector, element3);

    // Check if the elements are added correctly
    TEST_ASSUME_EQUAL_UINT(3, vector.size);
    TEST_ASSUME_EQUAL_INT(42, vector.data[0].data.int_type);
    TEST_ASSUME_EQUAL_INT(10, vector.data[1].data.int_type);
    TEST_ASSUME_EQUAL_INT(5, vector.data[2].data.int_type);

    fossil_vector_erase(&vector);
}

XTEST(test_vector_search) {
    cvector vector = fossil_vector_create(TOFU_INT_TYPE);

    // Push back some elements
    fossil_tofu_t element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    fossil_tofu_t element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    fossil_tofu_t element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fossil_vector_push_back(&vector, element1);
    fossil_vector_push_back(&vector, element2);
    fossil_vector_push_back(&vector, element3);

    // Search for elements
    TEST_ASSUME_EQUAL_INT(0, fossil_vector_search(&vector, element1));
    TEST_ASSUME_EQUAL_INT(1, fossil_vector_search(&vector, element2));
    TEST_ASSUME_EQUAL_INT(2, fossil_vector_search(&vector, element3));

    // Search for non-existing element
    fossil_tofu_t nonExistingElement = { TOFU_INT_TYPE, { .int_type = 100 } };
    TEST_ASSUME_EQUAL_INT(-1, fossil_vector_search(&vector, nonExistingElement));

    fossil_vector_erase(&vector);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(test_vector_group) {
    XTEST_RUN_UNIT(test_vector_create_and_erase);
    XTEST_RUN_UNIT(test_vector_push_back);
    XTEST_RUN_UNIT(test_vector_search);
} // end of func
