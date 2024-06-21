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
#include "fossil/generic/tofu.h"
#include <wchar.h>
#include <string.h>
#include <stdarg.h>
#include <inttypes.h>

// Lookup table for valid strings corresponding to each tofu type.
static const char *tofu_type_strings[] = {
    "ghost",
    "int",
    "uint",
    "hex",
    "octal",
    "float",
    "double",
    "bstr",
    "wstr",
    "cstr",
    "bchar",
    "cchar",
    "wchar",
    "size",
    "bool"
};

// Helper function to convert hexadecimal string to uint64_t
static uint64_t parse_hexadecimal(const char *value) {
    uint64_t result;
    sscanf(value, "%" SCNx64, &result);
    return result;
}

// Helper function to convert octal string to uint64_t
static uint64_t parse_octal(const char *value) {
    uint64_t result;
    sscanf(value, "%" SCNo64, &result);
    return result;
}

// Function to convert string to fossil_tofu_type_t
fossil_tofu_type_t string_to_tofu_type(const char *str) {
    for (int i = 0; i < FOSSIL_TOFU_TYPE_SIZE; ++i) {
        if (strcmp(str, tofu_type_strings[i]) == 0) {
            return (fossil_tofu_type_t)i;
        }
    }
    return FOSSIL_TOFU_TYPE_GHOST; // Default to ghost type if not found
}

// Function to create fossil_tofu_t based on type and value strings
fossil_tofu_t fossil_tofu_create(char* type, char* value) {
    fossil_tofu_type_t tofu_type = string_to_tofu_type(type);
    fossil_tofu_t tofu;
    tofu.type = tofu_type;
    tofu.is_cached = false;

    switch (tofu_type) {
        case FOSSIL_TOFU_TYPE_INT:
            tofu.value.int_val = atoll(value);
            break;
        case FOSSIL_TOFU_TYPE_UINT:
            tofu.value.uint_val = strtoull(value, NULL, 10);
            break;
        case FOSSIL_TOFU_TYPE_HEX:
            tofu.value.uint_val = parse_hexadecimal(value);
            break;
        case FOSSIL_TOFU_TYPE_OCTAL:
            tofu.value.uint_val = parse_octal(value);
            break;
        case FOSSIL_TOFU_TYPE_FLOAT:
            tofu.value.float_val = strtof(value, NULL);
            break;
        case FOSSIL_TOFU_TYPE_DOUBLE:
            tofu.value.double_val = strtod(value, NULL);
            break;
        case FOSSIL_TOFU_TYPE_BSTR:
            tofu.value.byte_string_val = (char *) malloc(strlen(value) + 1);
            strcpy(tofu.value.byte_string_val, value);
            break;
        case FOSSIL_TOFU_TYPE_WSTR:
            // Assuming wide string conversion is handled appropriately
            // Here, we just allocate memory and copy the value
            tofu.value.wide_string_val = (wchar_t *) malloc((wcslen((wchar_t *)value) + 1) * sizeof(wchar_t));
            wcscpy(tofu.value.wide_string_val, (wchar_t *)value);
            break;
        case FOSSIL_TOFU_TYPE_CSTR:
            tofu.value.c_string_val = _custom_fossil_strdup(value);
            break;
        case FOSSIL_TOFU_TYPE_BCHAR:
            tofu.value.byte_val = (uint8_t *) malloc(strlen(value) + 1);
            memcpy(tofu.value.byte_val, value, strlen(value) + 1);
            break;
        case FOSSIL_TOFU_TYPE_CCHAR:
            tofu.value.char_val = value[0];
            break;
        case FOSSIL_TOFU_TYPE_WCHAR:
            // Assuming wide char conversion is handled appropriately
            tofu.value.wchar_val = ((wchar_t *)value)[0];
            break;
        case FOSSIL_TOFU_TYPE_BOOL:
            tofu.value.bool_val = (uint8_t)atoi(value);
            break;
        default:
            fprintf(stderr, "Unsupported type\n");
            tofu.type = FOSSIL_TOFU_TYPE_GHOST;
            break;
    }

    return tofu;
}

// Memorization (caching) function for fossil_tofu_t
void fossil_tofu_memorize(fossil_tofu_t *tofu) {
    if (!tofu->is_cached) {
        tofu->cached_value = tofu->value;
        tofu->is_cached = true;
    }
}

