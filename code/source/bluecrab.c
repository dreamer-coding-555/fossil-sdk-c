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
#include "fossil/core/bluecrab.h"
#include "fossil/common/common.h"
#include <ctype.h>
#include <string.h>

// Helper function to find a namespace by name
static fson_namespace* find_namespace(fossil_crabdb_t* db, const char* name) {
    for (int i = 0; i < db->count; ++i) {
        if (strcmp(db->namespaces[i].name, name) == 0) {
            return &db->namespaces[i];
        }
    }
    return cnullptr;
}

fossil_crabdb_t* fossil_crabdb_create(const char* name) {
    fossil_crabdb_t* db = (fossil_crabdb_t*)malloc(sizeof(fossil_crabdb_t));
    if (db) {
        db->name = _custom_fossil_strdup(name);
        if (db->name == cnullptr) {
            free(db);
            return cnullptr;
        }
        db->namespaces = cnullptr;
        db->count = 0;
    }
    return db;
}

void fossil_crabdb_erase(fossil_crabdb_t* db) {
    if (db) {
        for (int i = 0; i < db->count; ++i) {
            free(db->namespaces[i].name);
            free(db->namespaces[i].values);
        }
        free(db->name);
        free(db->namespaces);
        free(db);
    }
}

int32_t fossil_crabdb_create_namespace(fossil_crabdb_t* db, const char* name) {
    if (find_namespace(db, name) != cnullptr) {
        return 0; // Namespace already exists
    }
    fson_namespace* new_namespaces = (fson_namespace*)realloc(db->namespaces, (db->count + 1) * sizeof(fson_namespace));
    if (new_namespaces == cnullptr) {
        return -1; // Memory allocation failed
    }
    db->namespaces = new_namespaces;
    db->namespaces[db->count].name = _custom_fossil_strdup(name);
    if (db->namespaces[db->count].name == cnullptr) {
        return -1; // Memory allocation failed
    }
    db->namespaces[db->count].values = cnullptr;
    ++db->count;
    return 1; // Namespace created successfully
}

int32_t fossil_crabdb_insert_data(fossil_crabdb_t* db, const char* namespace_name, const char* key, const char* value, const char* type) {
    if (!db || !namespace_name || !key || !value || !type) {
        return -1; // Invalid input parameters
    }

    // Find the namespace
    fson_namespace* ns = find_namespace(db, namespace_name);
    if (ns == cnullptr) {
        return -1; // Namespace not found
    }

    // Check if the key already exists
    fson_value* existing_value = fossil_fson_search_data(ns, key);
    if (existing_value != cnullptr) {
        return 0; // Key already exists
    }

    // Allocate memory for the new value
    fson_value new_value;
    new_value.key = _custom_fossil_strdup(key);
    if (new_value.key == cnullptr) {
        return -1; // Memory allocation failed
    }
    new_value.value = _custom_fossil_strdup(value);
    if (new_value.value == cnullptr) {
        free(new_value.key);
        return -1; // Memory allocation failed
    }

    // Determine the type
    if (strcmp(type, "str") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_STR;
    } else if (strcmp(type, "i8") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_I8;
    } else if (strcmp(type, "i16") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_I16;
    } else if (strcmp(type, "i32") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_I32;
    } else if (strcmp(type, "i64") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_I64;
    } else if (strcmp(type, "u8") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_U8;
    } else if (strcmp(type, "u16") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_U16;
    } else if (strcmp(type, "u32") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_U32;
    } else if (strcmp(type, "u64") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_U64;
    } else if (strcmp(type, "o8") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_O8;
    } else if (strcmp(type, "o16") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_O16;
    } else if (strcmp(type, "o32") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_O32;
    } else if (strcmp(type, "o64") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_O64;
    } else if (strcmp(type, "b8") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_B8;
    } else if (strcmp(type, "b16") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_B16;
    } else if (strcmp(type, "b32") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_B32;
    } else if (strcmp(type, "b64") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_B64;
    } else if (strcmp(type, "h8") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_H8;
    } else if (strcmp(type, "h16") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_H16;
    } else if (strcmp(type, "h32") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_H32;
    } else if (strcmp(type, "h64") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_H64;
    } else if (strcmp(type, "float") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_FLOAT;
    } else if (strcmp(type, "double") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_DOUBLE;
    } else if (strcmp(type, "bool") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_BOOL;
    } else if (strcmp(type, "null") == 0) {
        new_value.type = FOSSIL_FSON_TYPE_CNULL;
    } else {
        free(new_value.key);
        free(new_value.value);
        return -1; // Invalid type
    }

    // Reallocate memory for the values array
    fson_value* new_values = (fson_value*)realloc(ns->values, (ns->count + 1) * sizeof(fson_value));
    if (new_values == cnullptr) {
        free(new_value.key);
        free(new_value.value);
        return -1; // Memory allocation failed
    }
    ns->values = new_values;

    // Add the new value
    ns->values[ns->count] = new_value;
    ++ns->count;

    return 1; // Insertion successful
}

