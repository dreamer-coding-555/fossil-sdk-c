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
#include <fossil/threads/threadpool.h> // library under test

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

// Test case 1: Test fossil_thread_pool_create with valid parameters
XTEST(test_fossil_thread_pool_create_valid_params) {
    xthread_pool_t pool;
    TEST_ASSUME_EQUAL_INT32(0, fossil_thread_pool_create(&pool, 4, 10));
}

// Test case 2: Test fossil_thread_pool_erase with valid parameters
XTEST(test_fossil_thread_pool_erase_valid_params) {
    xthread_pool_t pool;
    fossil_thread_pool_create(&pool, 4, 10); // Create a thread pool before erasing it
    TEST_ASSUME_EQUAL_INT32(0, fossil_thread_pool_erase(&pool));
}

// Test case 3: Test fossil_thread_pool_add_task with valid parameters
XTEST(test_fossil_thread_pool_add_task_valid_params) {
    xthread_pool_t pool;
    fossil_thread_pool_create(&pool, 4, 10); // Create a thread pool before adding tasks to it
    TEST_ASSUME_EQUAL_INT32(0, fossil_thread_pool_add_task(&pool, NULL, NULL));
}

// Test case 4: Test fossil_thread_pool_add_task with full task queue
XTEST(test_fossil_thread_pool_add_task_full_queue) {
    xthread_pool_t pool;
    fossil_thread_pool_create(&pool, 4, 1); // Create a thread pool with a queue size of 1
    fossil_thread_pool_add_task(&pool, NULL, NULL); // Fill the task queue
    TEST_ASSUME_EQUAL_INT32(-1, fossil_thread_pool_add_task(&pool, NULL, NULL)); // Attempt to add another task
}

// Test case 5: Test fossil_thread_pool_add_task with NULL task function
XTEST(test_fossil_thread_pool_add_task_null_task) {
    xthread_pool_t pool;
    fossil_thread_pool_create(&pool, 4, 10); // Create a thread pool before adding tasks to it
    TEST_ASSUME_EQUAL_INT32(-1, fossil_thread_pool_add_task(&pool, NULL, NULL));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(poolthreads_group) {
    XTEST_RUN_UNIT(test_fossil_thread_pool_create_valid_params);
    XTEST_RUN_UNIT(test_fossil_thread_pool_erase_valid_params);
    XTEST_RUN_UNIT(test_fossil_thread_pool_add_task_valid_params);
    XTEST_RUN_UNIT(test_fossil_thread_pool_add_task_full_queue);
    XTEST_RUN_UNIT(test_fossil_thread_pool_add_task_null_task);
} // end of fixture
