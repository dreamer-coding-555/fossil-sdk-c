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
#include "fossil/structures/map.h"
#include "fossil/common/common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================

fossil_map_t* fossil_map_create(fossil_tofu_type list_type) {
    fossil_map_t* new_map = (fossil_map_t*)malloc(sizeof(fossil_map_t));
    if (new_map == cnullptr) {
        // Handle memory allocation failure
        return cnullptr;
    }

    new_map->size = 0;
    new_map->type = list_type;  // Store the list type in the fossil_map_t

    // Initialize keys and values based on the list_type
    for (size_t i = 0; i < MAX_MAP_SIZE; i++) {
        new_map->keys[i].type = list_type;
        new_map->values[i].type = list_type;
        
        switch (list_type) {
            case TOFU_INT_TYPE:
                new_map->keys[i].data.int_type = 0;
                new_map->values[i].data.int_type = 0;
                break;
            case TOFU_UINT_TYPE:
                new_map->keys[i].data.uint_type = 0;
                new_map->values[i].data.uint_type = 0;
                break;
            case TOFU_STRING_TYPE:
                new_map->keys[i].data.string_type = cnullptr;
                new_map->values[i].data.string_type = cnullptr;
                break;
            case TOFU_CHAR_TYPE:
                new_map->keys[i].data.char_type = '\0';
                new_map->values[i].data.char_type = '\0';
                break;
            case TOFU_BOOLEAN_TYPE:
                new_map->keys[i].data.boolean_type = false;
                new_map->values[i].data.boolean_type = false;
                break;
            case TOFU_ARRAY_TYPE:
                new_map->keys[i].data.array_type.elements = cnullptr;
                new_map->keys[i].data.array_type.size = 0;
                new_map->values[i].data.array_type.elements = cnullptr;
                new_map->values[i].data.array_type.size = 0;
                break;
            case TOFU_MAP_TYPE:
                new_map->keys[i].data.map_type.key = cnullptr;
                new_map->keys[i].data.map_type.value = cnullptr;
                new_map->keys[i].data.map_type.size = 0;
                new_map->values[i].data.map_type.key = cnullptr;
                new_map->values[i].data.map_type.value = cnullptr;
                new_map->values[i].data.map_type.size = 0;
                break;
            case TOFU_NULLPTR_TYPE:
                new_map->keys[i].data.nullptr_type = cnullptr;
                new_map->values[i].data.nullptr_type = cnullptr;
                break;
            default:
                // Initialize other types if necessary
                break;
        }
    }

    return new_map;
}

void fossil_map_erase(fossil_map_t* map) {
    if (map == cnullptr) {
        return;
    }

    free(map);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

fossil_tofu_error_t fossil_map_insert(fossil_map_t* map, fossil_tofu_t key, fossil_tofu_t value) {
    if (map == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    if (map->size >= MAX_MAP_SIZE) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Map is full
    }

    // Check if the key already exists
    for (size_t i = 0; i < map->size; ++i) {
        if (fossil_tofu_compare(&map->keys[i], &key) == 0) {
            return fossil_tofu_error(FOSSIL_TOFU_ERROR_TYPE_MISMATCH); // Duplicate key
        }
    }

    map->keys[map->size] = key;
    map->values[map->size] = value;
    map->size++;

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

fossil_tofu_error_t fossil_map_remove(fossil_map_t* map, fossil_tofu_t key) {
    if (map == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    size_t index = MAX_MAP_SIZE;

    // Find the index of the key
    for (size_t i = 0; i < map->size; ++i) {
        if (fossil_tofu_compare(&map->keys[i], &key) == 0) {
            index = i;
            break;
        }
    }

    if (index == MAX_MAP_SIZE) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Key not found
    }

    // Shift elements to fill the gap
    for (size_t i = index; i < map->size - 1; ++i) {
        map->keys[i] = map->keys[i + 1];
        map->values[i] = map->values[i + 1];
    }

    map->size--;

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
}

fossil_tofu_error_t fossil_map_search(fossil_map_t* map, fossil_tofu_t key) {
    if (map == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    for (size_t i = 0; i < map->size; ++i) {
        if (fossil_tofu_compare(&map->keys[i], &key) == 0) {
            return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK); // Found
        }
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Key not found
}

// =======================
// UTILITY FUNCTIONS
// =======================

size_t fossil_map_size(fossil_map_t* map) {
    if (map == cnullptr) {
        return 0;
    }

    return map->size;
}

fossil_tofu_error_t fossil_map_getter(fossil_map_t* map, fossil_tofu_t key, fossil_tofu_t* value) {
    if (map == cnullptr || value == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    for (size_t i = 0; i < map->size; ++i) {
        if (fossil_tofu_compare(&map->keys[i], &key) == 0) {
            *value = map->values[i];
            return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK); // Found
        }
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Key not found
}

fossil_tofu_error_t fossil_map_setter(fossil_map_t* map, fossil_tofu_t key, fossil_tofu_t value) {
    if (map == cnullptr) {
        return fossil_tofu_error(FOSSIL_TOFU_ERROR_NULL_POINTER);
    }

    for (size_t i = 0; i < map->size; ++i) {
        if (fossil_tofu_compare(&map->keys[i], &key) == 0) {
            // Found, update the value
            map->values[i] = value;
            return fossil_tofu_error(FOSSIL_TOFU_ERROR_OK);
        }
    }

    return fossil_tofu_error(FOSSIL_TOFU_ERROR_INDEX_OUT_OF_BOUNDS); // Key not found
}

bool fossil_map_not_empty(fossil_map_t* map) {
    return map != cnullptr && map->size > 0;
}

bool fossil_map_not_cnullptr(fossil_map_t* map) {
    return map != cnullptr;
}

bool fossil_map_is_empty(fossil_map_t* map) {
    return map == cnullptr || map->size == 0;
}

bool fossil_map_is_cnullptr(fossil_map_t* map) {
    return map == cnullptr;
}

bool fossil_map_contains(fossil_map_t* map, fossil_tofu_t key) {
    if (map == cnullptr) {
        return false;
    }

    for (size_t i = 0; i < map->size; ++i) {
        if (fossil_tofu_compare(&map->keys[i], &key) == 0) {
            return true; // Found
        }
    }

    return false; // Key not found
}

// =======================
// ITERATOR FUNCTIONS
// =======================
fossil_tofu_iterator fossil_map_iterator_start(fossil_map_t* map) {
    fossil_tofu_iterator iterator;
    iterator.current_key = map->keys;
    iterator.current_value = map->values;
    iterator.index = 0;

    return iterator;
}

fossil_tofu_iterator fossil_map_iterator_end(fossil_map_t* map) {
    fossil_tofu_iterator iterator;
    iterator.current_key = map->keys + map->size;
    iterator.current_value = map->values + map->size;
    iterator.index = map->size;

    return iterator;
}

fossil_tofu_iterator fossil_map_iterator_next(fossil_tofu_iterator iterator) {
    iterator.current_key++;
    iterator.current_value++;
    iterator.index++;

    return iterator;
}

bool fossil_map_iterator_has_next(fossil_tofu_iterator iterator) {
    return iterator.index < MAX_MAP_SIZE;
}
