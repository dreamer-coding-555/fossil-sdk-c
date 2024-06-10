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

// Test case 1: Test fossil_sem_create with a valid initial value
XTEST(test_fossil_sem_create_valid_value) {
    xsem_t sem;
    TEST_ASSUME_EQUAL_INT32(0, fossil_sem_create(&sem, 5));
}

// Test case 2: Test fossil_sem_erase after creation
XTEST(test_fossil_sem_erase_after_create) {
    xsem_t sem;
    fossil_sem_create(&sem, 5); // Initialize the semaphore before erasing it
    TEST_ASSUME_EQUAL_INT32(0, fossil_sem_erase(&sem));
}

// Test case 3: Test fossil_sem_wait with valid parameters
XTEST(test_fossil_sem_wait_valid_params) {
    xsem_t sem;
    fossil_sem_create(&sem, 1);
    TEST_ASSUME_EQUAL_INT32(0, fossil_sem_wait(&sem));
}

// Test case 4: Test fossil_sem_post with valid parameters
XTEST(test_fossil_sem_post_valid_params) {
    xsem_t sem;
    fossil_sem_create(&sem, 0);
    TEST_ASSUME_EQUAL_INT32(0, fossil_sem_post(&sem));
}

// Test case 5: Test fossil_sem_trywait with valid parameters
XTEST(test_fossil_sem_trywait_valid_params) {
    xsem_t sem;
    fossil_sem_create(&sem, 1);
    TEST_ASSUME_EQUAL_INT32(0, fossil_sem_trywait(&sem));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(sem_group) {
    XTEST_RUN_UNIT(test_fossil_sem_create_valid_value);
    XTEST_RUN_UNIT(test_fossil_sem_erase_after_create);
    XTEST_RUN_UNIT(test_fossil_sem_wait_valid_params);
    XTEST_RUN_UNIT(test_fossil_sem_post_valid_params);
    XTEST_RUN_UNIT(test_fossil_sem_trywait_valid_params);
} // end of fixture
