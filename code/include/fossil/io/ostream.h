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
#ifndef FOSSIL_STDIO_OSTREAM_H
#define FOSSIL_STDIO_OSTREAM_H

#include "fossil/common/common.h"

/*
 * fstr - Flexible String Formatter
 *
 * Description:
 * fstr is a versatile string formatting function designed to provide flexible and customizable
 * formatting options for strings in C programs. It supports both traditional C-style format
 * specifiers and custom f-string format specifiers, offering developers a wide range of options
 * for formatting output.
 *
 * Traditional C-style Format Specifiers:
 *   - fstr supports traditional C-style format specifiers, including %d, %i, %u, %x, %X, %o, %f,
 *     %e, %E, %g, %G, %c, %s, %p, etc. These specifiers are similar to those supported by the
 *     standard printf family of functions, providing compatibility with existing codebases.
 *
 * Custom f-string Format Specifiers (f{} Format):
 *   - fstr introduces custom f-string format specifiers in the form of f{type:options}, allowing
 *     for more flexible and customizable formatting compared to traditional formats. Supported
 *     types include:
 *       - Integer Types: i8, i16, i32, i64, u8, u16, u32, u64
 *       - Hexadecimal Types: h8, h16, h32, h64
 *       - Octal Types: o8, o16, o32, o64
 *       - Fixed Point Types: q8, q16, q32, q64
 *       - Other Numeric Types: f32, f64, size
 *       - String Type: str
 *       - Character Type: char
 *       - Pointer Type: ptr
 *   - Supported options include various text attributes and colors, allowing developers to
 *     customize the appearance of the output, such as bold, underline, italic, and different
 *     colors.
 *
 * Usage:
 *   - To use fstr, simply include the appropriate format specifier within a format string passed
 *     to the fstr function. For example:
 *       fstr("f{str:bold:green} %d f{hex:bold} %x\n", 10, 255);
 *
 *   - fstr automatically detects and processes both traditional C-style format specifiers and
 *     custom f-string format specifiers within the same format string, providing seamless
 *     integration and enhanced formatting capabilities.
 *
 * Note: fstr offers a powerful and extensible solution for string formatting needs in C programs,
 *       enabling developers to create visually appealing and informative output with ease.
 */

/*
 * Note: fstr offers the option to use either classic C-style format specifiers or mix both
 * traditional and custom f-string format specifiers within the same format string. This allows
 * developers to leverage the familiar syntax of C-style format specifiers while also taking
 * advantage of the enhanced flexibility and customization offered by f-string format specifiers.
 * By supporting both formats in a single format string, fstr provides developers with the
 * versatility to choose the most suitable formatting approach for their specific needs, whether it
 * be compatibility with existing codebases or the desire for advanced formatting options.
 */

typedef const char * fossil_message_t;

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * Outputs a string using puts.
 *
 * @param string The string to be outputted.
 */
void fossil_console_puts(fossil_message_t string);

/**
 * Outputs a string to a file stream using fputs.
 *
 * @param string The string to be outputted.
 * @param stream The file stream to which the string is written.
 */
void fossil_console_fputs(FILE *stream, fossil_message_t string);

/**
 * Print formatted output to the console without color.
 *
 * @param format  The format string for the output.
 * @param ...     Additional arguments for formatted output.
 */
void fossil_console_out(fossil_message_t format, ...);

/**
 * Print formatted output to the console without color using fprintf.
 *
 * @param stream  The output stream (e.g., stdout).
 * @param format  The format string for the output.
 * @param ...     Additional arguments for formatted output.
 */
void fossil_console_fout(FILE *stream, fossil_message_t format, ...);

/**
 * Print formatted error message to the console.
 *
 * @param format The format string for the error message.
 * @param ...    Additional arguments for formatted output.
 */
void fossil_console_err(fossil_message_t format, ...);

/**
 * Clear the console screen.
 */
void fossil_console_clear(void);

/**
 * Flush the console output.
 */
void fossil_console_flush(void);

/**
 * Display a progress bar in the console.
 *
 * @param iterations The total number of iterations for the progress.
 * @param delay      The delay in milliseconds between progress updates.
 */
void fossil_console_progress(int32_t iterations, int32_t delay);

/**
 * Pause the console until user input is received.
 */
void fossil_console_pause(void);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <cstdarg>

namespace fossil {

class OStream {
public:
    static void puts(fossil_message_t string) {
        fossil_console_puts(string);
    }

    static void fputs(FILE *stream, fossil_message_t string) {
        fossil_console_fputs(stream, string);
    }

    static void out(fossil_message_t format, ...) {
        va_list args;
        va_start(args, format);
        fossil_console_out(format, args);
        va_end(args);
    }

    static void fout(FILE *stream, fossil_message_t format, ...) {
        va_list args;
        va_start(args, format);
        fossil_console_fout(stream, format, args);
        va_end(args);
    }

    static void err(fossil_message_t format, ...) {
        va_list args;
        va_start(args, format);
        fossil_console_err(format, args);
        va_end(args);
    }

    static void clear() {
        fossil_console_clear();
    }

    static void flush() {
        fossil_console_flush();
    }

    static void progress(int32_t iterations, int32_t delay) {
        fossil_console_progress(iterations, delay);
    }

    static void pause() {
        fossil_console_pause();
    }
};

} // namespace fossil

#endif // __cplusplus

#endif
