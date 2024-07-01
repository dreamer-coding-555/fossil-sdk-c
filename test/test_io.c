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
#include <fossil/io/fstream.h>
#include <fossil/io/istream.h>
#include <fossil/io/ostream.h>
#include <fossil/io/soap.h>

#include <fossil/unittest.h> // basic test tools
#include <fossil/xassume.h>  // extra asserts
#include <fossil/mockup/file.h>

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilities
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test classic string
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(io_file_fixture);
FOSSIL_TEST_DATA(StreamTestData) {
    fossil_mockup_file_t *mock_file;
    fossil_fstream_t stream;
} io;

FOSSIL_SETUP(io_file_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(io_file_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(stream_let_open_and_close_file) {
    io.mock_file = fossil_mockup_file_create("testfile.txt", "");
    ASSUME_ITS_EQUAL_I32(0, fossil_fstream_open(&io.stream, io.mock_file->filename, "w"));
    ASSUME_NOT_CNULL(io.stream.file);
    fossil_fstream_close(&io.stream);
    ASSUME_ITS_CNULL(io.stream.file);
    fossil_mockup_file_erase(io.mock_file);
}

FOSSIL_TEST(stream_let_write_and_read_file) {
    const char *filename = "testfile.txt";
    const char *content = "This is a test.";
    io.mock_file = fossil_mockup_file_create(filename, "");

    // Write data to the file
    ASSUME_ITS_EQUAL_I32(0, fossil_fstream_open(&io.stream, filename, "w"));
    fossil_fstream_write(&io.stream, content, strlen(content), 1);
    fossil_fstream_close(&io.stream);

    // Read data from the file
    char buffer[1024];
    ASSUME_ITS_EQUAL_I32(0, fossil_fstream_open(&io.stream, filename, "r"));
    fossil_fstream_read(&io.stream, buffer, sizeof(buffer), 1);
    fossil_fstream_close(&io.stream);
    // ASSUME_ITS_EQUAL_CSTR(content, buffer); make issue ticket for Fossil Mock io issues

    fossil_mockup_file_erase(io.mock_file);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test byte string
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_FIXTURE(io_soap_fixture);
FOSSIL_SETUP(io_soap_fixture) {
    // Setup code if needed
}

FOSSIL_TEARDOWN(io_soap_fixture) {
    // Teardown code if needed
}

FOSSIL_TEST(test_fossil_soap_sanitize) {
    char input[] = "This is a test with curse1 and racist_phrase1.";
    char expected[] = "This is a test with *** and ***.";

    fossil_soap_sanitize(input);

    ASSUME_ITS_EQUAL_CSTR(expected, input);
}

FOSSIL_TEST(test_fossil_soap_is_offensive) {
    ASSUME_ITS_TRUE(fossil_soap_is_offensive("curse1"));
    ASSUME_ITS_TRUE(fossil_soap_is_offensive("racist_phrase2"));
    ASSUME_ITS_FALSE(fossil_soap_is_offensive("non_offensive_word"));
}

FOSSIL_TEST(test_fossil_soap_count_offensive) {
    char input[] = "This is a test with curse1 and racist_phrase1";
    ASSUME_ITS_EQUAL_I32(2, fossil_soap_count_offensive(input));
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_GROUP(c_iostream_tests) {    
    // IO File Fixture
    ADD_TESTF(stream_let_open_and_close_file, io_file_fixture);
    ADD_TESTF(stream_let_write_and_read_file, io_file_fixture);

    // Soap Fixture
    ADD_TESTF(test_fossil_soap_sanitize, io_soap_fixture);
    ADD_TESTF(test_fossil_soap_is_offensive, io_soap_fixture);
    ADD_TESTF(test_fossil_soap_count_offensive, io_soap_fixture);
} // end of tests
