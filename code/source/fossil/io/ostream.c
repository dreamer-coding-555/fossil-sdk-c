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
#include "fossil/io/ostream.h"
#include "fossil/io/soap.h"
#include <fossil/common/limits.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#define _GNU_SOURCE // for getline function
#include <termios.h>
#include <unistd.h>
#endif
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include <inttypes.h>

// Struct to store formatting information
typedef struct {
    const char *name;
    const char *code;
} FormatInfo;

// Function to apply color and attribute codes using dot notation or simple names
void apply_formatting(const char *type) {
    // ANSI escape codes for foreground colors
    const FormatInfo fg_colors[] = {
        {"black",   "\033[30m"},   // Black
        {"red",     "\033[31m"},   // Red
        {"green",   "\033[32m"},   // Green
        {"yellow",  "\033[33m"},   // Yellow
        {"blue",    "\033[34m"},   // Blue
        {"magenta", "\033[35m"},   // Magenta
        {"cyan",    "\033[36m"},   // Cyan
        {"white",   "\033[37m"},   // White
        {"bright_black",   "\033[90m"},  // Bright Black (Gray)
        {"bright_red",     "\033[91m"},  // Bright Red
        {"bright_green",   "\033[92m"},  // Bright Green
        {"bright_yellow",  "\033[93m"},  // Bright Yellow
        {"bright_blue",    "\033[94m"},  // Bright Blue
        {"bright_magenta", "\033[95m"},  // Bright Magenta
        {"bright_cyan",    "\033[96m"},  // Bright Cyan
        {"bright_white",   "\033[97m"}   // Bright White
    };

    // ANSI escape codes for background colors
    const FormatInfo bg_colors[] = {
        {"black",   "\033[40m"},  // Background Black
        {"red",     "\033[41m"},  // Background Red
        {"green",   "\033[42m"},  // Background Green
        {"yellow",  "\033[43m"},  // Background Yellow
        {"blue",    "\033[44m"},  // Background Blue
        {"magenta", "\033[45m"},  // Background Magenta
        {"cyan",    "\033[46m"},  // Background Cyan
        {"white",   "\033[47m"},  // Background White
        {"bright_black",   "\033[100m"},  // Bright Background Black (Gray)
        {"bright_red",     "\033[101m"},  // Bright Background Red
        {"bright_green",   "\033[102m"},  // Bright Background Green
        {"bright_yellow",  "\033[103m"},  // Bright Background Yellow
        {"bright_blue",    "\033[104m"},  // Bright Background Blue
        {"bright_magenta", "\033[105m"},  // Bright Background Magenta
        {"bright_cyan",    "\033[106m"},  // Bright Background Cyan
        {"bright_white",   "\033[107m"}   // Bright Background White
    };

    // ANSI escape codes for text attributes
    const FormatInfo attributes[] = {
        {"bold",      "\033[1m"},   // Bold
        {"dim",       "\033[2m"},   // Dim
        {"underline", "\033[4m"},   // Underline
        {"blink",     "\033[5m"},   // Blink
        {"reverse",   "\033[7m"},   // Reverse
        {"hidden",    "\033[8m"},   // Hidden
        {"emphasize", "\033[1m"}    // 'emphasize' maps to 'bold'
    };

    // Tokenize the type string by ':'
    char temp[64];
    strncpy(temp, type, sizeof(temp) - 1);
    temp[sizeof(temp) - 1] = '\0';

    char *token = strtok(temp, ":");
    while (token) {
        int32_t recognized = 0;

        if (strncmp(token, "fg.", 3) == 0) {
            // Check if token matches any foreground color
            for (size_t i = 0; i < sizeof(fg_colors) / sizeof(fg_colors[0]); ++i) {
                if (strcmp(token + 3, fg_colors[i].name) == 0) {
                    printf("%s", fg_colors[i].code);
                    recognized = 1;
                    break;
                }
            }
        } else if (strncmp(token, "bg.", 3) == 0) {
            // Check if token matches any background color
            for (size_t i = 0; i < sizeof(bg_colors) / sizeof(bg_colors[0]); ++i) {
                if (strcmp(token + 3, bg_colors[i].name) == 0) {
                    printf("%s", bg_colors[i].code);
                    recognized = 1;
                    break;
                }
            }
        } else {
            // Check if token matches any attribute
            for (size_t i = 0; i < sizeof(attributes) / sizeof(attributes[0]); ++i) {
                if (strcmp(token, attributes[i].name) == 0) {
                    printf("%s", attributes[i].code);
                    recognized = 1;
                    break;
                }
            }

            // Check if token matches any foreground color (without prefix)
            for (size_t i = 0; i < sizeof(fg_colors) / sizeof(fg_colors[0]); ++i) {
                if (strcmp(token, fg_colors[i].name) == 0) {
                    printf("%s", fg_colors[i].code);
                    recognized = 1;
                    break;
                }
            }

            // Check if token matches any background color (without prefix)
            for (size_t i = 0; i < sizeof(bg_colors) / sizeof(bg_colors[0]); ++i) {
                if (strcmp(token, bg_colors[i].name) == 0) {
                    printf("%s", bg_colors[i].code);
                    recognized = 1;
                    break;
                }
            }
        }

        if (!recognized) {
            fprintf(stderr, "Error: unrecognized format '%s'\n", token);
        }

        token = strtok(cnullptr, ":");
    }
}