// Utility function to print fossil_tofu_t
void fossil_tofu_print(fossil_tofu_t tofu) {
    switch (tofu.type) {
        case FOSSIL_TOFU_TYPE_INT:
            printf("int: %lld\n", tofu.value.int_val);
            break;
        case FOSSIL_TOFU_TYPE_UINT:
            printf("uint: %llu\n", (unsigned long long)tofu.value.uint_val);
            break;
        case FOSSIL_TOFU_TYPE_HEX:
            printf("hex: %llx\n", (unsigned long long)tofu.value.uint_val);
            break;
        case FOSSIL_TOFU_TYPE_OCTAL:
            printf("octal: %llo\n", (unsigned long long)tofu.value.uint_val);
            break;
        case FOSSIL_TOFU_TYPE_FLOAT:
            printf("float: %f\n", tofu.value.float_val);
            break;
        case FOSSIL_TOFU_TYPE_DOUBLE:
            printf("double: %lf\n", tofu.value.double_val);
            break;
        case FOSSIL_TOFU_TYPE_BSTR:
            printf("bstr: %s\n", tofu.value.byte_string_val);
            break;
        case FOSSIL_TOFU_TYPE_WSTR:
            wprintf(L"wstr: %ls\n", tofu.value.wide_string_val);
            break;
        case FOSSIL_TOFU_TYPE_CSTR:
            printf("cstr: %s\n", tofu.value.c_string_val);
            break;
        case FOSSIL_TOFU_TYPE_BCHAR:
            printf("bchar: %s\n", (char *)tofu.value.byte_val);
            break;
        case FOSSIL_TOFU_TYPE_CCHAR:
            printf("cchar: %c\n", tofu.value.char_val);
            break;
        case FOSSIL_TOFU_TYPE_WCHAR:
            wprintf(L"wchar: %lc\n", tofu.value.wchar_val);
            break;
        case FOSSIL_TOFU_TYPE_BOOL:
            printf("bool: %s\n", tofu.value.bool_val ? "true" : "false");
            break;
        case FOSSIL_TOFU_TYPE_GHOST:
            printf("scary ghost value\n");
            break;
        default:
            printf("Unknown type\n");
            break;
    }
}

// Function to destroy fossil_tofu_t and free allocated memory
void fossil_tofu_erase(fossil_tofu_t *tofu) {
    switch (tofu->type) {
        case FOSSIL_TOFU_TYPE_BSTR:
            free(tofu->value.byte_string_val);
            break;
        case FOSSIL_TOFU_TYPE_WSTR:
            free(tofu->value.wide_string_val);
            break;
        case FOSSIL_TOFU_TYPE_CSTR:
            free(tofu->value.c_string_val);
            break;
        case FOSSIL_TOFU_TYPE_BCHAR:
            free(tofu->value.byte_val);
            break;
        default:
            // No dynamic memory to free for other types
            break;
    }
}

// Utility function to convert fossil_tofu_type_t to string representation
const char* fossil_tofu_type_to_string(fossil_tofu_type_t type) {
    if (type >= 0 && type < FOSSIL_TOFU_TYPE_BOOL) {
        return tofu_type_strings[type];
    } else {
        return "unknown";
    }
}

bool fossil_tofu_compare(fossil_tofu_t *tofu1, fossil_tofu_t *tofu2) {
    if (tofu1->type != tofu2->type) {
        return false;
    }

    switch (tofu1->type) {
        case FOSSIL_TOFU_TYPE_INT:
            return tofu1->value.int_val == tofu2->value.int_val;
        case FOSSIL_TOFU_TYPE_UINT:
            return tofu1->value.uint_val == tofu2->value.uint_val;
        case FOSSIL_TOFU_TYPE_HEX:
        case FOSSIL_TOFU_TYPE_OCTAL:
            return tofu1->value.uint_val == tofu2->value.uint_val;
        case FOSSIL_TOFU_TYPE_FLOAT:
            return tofu1->value.float_val == tofu2->value.float_val;
        case FOSSIL_TOFU_TYPE_DOUBLE:
            return tofu1->value.double_val == tofu2->value.double_val;
        case FOSSIL_TOFU_TYPE_BSTR:
            return strcmp(tofu1->value.byte_string_val, tofu2->value.byte_string_val) == 0;
        case FOSSIL_TOFU_TYPE_WSTR:
            return wcscmp(tofu1->value.wide_string_val, tofu2->value.wide_string_val) == 0;
        case FOSSIL_TOFU_TYPE_CSTR:
            return strcmp(tofu1->value.c_string_val, tofu2->value.c_string_val) == 0;
        case FOSSIL_TOFU_TYPE_BCHAR:
            return strcmp((char *)tofu1->value.byte_val, (char *)tofu2->value.byte_val) == 0;
        case FOSSIL_TOFU_TYPE_CCHAR:
            return tofu1->value.char_val == tofu2->value.char_val;
        case FOSSIL_TOFU_TYPE_WCHAR:
            return tofu1->value.wchar_val == tofu2->value.wchar_val;
        case FOSSIL_TOFU_TYPE_BOOL:
            return tofu1->value.bool_val == tofu2->value.bool_val;
        default:
            return false;
    }
}

