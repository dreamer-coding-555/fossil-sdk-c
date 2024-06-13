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
#ifndef FOSSIL_STR_STRSTREAM_H
#define FOSSIL_STR_STRSTREAM_H

/**
 * @brief String Stream Functions
 * 
 * This header file contains functions for reading from and writing to string streams.
 * 
 * The functions support classic C strings, byte strings, and wide strings.
 * 
 * Usage:
 * 
 * Example:
 * 
 * @code
 * size_t pos = 0;
 * size_t end_pos;
 * const_cstring str = "This is a test\nSecond line\nThird line\n";
 * 
 * // Read line by line from a classic C string
 * while (pos < strlen(str)) {
 *     cstring line = fossil_cstrstream_read_line(str, &pos, &end_pos);
 *     printf("Line: %s\n", line);
 *     free(line);
 *     pos = end_pos; // Move to the next line
 * }
 * @endcode
 */

#include "bstring.h"
#include "cstring.h"
#include "wstring.h"

#ifdef __cplusplus
extern "C"
{
#endif

// =================================================================
// Available functions
// =================================================================

/**
 * Classic C string stream functions
 */

/**
 * Read a substring from the given classic C string 'str'.
 * 
 * Reads 'len' characters from 'str' starting at position '*pos'.
 * Returns the read substring and updates '*pos' to the next position.
 */
cstring fossil_cstrstream_read(const_cstring str, size_t *pos, size_t len);

/**
 * Read a line from the given classic C string 'str'.
 * 
 * Reads characters from 'str' starting at position '*pos' until a newline or end of string.
 * Returns the read line and updates '*pos' to the next position after the newline.
 * Updates '*end_pos' to the position of the newline or end of string.
 */
cstring fossil_cstrstream_read_line(const_cstring str, size_t *pos, size_t *end_pos);

/**
 * Write a string to the given classic C string 'dest'.
 * 
 * Writes the string 'src' to 'dest' starting at position '*pos'.
 * Updates '*pos' to the next position after the written string.
 */
void fossil_cstrstream_write(cstring dest, size_t *pos, const_cstring src);

/**
 * Append a string to the given classic C string 'dest'.
 * 
 * Appends the string 'src' to 'dest' starting at position '*pos'.
 * Updates '*pos' to the next position after the appended string.
 */
void fossil_cstrstream_append(cstring dest, size_t *pos, const_cstring src);

/**
 * Seek to a specific position in the classic C string stream.
 * 
 * Sets '*pos' to the specified 'offset'.
 */
void fossil_cstrstream_seek(size_t *pos, size_t offset);

/**
 * Get the current position in the classic C string stream.
 * 
 * Returns the current position '*pos' in the classic C string 'str'.
 */
size_t fossil_cstrstream_tell(const_cstring str, size_t pos);


/**
 * Byte string stream functions
 */

/**
 * Read a substring from the given byte string 'str'.
 * 
 * Reads 'len' bytes from 'str' starting at position '*pos'.
 * Returns the read substring and updates '*pos' to the next position.
 */
bstring fossil_bstrstream_read(const_bstring str, size_t *pos, size_t len);

/**
 * Read a line from the given byte string 'str'.
 * 
 * Reads bytes from 'str' starting at position '*pos' until a newline or end of string.
 * Returns the read line and updates '*pos' to the next position after the newline.
 * Updates '*end_pos' to the position of the newline or end of string.
 */
bstring fossil_bstrstream_read_line(const_bstring str, size_t *pos, size_t *end_pos);

/**
 * Write a byte string to the given byte string 'dest'.
 * 
 * Writes the byte string 'src' to 'dest' starting at position '*pos'.
 * Updates '*pos' to the next position after the written byte string.
 */
void fossil_bstrstream_write(bstring dest, size_t *pos, const_bstring src);

/**
 * Append a byte string to the given byte string 'dest'.
 * 
 * Appends the byte string 'src' to 'dest' starting at position '*pos'.
 * Updates '*pos' to the next position after the appended byte string.
 */
void fossil_bstrstream_append(bstring dest, size_t *pos, const_bstring src);

/**
 * Seek to a specific position in the byte string stream.
 * 
 * Sets '*pos' to the specified 'offset'.
 */
void fossil_bstrstream_seek(size_t *pos, size_t offset);

/**
 * Get the current position in the byte string stream.
 * 
 * Returns the current position '*pos' in the byte string 'str'.
 */
size_t fossil_bstrstream_tell(const_bstring str, size_t pos);

/**
 * Wisiwig string stream functions
 */

/**
 * @brief Read a substring of length 'len' from the wide string starting at position 'pos'.
 * 
 * @param str The wide string to read from.
 * @param pos Pointer to the current position in the string. Updated after reading.
 * @param len Length of the substring to read.
 * @return wstring The substring read from the wide string.
 */
wstring fossil_wstrstream_read(const_wstring str, size_t *pos, size_t len);

/**
 * @brief Read a line from the wide string starting at position 'pos' and update 'end_pos'.
 * 
 * @param str The wide string to read from.
 * @param pos Pointer to the current position in the string. Updated after reading.
 * @param end_pos Pointer to the end position of the read line. Updated after reading.
 * @return wstring The line read from the wide string.
 */
wstring fossil_wstrstream_read_line(const_wstring str, size_t *pos, size_t *end_pos);

/**
 * @brief Write the source wide string to the destination starting at position 'pos'.
 * 
 * @param dest The destination wide string.
 * @param pos Pointer to the current position in the destination string. Updated after writing.
 * @param src The source wide string to write.
 */
void fossil_wstrstream_write(wstring dest, size_t *pos, const_wstring src);

/**
 * @brief Append the source wide string to the destination starting at position 'pos'.
 * 
 * @param dest The destination wide string.
 * @param pos Pointer to the current position in the destination string. Updated after appending.
 * @param src The source wide string to append.
 */
void fossil_wstrstream_append(wstring dest, size_t *pos, const_wstring src);

/**
 * @brief Set the stream position to 'offset'.
 * 
 * @param pos Pointer to the stream position. Updated to 'offset'.
 * @param offset The new stream position.
 */
void fossil_wstrstream_seek(size_t *pos, size_t offset);

/**
 * @brief Return the current stream position.
 * 
 * @param str The wide string.
 * @param pos The current stream position.
 * @return size_t The current stream position.
 */
size_t fossil_wstrstream_tell(const_wstring str, size_t pos);

#ifdef __cplusplus
}
#endif

#endif
