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
#include "fossil/strings/strstream.h"
#include "fossil/common/common.h"
#include "fossil/strings/manip.h"
#include <stdlib.h>
#include <string.h>

// Read a substring of length 'len' from the string starting at position 'pos'
cstring fossil_cstrstream_read(const_cstring str, size_t *pos, size_t len) {
    if (!str || *pos >= strlen(str) || len == 0) {
        return cnullptr; // Invalid input or end of string reached, or zero length
    }
    cstring buffer = fossil_cstr_substr(str + *pos, 0, len);
    if (!buffer) {
        return cnullptr; // Memory allocation failure
    }
    *pos += strlen(buffer); // Move position by the length of the read substring
    return buffer;
}

// Read a line from the string starting at position 'pos' and update 'end_pos'
cstring fossil_cstrstream_read_line(const_cstring str, size_t *pos, size_t *end_pos) {
    if (!str || *pos >= strlen(str) || !end_pos) {
        return cnullptr; // Invalid input or end of string reached
    }
    size_t start = *pos;
    while (str[*pos] && str[*pos] != '\n') {
        (*pos)++;
    }
    cstring buffer = fossil_cstr_substr(str, start, *pos - start);
    if (!buffer) {
        return cnullptr; // Memory allocation failure
    }
    if (str[*pos] == '\n') {
        (*pos)++;
    }
    *end_pos = *pos;
    return buffer;
}

// Write the source string to the destination starting at position 'pos'
void fossil_cstrstream_write(cstring dest, size_t *pos, const_cstring src) {
    if (!dest || !src) {
        return; // Invalid input
    }
    size_t destLen = strlen(dest);
    size_t srcLen = strlen(src);
    if (*pos + srcLen >= destLen) {
        return; // Writing would exceed buffer size
    }
    fossil_cstr_copy(dest + *pos, src); // Copy source string to destination buffer
    *pos += srcLen; // Move position by the length of the written substring
}

// Append the source string to the destination starting at position 'pos'
void fossil_cstrstream_append(cstring dest, size_t *pos, const_cstring src) {
    if (!dest || !src) {
        return; // Invalid input
    }
    size_t srcLen = strlen(src);
    dest = realloc(dest, *pos + srcLen + 1);
    if (!dest) {
        return; // Memory allocation failure
    }
    fossil_cstr_copy(dest + *pos, src); // Copy source string to destination buffer
    *pos += srcLen; // Move position by the length of the appended substring
    dest[*pos] = cterminator; // Null-terminate the destination buffer
}

// Set the stream position to 'offset'
void fossil_cstrstream_seek(size_t *pos, size_t offset) {
    *pos = offset;
}

// Return the current stream position
size_t fossil_cstrstream_tell(const_cstring str, size_t pos) {
    // Ensure the string is not NULL
    if (str == cnullptr) {
        // Handle the error, e.g., by returning a special value or by using an assertion
        return (size_t)-1;
    }

    // Get the length of the string
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }

    // Check if pos is within the string bounds
    if (pos >= length) {
        // Handle the error, e.g., by returning a special value or by using an assertion
        return (size_t)-1;
    }
    return pos;
}

//
// Byte string stream functions
//

// Read a substring of length 'len' from the string starting at position 'pos'
bstring fossil_bstrstream_read(const_bstring str, size_t *pos, size_t len) {
    if (!str || *pos >= fossil_bstr_length(str) || len == 0) {
        return cnullptr; // Invalid input or end of string reached, or zero length
    }
    bstring buffer = fossil_bstr_substr(str, *pos, len);
    if (!buffer) {
        return cnullptr; // Memory allocation failure
    }
    *pos += fossil_bstr_length(buffer); // Move position by the length of the read substring
    return buffer;
}

// Read a line from the string starting at position 'pos' and update 'end_pos'
bstring fossil_bstrstream_read_line(const_bstring str, size_t *pos, size_t *end_pos) {
    if (!str || *pos >= fossil_bstr_length(str) || !end_pos) {
        return cnullptr; // Invalid input or end of string reached
    }
    size_t start = *pos;
    while (*pos < fossil_bstr_length(str) && fossil_bletter_at(str, *pos) != '\n') {
        (*pos)++;
    }
    bstring buffer = fossil_bstr_substr(str, start, *pos - start);
    if (!buffer) {
        return cnullptr; // Memory allocation failure
    }
    if (*pos < fossil_bstr_length(str) && fossil_bletter_at(str, *pos) == '\n') {
        (*pos)++;
    }
    *end_pos = *pos;
    return buffer;
}

