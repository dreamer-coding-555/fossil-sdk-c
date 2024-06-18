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
#include "fossil/strings/format.h"
#include "fossil/common/common.h"
#include <stdarg.h>

// Byte string macro
#define BSTR(str) ((bletter *)(str))

cstring fossil_cstr_format(const_cstring format, ...) {
    if (!format) {
        return cnullptr; // Input validation
    }

    va_list args, args_copy;
    va_start(args, format);
    va_copy(args_copy, args);

    // Calculate required size
    int size = vsnprintf(cnullptr, 0, format, args);
    va_end(args);

    if (size < 0) {
        return cnullptr; // Error handling
    }

    cstring buffer = malloc((size_t)size + 1);
    if (!buffer) {
        return cnullptr; // Memory management
    }

    vsnprintf(buffer, (size_t)size + 1, format, args_copy);
    va_end(args_copy);

    return buffer;
}

bstring fossil_bstr_format(const_bstring format, ...) {
    if (!format) {
        return cnullptr; // Input validation
    }

    va_list args, args_copy;
    va_start(args, format);
    va_copy(args_copy, args);

    // Calculate required size
    int size = vsnprintf(cnullptr, 0, (const char *)format, args);
    va_end(args);

    if (size < 0) {
        return cnullptr; // Error handling
    }

    bstring buffer = malloc((size_t)size + 1);
    if (!buffer) {
        return cnullptr; // Memory management
    }

    vsnprintf((char *)buffer, (size_t)size + 1, (const char *)format, args_copy);
    va_end(args_copy);

    return buffer;
}

wstring fossil_wstr_format(const_wstring format, ...) {
    if (!format) {
        return cnullptr; // Input validation
    }

    va_list args, args_copy;
    va_start(args, format);
    va_copy(args_copy, args);

    // Calculate required size
    int size = vswprintf(cnullptr, 0, (const wchar_t *)format, args);
    va_end(args);

    if (size < 0) {
        return cnullptr; // Error handling
    }

    wstring buffer = malloc((size_t)size * sizeof(wchar_t) + sizeof(wchar_t));
    if (!buffer) {
        return cnullptr; // Memory management
    }

    vswprintf((wchar_t *)buffer, (size_t)size + 1, (const wchar_t *)format, args_copy);
    va_end(args_copy);

    return buffer;
}

cstring fossil_cstr_format_phone(const_cstring phone) {
    if (!phone || strlen(phone) != 10) {
        return cnullptr;
    }

    return fossil_cstr_format("(%c%c%c) %c%c%c-%c%c%c%c",
                            phone[0], phone[1], phone[2],
                            phone[3], phone[4], phone[5],
                            phone[6], phone[7], phone[8], phone[9]);
}

bstring fossil_bstr_format_phone(const_bstring phone) {
    if (!phone || fossil_bstr_length(phone) != 10) {
        return cnullptr;
    }

    return fossil_bstr_format(BSTR("(%c%c%c) %c%c%c-%c%c%c%c"),
                            phone[0], phone[1], phone[2],
                            phone[3], phone[4], phone[5],
                            phone[6], phone[7], phone[8], phone[9]);
}

cstring fossil_cstr_format_date(const_cstring date) {
    if (!date || strlen(date) != 8) {
        return cnullptr;
    }

    return fossil_cstr_format("%c%c/%c%c/%c%c%c%c",
                            date[0], date[1],
                            date[2], date[3],
                            date[4], date[5], date[6], date[7]);
}

bstring fossil_bstr_format_date(const_bstring date) {
    if (!date || fossil_bstr_length(date) != 8) {
        return cnullptr;
    }

    return fossil_bstr_format(BSTR("%c%c/%c%c/%c%c%c%c"),
                            date[0], date[1],
                            date[2], date[3],
                            date[4], date[5], date[6], date[7]);
}

cstring fossil_cstr_format_time(const_cstring time) {
    if (!time || strlen(time) != 6) {
        return cnullptr;
    }

    return fossil_cstr_format("%c%c:%c%c:%c%c",
                            time[0], time[1],
                            time[2], time[3],
                            time[4], time[5]);
}

bstring fossil_bstr_format_time(const_bstring time) {
    if (!time || fossil_bstr_length(time) != 6) {
        return cnullptr;
    }

    return fossil_bstr_format(BSTR("%c%c:%c%c:%c%c"),
                            time[0], time[1],
                            time[2], time[3],
                            time[4], time[5]);
}

