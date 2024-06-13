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
#include "fossil/stdtool/filesystem.h" // lib source code

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

// Test case for initializing error with a message
XTEST(test_fossil_filesys_create) {
    fossil_filesystem_t dir = fossil_filesys_create("path\\to\\directory");
    ASSUME_NOT_CNULL(dir.path);
    ASSUME_ITS_TRUE(fossil_filesys_exists(&dir));
    fossil_filesys_erase(&dir);
}

XTEST(test_fossil_filesys_list_files) {
    fossil_filesystem_t dir = fossil_filesys_create("path\\to\\directory");
    // You may want to redirect stdout to capture the printed output for testing
    // Redirecting output in C is platform-dependent, so it's not included here.
    fossil_filesys_list_files(&dir);
    // Add assertions based on the expected output
    fossil_filesys_erase(&dir);
}

XTEST(test_fossil_filesys_create_subdirectory) {
    fossil_filesystem_t parentDirectory = fossil_filesys_create("path\\to\\parent");
    fossil_filesys_create_subdirectory(&parentDirectory, "new_subdirectory");
    ASSUME_ITS_TRUE(fossil_filesys_exists(&parentDirectory));
    fossil_filesystem_t subDirectory = fossil_filesys_create("path\\to\\parent\\new_subdirectory");
    ASSUME_ITS_TRUE(fossil_filesys_exists(&subDirectory));
    fossil_filesys_erase(&parentDirectory);
    fossil_filesys_erase(&subDirectory);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
XTEST_DEFINE_POOL(test_filesystem_group) {
    ADD_TEST(test_fossil_filesys_create);
    ADD_TEST(test_fossil_filesys_list_files);
    ADD_TEST(test_fossil_filesys_create_subdirectory);
} // end of function main
