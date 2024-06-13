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
#include "fossil/core/fson.h"
#include "fossil/common/common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

// Define a lookup table for type names
const char* fson_type_names[] = {
    "UNKNOWN",
    "i8", "i16", "i32", "i64",
    "u8", "u16", "u32", "u64",
    "o8", "o16", "o32", "o64",
    "b8", "b16", "b32", "b64",
    "h8", "h16", "h32", "h64",
    "str", "cnull", "float", "double",
    "bool"
};

// Function to get type ID from type name
fson_type get_type_id(const char* type_name) {
    for (int i = 1; i <= FSON_TYPE_BOOL; i++) {
        if (strcmp(fson_type_names[i], type_name) == 0) {
            return (fson_type)i;
        }
    }
    return FSON_TYPE_UNKNOWN; // Type not found
}

// Tokenize FSON string
fson_token* fossil_fson_tokenize(const char* restrict input) {
    fson_token* tokens = malloc(sizeof(fson_token) * 100);
    int token_count = 0;
    const char* ptr = input;

    while (*ptr != '\0') {
        while (isspace(*ptr)) ptr++;
        if (*ptr == '\0') break;

        if (isalpha(*ptr) || *ptr == '_') {
            const char* start = ptr;
            while (isalnum(*ptr) || *ptr == '_') ptr++;
            int length = ptr - start;
            char* value = _custom_fossil_core_strndup(start, length);
            tokens[token_count++] = (fson_token){FSON_TOKEN_IDENTIFIER, value};
        } else if (isdigit(*ptr) || *ptr == '-' || *ptr == '+') {
            const char* start = ptr;
            while (isdigit(*ptr) || *ptr == '.' || *ptr == 'e' || *ptr == 'E' || *ptr == '-' || *ptr == '+') ptr++;
            int length = ptr - start;
            char* value = _custom_fossil_core_strndup(start, length);
            tokens[token_count++] = (fson_token){FSON_TOKEN_NUMBER, value};
        } else if (*ptr == '"' || *ptr == '\'') {
            char quote = *ptr++;
            const char* start = ptr;
            while (*ptr != quote) ptr++;
            int length = ptr - start;
            char* value = _custom_fossil_core_strndup(start, length);
            tokens[token_count++] = (fson_token){FSON_TOKEN_STRING, value};
            ptr++;
        } else if (ispunct(*ptr)) {
            char* value = _custom_fossil_core_strndup(ptr, 1);
            tokens[token_count++] = (fson_token){FSON_TOKEN_SYMBOL, value};
            ptr++;
        } else {
            ptr++;
        }
    }

    tokens[token_count++] = (fson_token){FSON_TOKEN_EOF, cnullptr};
    return tokens;
}

// Free tokens
void fossil_fson_erase_tokens(fson_token* tokens) {
    for (int i = 0; tokens[i].type != FSON_TOKEN_EOF; i++) {
        free(tokens[i].value);
    }
    free(tokens);
}

// Find a value by key within a namespace
fson_value* fossil_fson_value_find(fson_namespace* ns, const char* restrict key) {
    if (ns == cnullptr || key == cnullptr) {
        return cnullptr; // Invalid arguments
    }

    // Linear search for the key
    for (int i = 0; i < ns->count; i++) {
        if (strcmp(ns->values[i].key, key) == 0) {
            return &ns->values[i]; // Key found
        }
    }

    return cnullptr; // Key not found
}

// Namespace-specific functions

fson_namespace* fossil_fson_namespace_parse(fson_token** tokens) {
    fson_namespace* ns = malloc(sizeof(fson_namespace));
    if (ns == cnullptr) {
        printf("Memory allocation error\n");
        return cnullptr;
    }

    // Expect an identifier (namespace name)
    if ((*tokens)->type != FSON_TOKEN_IDENTIFIER) {
        printf("Error: Expected an identifier for namespace name\n");
        return cnullptr;
    }
    ns->name = _custom_fossil_core_strdup((*tokens)->value);
    (*tokens)++;

    // Expect a symbol '{'
    if ((*tokens)->type != FSON_TOKEN_SYMBOL || strcmp((*tokens)->value, "{") != 0) {
        printf("Error: Expected '{'\n");
        return cnullptr;
    }
    (*tokens)++;

    // Parse key-value pairs
    fson_value* values = malloc(sizeof(fson_value) * 100);
    if (values == cnullptr) {
        printf("Memory allocation error\n");
        return cnullptr;
    }
    int value_count = 0;
    while ((*tokens)->type != FSON_TOKEN_EOF) {
        // Expect an identifier (key)
        if ((*tokens)->type != FSON_TOKEN_IDENTIFIER) {
            printf("Error: Expected an identifier for key\n");
            return cnullptr;
        }
        char* key = _custom_fossil_core_strdup((*tokens)->value);
        (*tokens)++;

        // Expect a symbol ':'
        if ((*tokens)->type != FSON_TOKEN_SYMBOL || strcmp((*tokens)->value, ":") != 0) {
            printf("Error: Expected ':'\n");
            return cnullptr;
        }
        (*tokens)++;

        // Expect a value
        char* value = cnullptr;
        char* type = cnullptr;
        if ((*tokens)->type == FSON_TOKEN_STRING || (*tokens)->type == FSON_TOKEN_NUMBER) {
            value = _custom_fossil_core_strdup((*tokens)->value);
            type = _custom_fossil_core_strdup("str");  // Default type is string
            (*tokens)++;
        } else if ((*tokens)->type == FSON_TOKEN_IDENTIFIER) {
            type = _custom_fossil_core_strdup((*tokens)->value);
            (*tokens)++;
            if ((*tokens)->type != FSON_TOKEN_STRING && (*tokens)->type != FSON_TOKEN_NUMBER && strcmp((*tokens)->value, "cnull") != 0) {
                printf("Error: Expected a value after type\n");
                return cnullptr;
            }
            if (strcmp((*tokens)->value, "cnull") == 0) {
                value = cnullptr;
            } else {
                value = _custom_fossil_core_strdup((*tokens)->value);
            }
            (*tokens)++;
        } else {
            printf("Error: Expected a value\n");
            return cnullptr;
        }

        // Save the key-value pair
        values[value_count++] = (fson_value){key, value, get_type_id(type)};
    }
    // Add a NULL terminator to the values array
    values[value_count] = (fson_value){cnullptr, cnullptr, FSON_TYPE_UNKNOWN};

    ns->values = values;
    ns->count = value_count; // Set the count of values

    // Skip the symbol '}'
    (void)(*tokens);

    return ns;
}