// Function to reset terminal formatting
void reset_formatting(void) {
    printf("\033[0m");
}

void fstring_process(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == 'f' && *(format + 1) == '{') {
            // Handling f-string format
            char type[64] = "";
            size_t i = 0;
            format += 2; // Move past 'f{' prefix
            while (*format != '}' && *format != '\0' && i < sizeof(type) - 1) {
                type[i++] = *format++;
            }
            type[i] = '\0';

            if (*format != '}') {
                fprintf(stderr, "Error: Invalid format specifier.\n");
                va_end(args);
                return;
            }

            // Parse main type and format attributes
            char main_type[16] = "";
            char *colon = strchr(type, ':');
            if (colon) {
                size_t len = colon - type;
                strncpy(main_type, type, len);
                main_type[len] = '\0';
                apply_formatting(colon + 1);  // Apply attributes and colors
            } else {
                strcpy(main_type, type);
            }

            size_t limit = (size_t)-1; // Default limit, -1 means no limit specified
            if (main_type[0] != '\0' && main_type[strlen(main_type) - 1] == ':') {
                main_type[strlen(main_type) - 1] = '\0'; // Remove colon
                limit = (size_t)atoi(colon + 1); // Convert the number after colon to size_t
                if (limit == 0) {
                    fprintf(stderr, "Error: Invalid limit specifier.\n");
                    va_end(args);
                    return;
                }
            }

            // Switch case for different main types
            if (strcmp(main_type, "i8") == 0) {
                int8_t val = (int8_t)va_arg(args, int);
                printf("%*" PRId8, (int)limit, val);
            } else if (strcmp(main_type, "i16") == 0) {
                int16_t val = (int16_t)va_arg(args, int);
                printf("%*" PRId16, (int)limit, val);
            } else if (strcmp(main_type, "i32") == 0) {
                int32_t val = va_arg(args, int32_t);
                printf("%*" PRId32, (int)limit, val);
            } else if (strcmp(main_type, "i64") == 0) {
                int64_t val;
#ifdef _MSC_VER
                val = va_arg(args, int64_t);
                printf("%I64d", val);
#else
                val = va_arg(args, int64_t);
                printf("%*ld", (int)limit, (long)val);
#endif
            } else if (strcmp(main_type, "u8") == 0) {
                uint8_t val = (uint8_t)va_arg(args, int);
                printf("%*" PRIu8, (int)limit, val);
            } else if (strcmp(main_type, "u16") == 0) {
                uint16_t val = (uint16_t)va_arg(args, int);
                printf("%*" PRIu16, (int)limit, val);
            } else if (strcmp(main_type, "u32") == 0) {
                uint32_t val = va_arg(args, uint32_t);
                printf("%*" PRIu32, (int)limit, val);
            } else if (strcmp(main_type, "u64") == 0) {
#ifdef _MSC_VER
                unsigned __int64 val = va_arg(args, unsigned __int64);
                printf("%.*I64u", (int)limit, val);
#else
                uint64_t val = va_arg(args, uint64_t);
                printf("%*lu", (int)limit, (unsigned long)val);
#endif
            } else if (strcmp(main_type, "h8") == 0) {
                uint8_t val = (uint8_t)va_arg(args, int);
                printf("%*" PRIx8, (int)limit, val);
            } else if (strcmp(main_type, "h16") == 0) {
                uint16_t val = (uint16_t)va_arg(args, int);
                printf("%*" PRIx16, (int)limit, val);
            } else if (strcmp(main_type, "h32") == 0) {
                uint32_t val = va_arg(args, uint32_t);
                printf("%*" PRIx32, (int)limit, val);
            } else if (strcmp(main_type, "h64") == 0) {
#ifdef _MSC_VER
                unsigned __int64 val = va_arg(args, unsigned __int64);
                printf("%.*I64x", (int)limit, val);
#else
                uint64_t val = va_arg(args, uint64_t);
                printf("%*lx", (int)limit, (unsigned long)val);
#endif
            } else if (strcmp(main_type, "o8") == 0) {
                uint8_t val = (uint8_t)va_arg(args, int);
                printf("%*" PRIo8, (int)limit, val);
            } else if (strcmp(main_type, "o16") == 0) {
                uint16_t val = (uint16_t)va_arg(args, int);
                printf("%*" PRIo16, (int)limit, val);
            } else if (strcmp(main_type, "o32") == 0) {
                uint32_t val = va_arg(args, uint32_t);
                printf("%*" PRIo32, (int)limit, val);
            } else if (strcmp(main_type, "o64") == 0) {
#ifdef _MSC_VER
                unsigned __int64 val = va_arg(args, unsigned __int64);
                printf("%.*I64o", (int)limit, val);
#else
                uint64_t val = va_arg(args, uint64_t);
                printf("%*lo", (int)limit, (unsigned long)val);
#endif
            } else if (strcmp(main_type, "size") == 0) {
                size_t val = va_arg(args, size_t);
#ifdef _MSC_VER
                printf("%Iu", val);
#else
                printf("%*lu", (int)limit, (long unsigned int)val);  // Use PRIuMAX for size_t
#endif
            } else if (strncmp(main_type, "q", 1) == 0 && (strcmp(main_type + 1, "8") == 0 || strcmp(main_type + 1, "16") == 0 || strcmp(main_type + 1, "32") == 0 || strcmp(main_type + 1, "64") == 0)) {
                int fractional_bits = atoi(main_type + 1);
                int64_t val = va_arg(args, int64_t);
                double fixed_point_val = (double)val / (1 << fractional_bits);
                printf("%.*f", (int)limit, fixed_point_val);
            } else if (strcmp(main_type, "str") == 0) {
                char *str = va_arg(args, char *);
                if (limit != (size_t)-1) {
                    printf("%.*s", (int)limit, str);
                } else {
                    printf("%s", str);
                }
            } else if (strcmp(main_type, "ptr") == 0) {
                void *ptr = va_arg(args, void *);
                printf("%p", ptr);
            } else if (strcmp(main_type, "char") == 0) {
                char val = (char)va_arg(args, int);
                printf("%*c", (int)limit, val);
            }  else if (strcmp(main_type, "f32") == 0) {
                float val = (float)va_arg(args, double);
                printf("%*f", (int)limit, val);
            } else if (strcmp(main_type, "f64") == 0) {
                double val = va_arg(args, double);
                printf("%*f", (int)limit, val);
            } else {
                fprintf(stderr, "Error: Invalid type specifier '%s'.\n", main_type);
                va_end(args);
                return;
            }
            reset_formatting(); // Reset to default formatting
            format++; // Move past '}'
        } else if (*format == '%') {
            // Handling classic format
            const char *percent = format;
            while (*format && (*format != ' ' && *format != '%' && *format != 'f' && *format != '{')) {
                format++;
            }
            if (*format == '%' || *format == 'f' || *format == '{') {
                int length = format - percent + 1;
                char temp[length + 1];
                strncpy(temp, percent, length);
                temp[length] = '\0';
                vprintf(temp, args);
            } else {
                putchar(*format++);
            }
        } else {
            putchar(*format++);
        }
    }
    va_end(args);
}