// Write the source string to the destination starting at position 'pos'
void fossil_bstrstream_write(bstring dest, size_t *pos, const_bstring src) {
    if (!dest || !src) {
        return; // Invalid input
    }
    size_t destLen = fossil_bstr_length(dest);
    size_t srcLen = fossil_bstr_length(src);
    if (*pos + srcLen >= destLen) {
        return; // Writing would exceed buffer size
    }
    fossil_bstr_copy(dest + *pos, src); // Copy source string to destination buffer
    *pos += srcLen; // Move position by the length of the written substring
}

// Append the source string to the destination starting at position 'pos'
void fossil_bstrstream_append(bstring dest, size_t *pos, const_bstring src) {
    if (!dest || !src) {
        return; // Invalid input
    }
    size_t srcLen = fossil_bstr_length(src);
    fossil_bstr_copy(dest + *pos, src); // Copy source string to destination at specified position
    *pos += srcLen; // Move position by the length of the appended substring
}

// Set the stream position to 'offset'
void fossil_bstrstream_seek(size_t *pos, size_t offset) {
    *pos = offset;
}

// Return the current stream position
size_t fossil_bstrstream_tell(const_bstring str, size_t pos) {
    // Ensure the string is not NULL
    if (str == cnullptr) {
        // Handle the error, e.g., by returning a special value or by using an assertion
        return (size_t)-1;
    }

    // Get the length of the string
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }

    // Check if pos is within the string bounds
    if (pos >= length) {
        // Handle the error, e.g., by returning a special value or by using an assertion
        return (size_t)-1;
    }
    return pos;
}

//
// Wisiwig string stream functions
//

// Read a substring of length 'len' from the string starting at position 'pos'
wstring fossil_wstrstream_read(const_wstring str, size_t *pos, size_t len) {
    if (!str || *pos >= fossil_wstr_length(str) || len == 0) {
        return cnullptr; // Invalid input or end of string reached, or zero length
    }
    wstring buffer = fossil_wstr_substr(str, *pos, len);
    if (!buffer) {
        return cnullptr; // Memory allocation failure
    }
    *pos += fossil_wstr_length(buffer); // Move position by the length of the read substring
    return buffer;
}

// Read a line from the string starting at position 'pos' and update 'end_pos'
wstring fossil_wstrstream_read_line(const_wstring str, size_t *pos, size_t *end_pos) {
    if (!str || *pos >= fossil_wstr_length(str) || !end_pos) {
        return cnullptr; // Invalid input or end of string reached
    }
    size_t start = *pos;
    while (*pos < fossil_wstr_length(str) && fossil_wletter_at(str, *pos) != L'\n') {
        (*pos)++;
    }
    wstring buffer = fossil_wstr_substr(str, start, *pos - start);
    if (!buffer) {
        return cnullptr; // Memory allocation failure
    }
    if (*pos < fossil_wstr_length(str) && fossil_wletter_at(str, *pos) == L'\n') {
        (*pos)++;
    }
    *end_pos = *pos;
    return buffer;
}

// Write the source string to the destination starting at position 'pos'
void fossil_wstrstream_write(wstring dest, size_t *pos, const_wstring src) {
    if (!dest || !src) {
        return; // Invalid input
    }
    size_t destLen = fossil_wstr_length(dest);
    size_t srcLen = fossil_wstr_length(src);
    if (*pos + srcLen >= destLen) {
        return; // Writing would exceed buffer size
    }
    fossil_wstr_copy(dest + *pos, src); // Copy source string to destination buffer
    *pos += srcLen; // Move position by the length of the written substring
}

// Append the source string to the destination starting at position 'pos'
void fossil_wstrstream_append(wstring dest, size_t *pos, const_wstring src) {
    if (!dest || !src) {
        return; // Invalid input
    }
    size_t srcLen = fossil_wstr_length(src);
    fossil_wstr_copy(dest + *pos, src); // Copy source string to destination at specified position
    *pos += srcLen; // Move position by the length of the appended substring
}

// Set the stream position to 'offset'
void fossil_wstrstream_seek(size_t *pos, size_t offset) {
    *pos = offset;
}

// Return the current stream position
size_t fossil_wstrstream_tell(const_wstring str, size_t pos) {
    // Ensure the string is not NULL
    if (str == cnullptr) {
        // Handle the error, e.g., by returning a special value or by using an assertion
        return (size_t)-1;
    }

    // Get the length of the wide string
    size_t length = 0;
    while (str[length] != L'\0') {
        length++;
    }

    // Check if pos is within the string bounds
    if (pos >= length) {
        // Handle the error, e.g., by returning a special value or by using an assertion
        return (size_t)-1;
    }
    return pos;
}
