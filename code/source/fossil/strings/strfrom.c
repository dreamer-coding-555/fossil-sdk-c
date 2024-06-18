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
#include "fossil/strings/strfrom.h"
#include "fossil/common/common.h"
#include <limits.h> // for INT_MAX, INT_MIN, etc.

// Helper function to calculate the number of digits in an integer
int num_digits(long long num) {
    int count = 0;
    if (num == 0) return 1; // Handle special case for zero
    if (num < 0) {
        count++; // Account for negative sign
        num = -num; // Convert negative number to positive
    }
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}

// Convert integer to string
cstring fossil_cstr_from_int(int num) {
    int digits = num_digits(num);
    cstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return cnullptr; // Return NULL if memory allocation fails
    }
    snprintf(str, digits + 1, "%d", num); // Use snprintf with dynamically calculated buffer size
    return str;
}

bstring fossil_bstr_from_int(int num) {
    int digits = num_digits(num);
    bstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return cnullptr; // Return NULL if memory allocation fails
    }
    snprintf((char *)str, digits + 1, "%d", num); // Use snprintf with dynamically calculated buffer size
    return str;
}

// Convert long to string
cstring fossil_cstr_from_long(long num) {
    int digits = num_digits(num);
    cstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return cnullptr; // Return NULL if memory allocation fails
    }
    snprintf(str, digits + 1, "%ld", num); // Use snprintf with dynamically calculated buffer size
    return str;
}

bstring fossil_bstr_from_long(long num) {
    int digits = num_digits(num);
    bstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return cnullptr; // Return NULL if memory allocation fails
    }
    snprintf((char *)str, digits + 1, "%ld", num); // Use snprintf with dynamically calculated buffer size
    return str;
}

// Convert long long to string
cstring fossil_cstr_from_llong(long long num) {
    int digits = num_digits(num);
    cstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return cnullptr; // Return NULL if memory allocation fails
    }
    snprintf(str, digits + 1, "%ld", (long int)num); // Use snprintf with dynamically calculated buffer size
    return str;
}

bstring fossil_bstr_from_llong(long long num) {
    int digits = num_digits(num);
    bstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return cnullptr; // Return NULL if memory allocation fails
    }
    snprintf((char *)str, digits + 1, "%ld", (long int)num); // Use snprintf with dynamically calculated buffer size
    return str;
}

// Convert unsigned long to string
cstring fossil_cstr_from_ulong(unsigned long num) {
    int digits = num_digits(num);
    cstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return cnullptr; // Return NULL if memory allocation fails
    }
    snprintf(str, digits + 1, "%lu", num); // Use snprintf with dynamically calculated buffer size
    return str;
}

bstring fossil_bstr_from_ulong(unsigned long num) {
    int digits = num_digits(num);
    bstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return cnullptr; // Return NULL if memory allocation fails
    }
    snprintf((char *)str, digits + 1, "%lu", num); // Use snprintf with dynamically calculated buffer size
    return str;
}

// Convert unsigned long long to string
cstring fossil_cstr_from_ullong(unsigned long long num) {
    int digits = num_digits(num);
    cstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return cnullptr; // Return NULL if memory allocation fails
    }
    snprintf(str, digits + 1, "%lu", (long unsigned int)num); // Use snprintf with dynamically calculated buffer size
    return str;
}

bstring fossil_bstr_from_ullong(unsigned long long num) {
    int digits = num_digits(num);
    bstring str = malloc(digits + 1); // Allocate memory dynamically
    if (!str) {
        return cnullptr; // Return NULL if memory allocation fails
    }
    snprintf((char *)str, digits + 1, "%lu", (long unsigned int)num); // Use snprintf with dynamically calculated buffer size
    return str;
}

// Convert integer to wide string
wstring fossil_wstr_from_int(int num) {
    int digits = num_digits(num);
    wstring str = (wstring)malloc((digits + 1) * sizeof(wchar_t)); // Allocate memory dynamically
    if (!str) {
        return cnullptr; // Return cnullptr if memory allocation fails
    }
    swprintf(str, digits + 1, L"%d", num); // Use swprintf with dynamically calculated buffer size
    return str;
}

// Convert long to wide string
wstring fossil_wstr_from_long(long num) {
    int digits = num_digits(num);
    wstring str = (wstring)malloc((digits + 1) * sizeof(wchar_t)); // Allocate memory dynamically
    if (!str) {
        return cnullptr; // Return cnullptr if memory allocation fails
    }
    swprintf(str, digits + 1, L"%ld", num); // Use swprintf with dynamically calculated buffer size
    return str;
}

// Convert long long to wide string
wstring fossil_wstr_from_llong(long long num) {
    int digits = num_digits(num);
    wstring str = (wstring)malloc((digits + 1) * sizeof(wchar_t)); // Allocate memory dynamically
    if (!str) {
        return cnullptr; // Return cnullptr if memory allocation fails
    }
    swprintf(str, digits + 1, L"%ld", (long int)num); // Use swprintf with dynamically calculated buffer size
    return str;
}

// Convert unsigned long to wide string
wstring fossil_wstr_from_ulong(unsigned long num) {
    int digits = num_digits(num);
    wstring str = (wstring)malloc((digits + 1) * sizeof(wchar_t)); // Allocate memory dynamically
    if (!str) {
        return cnullptr; // Return cnullptr if memory allocation fails
    }
    swprintf(str, digits + 1, L"%lu", num); // Use swprintf with dynamically calculated buffer size
    return str;
}

// Convert unsigned long long to wide string
wstring fossil_wstr_from_ullong(unsigned long long num) {
    int digits = num_digits(num);
    wstring str = (wstring)malloc((digits + 1) * sizeof(wchar_t)); // Allocate memory dynamically
    if (!str) {
        return cnullptr; // Return cnullptr if memory allocation fails
    }
    swprintf(str, digits + 1, L"%lu", (long unsigned int)num); // Use swprintf with dynamically calculated buffer size
    return str;
}

cstring fossil_cstr_from_double(double num) {
    // Decide the maximum possible length of the string
    int max_length = 50; // Arbitrarily chosen

    // Allocate memory for the string
    cstring str = malloc(max_length);
    if (!str) {
        return cnullptr; // Return NULL if memory allocation fails
    }

    // Convert the double to string
    int written = snprintf(str, max_length, "%lf", num);
    if (written < 0 || written >= max_length) {
        free(str); // Free the allocated memory
        return cnullptr; // Return NULL if snprintf failed or buffer overflow
    }

    return str;
}

bstring fossil_bstr_from_double(double num) {
    // Decide the maximum possible length of the string
    int max_length = 50; // Arbitrarily chosen

    // Allocate memory for the string
    bstring str = malloc(max_length);
    if (!str) {
        return cnullptr; // Return NULL if memory allocation fails
    }

    // Convert the double to string
    int written = snprintf((char *)str, max_length, "%lf", num);
    if (written < 0 || written >= max_length) {
        free(str); // Free the allocated memory
        return cnullptr; // Return NULL if snprintf failed or buffer overflow
    }

    return str;
}

wstring fossil_wstr_from_double(double num) {
    // Decide the maximum possible length of the string
    int max_length = 50; // Arbitrarily chosen

    // Allocate memory for the string
    wstring str = malloc(max_length * sizeof(wchar_t));
    if (!str) {
        return cnullptr; // Return NULL if memory allocation fails
    }

    // Convert the double to string
    int written = swprintf(str, max_length, L"%lf", (long unsigned int)num);
    if (written < 0 || written >= max_length) {
        free(str); // Free the allocated memory
        return cnullptr; // Return NULL if swprintf failed or buffer overflow
    }

    return str;
}