// Find a namespace by name within an array of namespaces
fson_namespace* fossil_fson_namespace_find(fson_namespace* namespaces, int32_t count, const char* restrict name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(namespaces[i].name, name) == 0) {
            return &namespaces[i];
        }
    }
    return cnullptr;
}

// Erase a namespace and its contents
void fossil_fson_namespace_erase(fson_namespace* ns) {
    for (int i = 0; ns->values[i].key != cnullptr; i++) {
        free(ns->values[i].key);
        free(ns->values[i].value);
    }
    free(ns->values);
    free(ns->name);
    free(ns);
}

// Data manipulation functions

// Insert data into a namespace
int32_t fossil_fson_insert_data(fson_namespace* namespaces, const char* restrict key, const char* restrict value, const char* restrict type_name) {
    if (namespaces == cnullptr || key == cnullptr || value == cnullptr || type_name == cnullptr) {
        return -1; // Invalid arguments
    }

    // Get type ID from type name
    fson_type type = get_type_id(type_name);
    if (type == FSON_TYPE_UNKNOWN) {
        return -1; // Invalid type name
    }

    // Find the last value in the namespace
    int i;
    for (i = 0; namespaces->values[i].key != cnullptr; i++);
    
    // Reallocate memory for values array
    fson_value* new_values = realloc(namespaces->values, sizeof(fson_value) * (i + 2)); // +2 for new value and NULL terminator
    if (new_values == cnullptr) {
        return -1; // Memory allocation error
    }
    namespaces->values = new_values;

    // Insert the new value
    namespaces->values[i].key = _custom_fossil_core_strndup(key, strlen(key));
    namespaces->values[i].value = _custom_fossil_core_strndup(value, strlen(value));
    namespaces->values[i].type = type;
    namespaces->values[i + 1].key = cnullptr; // NULL terminator

    return 1; // Insertion successful
}

// Update data in a namespace
int32_t fossil_fson_update_data(fson_namespace* namespaces, const char* restrict key, const char* restrict value) {
    if (namespaces == cnullptr || key == cnullptr || value == cnullptr) {
        return -1; // Invalid arguments
    }

    // Find the value with the given key
    fson_value* existing_value = fossil_fson_search_data(namespaces, key);
    if (existing_value == cnullptr) {
        return 0; // Key does not exist
    }

    // Update the value
    free(existing_value->value);
    existing_value->value = _custom_fossil_core_strdup(value);

    return 1; // Update successful
}

// Remove data from a namespace
int32_t fossil_fson_remove_data(fson_namespace* namespaces, const char* restrict key) {
    if (namespaces == cnullptr || key == cnullptr) {
        return -1; // Invalid arguments
    }

    // Find the value with the given key
    fson_value* existing_value = fossil_fson_search_data(namespaces, key);
    if (existing_value == cnullptr) {
        return 0; // Key does not exist
    }

    // Free the memory for the value
    free(existing_value->key);
    free(existing_value->value);

    // Shift the remaining values to fill the gap
    fson_value* current_value = existing_value;
    fson_value* next_value = existing_value + 1;
    while (next_value->key != cnullptr) {
        current_value->key = next_value->key;
        current_value->value = next_value->value;
        current_value->type = next_value->type;
        current_value++;
        next_value++;
    }
    current_value->key = cnullptr; // NULL terminator

    return 1; // Removal successful
}

// Search for data in a namespace
fson_value* fossil_fson_search_data(fson_namespace* ns, const char* restrict key) {
    if (ns == cnullptr || key == cnullptr) {
        return cnullptr; // Invalid arguments
    }

    // Linear search for the key
    for (int i = 0; ns->values[i].key != cnullptr; i++) {
        if (strcmp(ns->values[i].key, key) == 0) {
            return &ns->values[i]; // Key found
        }
    }

    return cnullptr; // Key not found
}
