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
#include <fossil/core/bluecrab.h>
#include "fossil/common/common.h" // for cnull

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xmock.h>   // basic mock tools
#include <fossil/xassume.h> // extra asserts

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(fossil_crabdb_t_fixture);
fossil_crabdb_t* db;

FOSSIL_SETUP(fossil_crabdb_t_fixture) {
    db = fossil_crabdb_create("test_db");
}

FOSSIL_TEARDOWN(fossil_crabdb_t_fixture) {
    fossil_crabdb_erase(db);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(test_fossil_crabdb_t_create_namespace) {
    ASSUME_NOT_CNULL(db);
    const char* namespace_name = "test_namespace";
    int32_t result = fossil_crabdb_create_namespace(db, namespace_name);
    ASSUME_ITS_EQUAL_I32(1, result);
}

FOSSIL_TEST(test_fossil_crabdb_t_insert_data) {
    ASSUME_NOT_CNULL(db);
    const char* namespace_name = "test_namespace";
    int32_t result = fossil_crabdb_insert_data(db, namespace_name, "key1", "value1", "str");
    ASSUME_ITS_EQUAL_I32(1, result);
}

FOSSIL_TEST(test_fossil_crabdb_t_update_data) {
    ASSUME_NOT_CNULL(db);
    const char* namespace_name = "test_namespace";
    fossil_crabdb_insert_data(db, namespace_name, "key1", "value1", "str");
    int32_t result = fossil_crabdb_update_data(db, namespace_name, "key1", "new_value1");
    ASSUME_ITS_EQUAL_I32(1, result);
}

FOSSIL_TEST(test_fossil_crabdb_t_execute_query) {
    ASSUME_NOT_CNULL(db);
    const char* namespace_name = "test_namespace";
    int32_t result = fossil_crabdb_create_namespace(db, namespace_name);
    ASSUME_ITS_EQUAL_I32(1, result);
    
    // Execute a query
    fossil_crabdb_execute_query(db, "insert_data('test_namespace', key: 'key1', value: 'value1', type: 'str')");
    
    // Search for the inserted data
    fson_value* data = fossil_crabdb_search_data(db, namespace_name, "key1");
    ASSUME_NOT_CNULL(data);
    ASSUME_ITS_EQUAL_CSTR("value1", data->value);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(test_fossil_crabdb_t_group) {
    ADD_TESTF(test_fossil_crabdb_t_create_namespace, fossil_crabdb_t_fixture);
    ADD_TESTF(test_fossil_crabdb_t_insert_data,      fossil_crabdb_t_fixture);
    ADD_TESTF(test_fossil_crabdb_t_update_data,      fossil_crabdb_t_fixture);
    ADD_TESTF(test_fossil_crabdb_t_execute_query,    fossil_crabdb_t_fixture);
} // end of function main