// Utility function to check if two fossil_tofu_t objects are equal
bool fossil_tofu_equals(fossil_tofu_t tofu1, fossil_tofu_t tofu2) {
    if (tofu1.type != tofu2.type) {
        return false;
    }

    switch (tofu1.type) {
        case FOSSIL_TOFU_TYPE_INT:
            return tofu1.value.int_val == tofu2.value.int_val;
        case FOSSIL_TOFU_TYPE_UINT:
            return tofu1.value.uint_val == tofu2.value.uint_val;
        case FOSSIL_TOFU_TYPE_HEX:
        case FOSSIL_TOFU_TYPE_OCTAL:
            return tofu1.value.uint_val == tofu2.value.uint_val;
        case FOSSIL_TOFU_TYPE_FLOAT:
            return tofu1.value.float_val == tofu2.value.float_val;
        case FOSSIL_TOFU_TYPE_DOUBLE:
            return tofu1.value.double_val == tofu2.value.double_val;
        case FOSSIL_TOFU_TYPE_BSTR:
            return strcmp(tofu1.value.byte_string_val, tofu2.value.byte_string_val) == 0;
        case FOSSIL_TOFU_TYPE_WSTR:
            return wcscmp(tofu1.value.wide_string_val, tofu2.value.wide_string_val) == 0;
        case FOSSIL_TOFU_TYPE_CSTR:
            return strcmp(tofu1.value.c_string_val, tofu2.value.c_string_val) == 0;
        case FOSSIL_TOFU_TYPE_BCHAR:
            return strcmp((char *)tofu1.value.byte_val, (char *)tofu2.value.byte_val) == 0;
        case FOSSIL_TOFU_TYPE_CCHAR:
            return tofu1.value.char_val == tofu2.value.char_val;
        case FOSSIL_TOFU_TYPE_WCHAR:
            return tofu1.value.wchar_val == tofu2.value.wchar_val;
        case FOSSIL_TOFU_TYPE_BOOL:
            return tofu1.value.bool_val == tofu2.value.bool_val;
        default:
            return false;
    }
}

// Utility function to copy a fossil_tofu_t object
fossil_tofu_t fossil_tofu_copy(fossil_tofu_t tofu) {
    fossil_tofu_t copy;
    copy.type = tofu.type;
    copy.is_cached = tofu.is_cached;

    switch (tofu.type) {
        case FOSSIL_TOFU_TYPE_INT:
            copy.value.int_val = tofu.value.int_val;
            break;
        case FOSSIL_TOFU_TYPE_UINT:
            copy.value.uint_val = tofu.value.uint_val;
            break;
        case FOSSIL_TOFU_TYPE_HEX:
        case FOSSIL_TOFU_TYPE_OCTAL:
            copy.value.uint_val = tofu.value.uint_val;
            break;
        case FOSSIL_TOFU_TYPE_FLOAT:
            copy.value.float_val = tofu.value.float_val;
            break;
        case FOSSIL_TOFU_TYPE_DOUBLE:
            copy.value.double_val = tofu.value.double_val;
            break;
        case FOSSIL_TOFU_TYPE_BSTR:
            copy.value.byte_string_val = _custom_fossil_strdup(tofu.value.byte_string_val);
            break;
        case FOSSIL_TOFU_TYPE_WSTR:
            copy.value.wide_string_val = (wchar_t *) malloc((wcslen(tofu.value.wide_string_val) + 1) * sizeof(wchar_t));
            wcscpy(copy.value.wide_string_val, tofu.value.wide_string_val);
            break;
        case FOSSIL_TOFU_TYPE_CSTR:
            copy.value.c_string_val = _custom_fossil_strdup(tofu.value.c_string_val);
            break;
        case FOSSIL_TOFU_TYPE_BCHAR:
            copy.value.byte_val = (uint8_t *) malloc(strlen((char *)tofu.value.byte_val) + 1);
            memcpy(copy.value.byte_val, tofu.value.byte_val, strlen((char *)tofu.value.byte_val) + 1);
            break;
        case FOSSIL_TOFU_TYPE_CCHAR:
            copy.value.char_val = tofu.value.char_val;
            break;
        case FOSSIL_TOFU_TYPE_WCHAR:
            copy.value.wchar_val = tofu.value.wchar_val;
            break;
        case FOSSIL_TOFU_TYPE_BOOL:
            copy.value.bool_val = tofu.value.bool_val;
            break;
        default:
            // Handle unknown type or ghost type
            copy.type = FOSSIL_TOFU_TYPE_GHOST;
            break;
    }

    return copy;
}
