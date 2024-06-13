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
#include <fossil/stdio/fstream.h> // library under test

#include <fossil/unittest.h>   // basic test tools
#include <fossil/xassume.h> // extra asserts
#include <fossil/mockup/file.h>

#include <fossil/common.h>  // common utilities
#include <fossil/status.h>  // status codes

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Utilites
// * * * * * * * * * * * * * * * * * * * * * * * *
// Setup steps for things like test fixtures and
// mock objects are set here.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_DATA(StreamTestData) {
    mockup_file_t *mock_file;
    fossil_fstream_t stream;
} io;

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Cases
// * * * * * * * * * * * * * * * * * * * * * * * *
// The test cases below are provided as samples, inspired
// by the Meson build system's approach of using test cases
// as samples for library usage.
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST(stream_let_open_and_close_file) {
    io.mock_file = mockup_file_create("testfile.txt", "");
    ASSUME_ITS_EQUAL_I32(0, fossil_fstream_open(&io.stream, io.mock_file->filename, "w"));
    ASSUME_NOT_CNULL(io.stream.file);
    fossil_fstream_close(&io.stream);
    ASSUME_ITS_CNULL(io.stream.file);
    mockup_file_erase(io.mock_file);
}

FOSSIL_TEST(stream_let_write_and_read_file) {
    const char *filename = "testfile.txt";
    const char *content = "This is a test.";
    io.mock_file = mockup_file_create(filename, "");

    // Write data to the file
    ASSUME_ITS_EQUAL_I32(0, fossil_fstream_open(&io.stream, filename, "w"));
    fossil_fstream_write(&io.stream, content, strlen(content), 1);
    fossil_fstream_close(&io.stream);

    // Read data from the file
    char buffer[1024];
    ASSUME_ITS_EQUAL_I32(0, fossil_fstream_open(&io.stream, filename, "r"));
    fossil_fstream_read(&io.stream, buffer, sizeof(buffer), 1);
    fossil_fstream_close(&io.stream);
    ASSUME_ITS_EQUAL_CSTR(content, buffer);

    mockup_file_erase(io.mock_file);
}

FOSSIL_TEST(stream_let_append_file) {
    const char *filename = "testfile.txt";
    char *content1 = "This is content1.";
    char *content2 = "This is content2.";
    io.mock_file = mockup_file_create(filename, "");

    // Append data to the file
    ASSUME_ITS_EQUAL_I32(0, fossil_fstream_open(&io.stream, filename, "w"));
    size_t bytes_written1 = fossil_fstream_write(&io.stream, content1, strlen(content1), 1);
    fossil_fstream_close(&io.stream);
    ASSUME_ITS_EQUAL_I32(strlen(content1), bytes_written1);

    ASSUME_ITS_EQUAL_I32(0, fossil_fstream_open(&io.stream, filename, "a"));
    size_t bytes_written2 = fossil_fstream_write(&io.stream, content2, strlen(content2), 1);
    fossil_fstream_close(&io.stream);
    ASSUME_ITS_EQUAL_I32(strlen(content2), bytes_written2);

    // Read data from the file and verify content
    char buffer[1024];
    ASSUME_ITS_EQUAL_I32(0, fossil_fstream_open(&io.stream, filename, "r"));
    size_t bytes_read = fossil_fstream_read(&io.stream, buffer, sizeof(buffer), 1);
    fossil_fstream_close(&io.stream);
    ASSUME_ITS_EQUAL_I32(strlen(content1) + strlen(content2), bytes_read);

    // Combine both contents and verify
    strcat(content1, content2);
    ASSUME_ITS_EQUAL_CSTR(content1, buffer);

    mockup_file_erase(io.mock_file);
}

FOSSIL_TEST(stream_let_save_and_reopen_file) {
    const char *filename = "testfile.txt";
    const char *new_filename = "newfile.txt";
    const char *content = "This is a test.";
    io.mock_file = mockup_file_create(filename, "");

    // Write data to the file
    ASSUME_ITS_EQUAL_I32(0, fossil_fstream_open(&io.stream, filename, "w"));
    size_t bytes_written = fossil_fstream_write(&io.stream, content, strlen(content), 1);
    fossil_fstream_close(&io.stream);
    ASSUME_ITS_EQUAL_I32(strlen(content), bytes_written);

    // Save the file with a new name
    ASSUME_ITS_EQUAL_I32(0, fossil_fstream_save(&io.stream, new_filename));

    // Read data from the new file and verify content
    char buffer[1024];
    ASSUME_ITS_EQUAL_I32(0, fossil_fstream_open(&io.stream, new_filename, "r"));
    size_t bytes_read = fossil_fstream_read(&io.stream, buffer, sizeof(buffer), 1);
    fossil_fstream_close(&io.stream);
    ASSUME_ITS_EQUAL_I32(strlen(content), bytes_read);
    ASSUME_ITS_EQUAL_CSTR(content, buffer);

    mockup_file_erase(io.mock_file);
}

FOSSIL_TEST(stream_let_seek_within_file) {
    const char *filename = "testfile.txt";
    const char *content = "This is a test.";
    io.mock_file = mockup_file_create(filename, "");

    // Write data to the file
    ASSUME_ITS_EQUAL_I32(0, fossil_fstream_open(&io.stream, filename, "w"));
    size_t bytes_written = fossil_fstream_write(&io.stream, content, strlen(content), 1);
    fossil_fstream_close(&io.stream);
    ASSUME_ITS_EQUAL_I32(strlen(content), bytes_written);

    // Seek to a specific position within the file and verify
    ASSUME_ITS_EQUAL_I32(0, fossil_fstream_open(&io.stream, filename, "r"));
    ASSUME_ITS_EQUAL_I32(0, fossil_fstream_seek(&io.stream, 5, SEEK_SET)); // Seek to the 5th byte
    char buffer[1024];
    size_t bytes_read = fossil_fstream_read(&io.stream, buffer, sizeof(buffer), 1);
    fossil_fstream_close(&io.stream);
    ASSUME_ITS_EQUAL_I32(strlen(content) - 5, bytes_read); // Check remaining content after seeking
    ASSUME_ITS_EQUAL_CSTR(content + 5, buffer); // Verify content after seeking

    mockup_file_erase(io.mock_file);
}

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Pool
// * * * * * * * * * * * * * * * * * * * * * * * *
FOSSIL_TEST_GROUP(fossil_logic_fossil_fstream_t_cases) {
    ADD_TEST(stream_let_open_and_close_file);
    ADD_TEST(stream_let_write_and_read_file);
    ADD_TEST(stream_let_append_file);
    ADD_TEST(stream_let_save_and_reopen_file);
    ADD_TEST(stream_let_seek_within_file);
}