cstring fossil_cstr_format_currency(const_cstring currency) {
    if (!currency) {
        return cnullptr;
    }

    return fossil_cstr_format("$%s", currency);
}

bstring fossil_bstr_format_currency(const_bstring currency) {
    if (!currency) {
        return cnullptr;
    }

    return fossil_bstr_format(BSTR("$%s"), currency);
}

cstring fossil_cstr_format_percentage(const_cstring percentage) {
    if (!percentage) {
        return cnullptr;
    }

    return fossil_cstr_format("%s%%", percentage);
}

bstring fossil_bstr_format_percentage(const_bstring percentage) {
    if (!percentage) {
        return cnullptr;
    }

    return fossil_bstr_format(BSTR("%s%%"), percentage);
}

cstring fossil_cstr_format_postal_code(const_cstring postal_code) {
    if (!postal_code || strlen(postal_code) != 5) {
        return cnullptr;
    }

    return fossil_cstr_format("%c%c%c%c%c",
                            postal_code[0], postal_code[1],
                            postal_code[2], postal_code[3],
                            postal_code[4]);
}

bstring fossil_bstr_format_postal_code(const_bstring postal_code) {
    if (!postal_code || fossil_bstr_length(postal_code) != 5) {
        return cnullptr;
    }

    return fossil_bstr_format(BSTR("%c%c%c%c%c"),
                            postal_code[0], postal_code[1],
                            postal_code[2], postal_code[3],
                            postal_code[4]);
}

cstring fossil_cstr_format_ssn(const_cstring ssn) {
    if (!ssn || strlen(ssn) != 9) {
        return cnullptr;
    }

    return fossil_cstr_format("%c%c%c-%c%c-%c%c%c%c",
                            ssn[0], ssn[1], ssn[2],
                            ssn[3], ssn[4],
                            ssn[5], ssn[6], ssn[7], ssn[8]);
}

bstring fossil_bstr_format_ssn(const_bstring ssn) {
    if (!ssn || fossil_bstr_length(ssn) != 9) {
        return cnullptr;
    }

    return fossil_bstr_format(BSTR("%c%c%c-%c%c-%c%c%c%c"),
                            ssn[0], ssn[1], ssn[2],
                            ssn[3], ssn[4],
                            ssn[5], ssn[6], ssn[7], ssn[8]);
}

wstring fossil_wstr_format_phone(const_wstring phone) {
    if (!phone || wcslen(phone) != 10) {
        return cnullptr;
    }

    return fossil_wstr_format(L"(%c%c%c) %c%c%c-%c%c%c%c",
                            phone[0], phone[1], phone[2],
                            phone[3], phone[4], phone[5],
                            phone[6], phone[7], phone[8], phone[9]);
}

wstring fossil_wstr_format_date(const_wstring date) {
    if (!date || wcslen(date) != 8) {
        return cnullptr;
    }

    return fossil_wstr_format(L"%c%c/%c%c/%c%c%c%c",
                            date[0], date[1],
                            date[2], date[3],
                            date[4], date[5], date[6], date[7]);
}

wstring fossil_wstr_format_time(const_wstring time) {
    if (!time || wcslen(time) != 6) {
        return cnullptr;
    }

    return fossil_wstr_format(L"%c%c:%c%c:%c%c",
                            time[0], time[1],
                            time[2], time[3],
                            time[4], time[5]);
}

wstring fossil_wstr_format_currency(const_wstring currency) {
    if (!currency) {
        return cnullptr;
    }

    return fossil_wstr_format(L"$%s", currency);
}

wstring fossil_wstr_format_percentage(const_wstring percentage) {
    if (!percentage) {
        return cnullptr;
    }

    return fossil_wstr_format(L"%s%%", percentage);
}

wstring fossil_wstr_format_postal_code(const_wstring postal_code) {
    if (!postal_code || wcslen(postal_code) != 5) {
        return cnullptr;
    }

    return fossil_wstr_format(L"%c%c%c%c%c",
                            postal_code[0], postal_code[1],
                            postal_code[2], postal_code[3],
                            postal_code[4]);
}

wstring fossil_wstr_format_ssn(const_wstring ssn) {
    if (!ssn || wcslen(ssn) != 9) {
        return cnullptr;
    }

    return fossil_wstr_format(L"%c%c%c-%c%c-%c%c%c%c",
                            ssn[0], ssn[1], ssn[2],
                            ssn[3], ssn[4],
                            ssn[5], ssn[6], ssn[7], ssn[8]);
}