// Output Function with puts
void fossil_console_puts(fossil_message_t string) {
    if (!string) {
        return;
    }

    char sanitized[FOSSIL_BUFFER_LARGE];
    strcpy(sanitized, string);
    fossil_soap_sanitize(sanitized);

    puts(sanitized);
}

// Output Function with fputs
void fossil_console_fputs(FILE *stream, fossil_message_t string) {
    if (!string || !stream) {
        return;
    }

    char sanitized[FOSSIL_BUFFER_LARGE];
    strcpy(sanitized, string);
    fossil_soap_sanitize(sanitized);

    fputs(sanitized, stream);
}

// General Output Function
void fossil_console_out(fossil_message_t format, ...) {
    if (!format) {
        return;
    }

    va_list args;
    va_start(args, format);

    char sanitized[FOSSIL_BUFFER_LARGE];
    vsnprintf(sanitized, FOSSIL_BUFFER_LARGE, format, args);
    fossil_soap_sanitize(sanitized);

    // Use fstring_process for formatting
    fstring_process(sanitized, args);

    va_end(args);
}

// General Output Function
void fossil_console_fout(FILE *stream, fossil_message_t format, ...) {
    if (!stream || !format) {
        return;
    }

    va_list args;
    va_start(args, format);

    char sanitized[FOSSIL_BUFFER_LARGE];
    vsnprintf(sanitized, FOSSIL_BUFFER_LARGE, format, args);
    fossil_soap_sanitize(sanitized);

    // Use fstring_process for formatting
    fstring_process(sanitized, args);

    va_end(args);
}

