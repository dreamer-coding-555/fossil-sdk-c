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
#include <fossil/threads/semaphores.h> // library under test

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

// Test case 1: Test fossil_sem_create with a valid initial value
FOSSIL_TEST(test_fossil_sem_create_valid_value) {
    fossil_xsem_t sem;
    ASSUME_ITS_EQUAL_I32(0, fossil_sem_create(&sem, 5));
}

// Test case 2: Test fossil_sem_erase after creation
FOSSIL_TEST(test_fossil_sem_erase_after_create) {
    fossil_xsem_t sem;
    fossil_sem_create(&sem, 5); // Initialize the semaphore before erasing it
    ASSUME_ITS_EQUAL_I32(0, fossil_sem_erase(&sem));
}

// Test case 3: Test fossil_sem_wait with valid parameters
FOSSIL_TEST(test_fossil_sem_wait_valid_params) {
    fossil_xsem_t sem;
    fossil_sem_create(&sem, 1);
    ASSUME_ITS_EQUAL_I32(0, fossil_sem_wait(&sem));
}

// Test case 4: Test fossil_sem_post with valid parameters
FOSSIL_TEST(test_fossil_sem_post_valid_params) {
    fossil_xsem_t sem;
    fossil_sem_create(&sem, 0);
    ASSUME_ITS_EQUAL_I32(0, fossil_sem_post(&sem));
}

// Test case 5: Test fossil_sem_trywait with valid parameters
FOSSIL_TEST(test_fossil_sem_trywait_valid_params) {
    fossil_xsem_t sem;
    fossil_sem_create(&sem, 1);
    ASSUME_ITS_EQUAL_I32(0, fossil_sem_trywait(&sem));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(sem_group) {
    ADD_TEST(test_fossil_sem_create_valid_value);
    ADD_TEST(test_fossil_sem_erase_after_create);
    ADD_TEST(test_fossil_sem_wait_valid_params);
    ADD_TEST(test_fossil_sem_post_valid_params);
    ADD_TEST(test_fossil_sem_trywait_valid_params);
} // end of fixture
