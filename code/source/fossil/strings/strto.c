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
#include "fossil/strings/strto.h"
#include "fossil/common/common.h"
#include <wchar.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

enum {
    FOSSIL_STRTO_BASE = 10
};

// Convert string to integer
int fossil_cstr_to_int(const_cstring str) {
    if (str == cnullptr || *str == cterminator) {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    long result = strtol(str, &endptr, FOSSIL_STRTO_BASE);
    if (errno == ERANGE || *endptr != cterminator || result > INT_MAX || result < INT_MIN) {
        // Handle conversion error or overflow/underflow
        return 0; // Return a default value or indicate error
    }

    return (int)result;
}

int fossil_bstr_to_int(const_bstring str) {
    if (str == cnullptr || *str == cterminator) {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    long result = strtol((const char *)str, &endptr, FOSSIL_STRTO_BASE);
    if (errno == ERANGE || *endptr != cterminator || result > INT_MAX || result < INT_MIN) {
        // Handle conversion error or overflow/underflow
        return 0; // Return a default value or indicate error
    }

    return (int)result;
}

// Convert string to floating point number
double fossil_cstr_to_double(const_cstring str) {
    if (str == cnullptr || *str == cterminator) {
        return 0.0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    double result = strtod(str, &endptr);
    if (errno == ERANGE || *endptr != cterminator) {
        // Handle conversion error
        return 0.0; // Return a default value or indicate error
    }

    return result;
}

double fossil_bstr_to_double(const_bstring str) {
    if (str == cnullptr || *str == cterminator) {
        return 0.0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    double result = strtod((const char *)str, &endptr);
    if (errno == ERANGE || *endptr != cterminator) {
        // Handle conversion error
        return 0.0; // Return a default value or indicate error
    }

    return result;
}

// Convert string to long integer
long fossil_cstr_to_long(const_cstring str) {
    if (str == cnullptr || *str == cterminator) {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    long result = strtol(str, &endptr, FOSSIL_STRTO_BASE);
    if (errno == ERANGE || *endptr != cterminator) {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

long fossil_bstr_to_long(const_bstring str) {
    if (str == cnullptr || *str == cterminator) {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    long result = strtol((const char *)str, &endptr, FOSSIL_STRTO_BASE);
    if (errno == ERANGE || *endptr != cterminator) {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

// Convert string to unsigned long integer
unsigned long fossil_cstr_to_ulong(const_cstring str) {
    if (str == cnullptr || *str == cterminator) {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    unsigned long result = strtoul(str, &endptr, FOSSIL_STRTO_BASE);
    if (errno == ERANGE || *endptr != cterminator) {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

unsigned long fossil_bstr_to_ulong(const_bstring str) {
    if (str == cnullptr || *str == cterminator) {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    unsigned long result = strtoul((const char *)str, &endptr, FOSSIL_STRTO_BASE);
    if (errno == ERANGE || *endptr != cterminator) {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

// Convert string to long long integer
long long fossil_cstr_to_llong(const_cstring str) {
    if (str == cnullptr || *str == cterminator) {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    long long result = strtoll(str, &endptr, FOSSIL_STRTO_BASE);
    if (errno == ERANGE || *endptr != cterminator) {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

long long fossil_bstr_to_llong(const_bstring str) {
    if (str == cnullptr || *str == cterminator) {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    long long result = strtoll((const char *)str, &endptr, FOSSIL_STRTO_BASE);
    if (errno == ERANGE || *endptr != cterminator) {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

// Convert string to unsigned long long integer
unsigned long long fossil_cstr_to_ullong(const_cstring str) {
    if (str == cnullptr || *str == cterminator) {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    unsigned long long result = strtoull(str, &endptr, FOSSIL_STRTO_BASE);
    if (errno == ERANGE || *endptr != cterminator) {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

unsigned long long fossil_bstr_to_ullong(const_bstring str) {
    if (str == cnullptr || *str == cterminator) {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    char *endptr;
    errno = 0;
    unsigned long long result = strtoull((const char *)str, &endptr, FOSSIL_STRTO_BASE);
    if (errno == ERANGE || *endptr != cterminator) {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

// Convert string to integer
int fossil_wstr_to_int(const_wstring str) {
    if (str == cnullptr || *str == wterminator) {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    wchar_t *endptr;
    errno = 0;
    long result = wcstol(str, &endptr, FOSSIL_STRTO_BASE);
    if (errno == ERANGE || *endptr != wterminator || result > INT_MAX || result < INT_MIN) {
        // Handle conversion error or overflow/underflow
        return 0; // Return a default value or indicate error
    }

    return (int)result;
}

// Convert string to floating point number
double fossil_wstr_to_double(const_wstring str) {
    if (str == cnullptr || *str == wterminator) {
        return 0.0; // Handle invalid input (NULL pointer or empty string)
    }

    wchar_t *endptr;
    errno = 0;
    double result = wcstod(str, &endptr);
    if (errno == ERANGE || *endptr != wterminator) {
        // Handle conversion error
        return 0.0; // Return a default value or indicate error
    }

    return result;
}

// Convert string to long integer
long fossil_wstr_to_long(const_wstring str) {
    if (str == cnullptr || *str == wterminator) {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    wchar_t *endptr;
    errno = 0;
    long result = wcstol(str, &endptr, FOSSIL_STRTO_BASE);
    if (errno == ERANGE || *endptr != wterminator) {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

// Convert string to unsigned long integer
unsigned long fossil_wstr_to_ulong(const_wstring str) {
    if (str == cnullptr || *str == wterminator) {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    wchar_t *endptr;
    errno = 0;
    unsigned long result = wcstoul(str, &endptr, FOSSIL_STRTO_BASE);
    if (errno == ERANGE || *endptr != wterminator) {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

// Convert string to long long integer
long long fossil_wstr_to_llong(const_wstring str) {
    if (str == cnullptr || *str == wterminator) {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    wchar_t *endptr;
    errno = 0;
    long long result = wcstoll(str, &endptr, FOSSIL_STRTO_BASE);
    if (errno == ERANGE || *endptr != wterminator) {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}

// Convert string to unsigned long long integer
unsigned long long fossil_wstr_to_ullong(const_wstring str) {
    if (str == cnullptr || *str == wterminator) {
        return 0; // Handle invalid input (NULL pointer or empty string)
    }

    wchar_t *endptr;
    errno = 0;
    unsigned long long result = wcstoull(str, &endptr, FOSSIL_STRTO_BASE);
    if (errno == ERANGE || *endptr != wterminator) {
        // Handle conversion error
        return 0; // Return a default value or indicate error
    }

    return result;
}