// Error Output Function
void fossil_console_err(fossil_message_t format, ...) {
    if (!format) {
        return;
    }

    va_list args;
    va_start(args, format);

    char sanitized[FOSSIL_BUFFER_LARGE];
    vsnprintf(sanitized, FOSSIL_BUFFER_LARGE, format, args);
    fossil_soap_sanitize(sanitized);

    // Use fstring_process for formatting
    fstring_process(sanitized, args);

    va_end(args);
}

// Clear Screen Function
void fossil_console_clear(void) {
#ifdef _WIN32
    int dummy = system("cls");
#else
    int dummy = system("clear");
#endif
    (void)dummy;  // Avoid unused variable warning
}

// Flush Output Function
void fossil_console_flush(void) {
    fflush(stdout);
}

// Console Progress Function
void fossil_console_progress(int32_t iterations, int32_t delay) {
    const char *animation[] = {"|", "/", "-", "\\"};
    int i;

    if (iterations <= 0 || delay <= 0) {
        fossil_console_puts("Invalid parameters for progress function.");
        return;
    }

    // Limit the maximum iterations to avoid excessive resource consumption
    iterations = (iterations > 1000) ? 1000 : iterations;

    for (i = 0; i < iterations; ++i) {
        fossil_console_out("\rProgress: %s", animation[i % 4]);
        fflush(stdout);

#ifdef _WIN32
        Sleep(delay);  // Sleep in milliseconds on Windows
#else
        sleep(delay * 1000);  // Sleep in microseconds on POSIX
#endif
    }

    fossil_console_out("\rProgress: Done!\n");
}

// Console Pause Function
void fossil_console_pause(void) {
    fossil_console_out("Press Enter to continue...");
    getchar();  // Wait for user input (Enter key)
}