int32_t fossil_crabdb_update_data(fossil_crabdb_t* db, const char* namespace_name, const char* key, const char* value) {
    if (!db || !namespace_name || !key || !value) {
        return -1; // Invalid input parameters
    }

    // Find the namespace
    fson_namespace* ns = find_namespace(db, namespace_name);
    if (ns == cnullptr) {
        return -1; // Namespace not found
    }

    // Search for the value by key
    fson_value* existing_value = fossil_fson_search_data(ns, key);
    if (existing_value == cnullptr) {
        return 0; // Key not found
    }

    // Update the value
    char* new_value = _custom_fossil_strdup(value);
    if (new_value == cnullptr) {
        return -1; // Memory allocation failed
    }
    free(existing_value->value);
    existing_value->value = new_value;

    return 1; // Update successful
}

int32_t fossil_crabdb_remove_data(fossil_crabdb_t* db, const char* namespace_name, const char* key) {
    if (!db || !namespace_name || !key) {
        return -1; // Invalid input parameters
    }

    // Find the namespace
    fson_namespace* ns = find_namespace(db, namespace_name);
    if (ns == cnullptr) {
        return -1; // Namespace not found
    }

    // Search for the value by key
    int found_index = -1;
    for (int i = 0; i < ns->count; ++i) {
        if (strcmp(ns->values[i].key, key) == 0) {
            found_index = i;
            break;
        }
    }
    if (found_index == -1) {
        return 0; // Key not found
    }

    // Free memory for the value
    free(ns->values[found_index].key);
    free(ns->values[found_index].value);

    // Shift elements to remove the value
    for (int i = found_index; i < ns->count - 1; ++i) {
        ns->values[i] = ns->values[i + 1];
    }
    --ns->count;

    return 1; // Removal successful
}

fson_value* fossil_crabdb_search_data(fossil_crabdb_t* db, const char* namespace_name, const char* key) {
    if (!db || !namespace_name || !key) {
        return cnullptr; // Invalid input parameters
    }

    // Find the namespace
    fson_namespace* ns = find_namespace(db, namespace_name);
    if (ns == cnullptr) {
        return cnullptr; // Namespace not found
    }

    // Search for the value by key
    for (int i = 0; i < ns->count; ++i) {
        if (strcmp(ns->values[i].key, key) == 0) {
            return &ns->values[i]; // Value found
        }
    }

    return cnullptr; // Value not found
}

void fossil_crabdb_display_namespace(fossil_crabdb_t* db, const char* namespace_name) {
    if (!db || !namespace_name) {
        printf("Invalid input parameters.\n");
        return;
    }

    // Find the namespace
    fson_namespace* ns = find_namespace(db, namespace_name);
    if (ns == cnullptr) {
        printf("Namespace '%s' not found.\n", namespace_name);
        return;
    }

    printf("Namespace: %s\n", namespace_name);
    printf("----------------------------\n");
    for (int i = 0; i < ns->count; ++i) {
        printf("Key: %s, Value: %s\n", ns->values[i].key, ns->values[i].value);
    }
    printf("----------------------------\n");
}

// Blue CrabDB execute command syntax:
//
// create_namespace('namespace_name')
// insert_data('namespace_name', key: 'some key', value: 'some value', type: 'str')
// update_data('namespace_name', key: 'some key', value: 'new value')
// remove_data('namespace_name', key: 'some key')
// search_data('namespace_name', key: 'some key')
// display_namespace('namespace_name')
void fossil_crabdb_execute_query(fossil_crabdb_t* db, const char* query) {
    // Tokenize the query string
    char* token;
    char query_copy[strlen(query) + 1];
    strcpy(query_copy, query);

    // Parse and execute each command in the query
    token = strtok(query_copy, " ");
    while (token != cnullptr) {
        if (strcmp(token, "create_namespace") == 0) {
            token = strtok(cnullptr, " ");
            fossil_crabdb_create_namespace(db, token);
        } else if (strcmp(token, "insert_data") == 0) {
            char* namespace_name = strtok(cnullptr, " ");
            char* key = strtok(cnullptr, " ");
            char* value = strtok(cnullptr, " ");
            char* type = strtok(cnullptr, " ");
            fossil_crabdb_insert_data(db, namespace_name, key, value, type);
        } else if (strcmp(token, "update_data") == 0) {
            char* namespace_name = strtok(cnullptr, " ");
            char* key = strtok(cnullptr, " ");
            char* value = strtok(cnullptr, " ");
            fossil_crabdb_update_data(db, namespace_name, key, value);
        } else if (strcmp(token, "remove_data") == 0) {
            char* namespace_name = strtok(cnullptr, " ");
            char* key = strtok(cnullptr, " ");
            fossil_crabdb_remove_data(db, namespace_name, key);
        } else if (strcmp(token, "search_data") == 0) {
            char* namespace_name = strtok(cnullptr, " ");
            char* key = strtok(cnullptr, " ");
            fossil_crabdb_search_data(db, namespace_name, key);
        } else if (strcmp(token, "display_namespace") == 0) {
            char* namespace_name = strtok(cnullptr, " ");
            fossil_crabdb_display_namespace(db, namespace_name);
        }
        token = strtok(cnullptr, " ");
    }
}
