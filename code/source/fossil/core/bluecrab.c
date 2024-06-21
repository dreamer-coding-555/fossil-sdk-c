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
#include <ctype.h>

fossil_crabdb_t* fossil_crabdb_create(void) {
    fossil_crabdb_t *db = (fossil_crabdb_t*) malloc(sizeof(fossil_crabdb_t));
    if (!db) {
        return cnullptr;
    }
    db->namespaces = cnullptr;
    return db;
}

void fossil_crabdb_erase(fossil_crabdb_t *db) {
    if (!db) return;

    fossil_crabdb_namespace_t *current = db->namespaces;
    while (current) {
        fossil_crabdb_namespace_t *next = current->next;
        free(current->name);

        for (size_t i = 0; i < current->sub_namespace_count; i++) {
            free(current->sub_namespaces[i].name);
        }
        free(current->sub_namespaces);

        fossil_crabdb_keyvalue_t *kv = current->data;
        while (kv) {
            fossil_crabdb_keyvalue_t *kv_next = kv->next;
            free(kv->key);
            free(kv->value);
            free(kv);
            kv = kv_next;
        }

        free(current);
        current = next;
    }

    free(db);
}

fossil_crabdb_error_t fossil_crabdb_create_namespace(fossil_crabdb_t *db, const char *namespace_name) {
    if (!db || !namespace_name) return CRABDB_ERR_MEM;

    fossil_crabdb_namespace_t *current = db->namespaces;
    while (current) {
        if (strcmp(current->name, namespace_name) == 0) {
            return CRABDB_ERR_NS_EXISTS;
        }
        current = current->next;
    }

    fossil_crabdb_namespace_t *new_namespace = (fossil_crabdb_namespace_t*) malloc(sizeof(fossil_crabdb_namespace_t));
    if (!new_namespace) return CRABDB_ERR_MEM;

    new_namespace->name = _custom_fossil_strdup(namespace_name);
    new_namespace->sub_namespaces = cnullptr;
    new_namespace->sub_namespace_count = 0;
    new_namespace->next = db->namespaces;
    new_namespace->data = cnullptr;
    db->namespaces = new_namespace;

    return CRABDB_OK;
}

fossil_crabdb_error_t fossil_crabdb_create_sub_namespace(fossil_crabdb_t *db, const char *namespace_name, const char *sub_namespace_name) {
    if (!db || !namespace_name || !sub_namespace_name) return CRABDB_ERR_MEM;

    fossil_crabdb_namespace_t *current = db->namespaces;
    while (current) {
        if (strcmp(current->name, namespace_name) == 0) {
            for (size_t i = 0; i < current->sub_namespace_count; i++) {
                if (strcmp(current->sub_namespaces[i].name, sub_namespace_name) == 0) {
                    return CRABDB_ERR_SUB_NS_EXISTS;
                }
            }

            current->sub_namespaces = (fossil_crabdb_namespace_t*) realloc(current->sub_namespaces, sizeof(fossil_crabdb_namespace_t) * (current->sub_namespace_count + 1));
            if (!current->sub_namespaces) return CRABDB_ERR_MEM;

            current->sub_namespaces[current->sub_namespace_count].name = _custom_fossil_strdup(sub_namespace_name);
            current->sub_namespaces[current->sub_namespace_count].sub_namespaces = cnullptr;
            current->sub_namespaces[current->sub_namespace_count].sub_namespace_count = 0;
            current->sub_namespaces[current->sub_namespace_count].next = cnullptr;
            current->sub_namespaces[current->sub_namespace_count].data = cnullptr;

            current->sub_namespace_count++;
            return CRABDB_OK;
        }
        current = current->next;
    }

    return CRABDB_ERR_NS_NOT_FOUND;
}

fossil_crabdb_error_t fossil_crabdb_erase_namespace(fossil_crabdb_t *db, const char *namespace_name) {
    if (!db || !namespace_name) return CRABDB_ERR_MEM;

    fossil_crabdb_namespace_t *prev = cnullptr;
    fossil_crabdb_namespace_t *current = db->namespaces;

    while (current) {
        if (strcmp(current->name, namespace_name) == 0) {
            if (prev) {
                prev->next = current->next;
            } else {
                db->namespaces = current->next;
            }

            free(current->name);

            for (size_t i = 0; i < current->sub_namespace_count; i++) {
                free(current->sub_namespaces[i].name);
            }
            free(current->sub_namespaces);

            fossil_crabdb_keyvalue_t *kv = current->data;
            while (kv) {
                fossil_crabdb_keyvalue_t *kv_next = kv->next;
                free(kv->key);
                free(kv->value);
                free(kv);
                kv = kv_next;
            }

            free(current);
            return CRABDB_OK;
        }
        prev = current;
        current = current->next;
    }

    return CRABDB_ERR_NS_NOT_FOUND;
}

fossil_crabdb_error_t fossil_crabdb_erase_sub_namespace(fossil_crabdb_t *db, const char *namespace_name, const char *sub_namespace_name) {
    if (!db || !namespace_name || !sub_namespace_name) return CRABDB_ERR_MEM;

    fossil_crabdb_namespace_t *current = db->namespaces;
    while (current) {
        if (strcmp(current->name, namespace_name) == 0) {
            for (size_t i = 0; i < current->sub_namespace_count; i++) {
                if (strcmp(current->sub_namespaces[i].name, sub_namespace_name) == 0) {
                    free(current->sub_namespaces[i].name);

                    for (size_t j = i; j < current->sub_namespace_count - 1; j++) {
                        current->sub_namespaces[j] = current->sub_namespaces[j + 1];
                    }

                    current->sub_namespaces = (fossil_crabdb_namespace_t*) realloc(current->sub_namespaces, sizeof(fossil_crabdb_namespace_t) * (current->sub_namespace_count - 1));
                    current->sub_namespace_count--;

                    return CRABDB_OK;
                }
            }
        }
        current = current->next;
    }

    return CRABDB_ERR_SUB_NS_NOT_FOUND;
}

fossil_crabdb_error_t fossil_crabdb_insert(fossil_crabdb_t *db, const char *namespace_name, const char *key, const char *value) {
    if (!db || !namespace_name || !key || !value) return CRABDB_ERR_MEM;

    fossil_crabdb_namespace_t *current = db->namespaces;
    while (current) {
        if (strcmp(current->name, namespace_name) == 0) {
            fossil_crabdb_keyvalue_t *kv = current->data;
            while (kv) {
                if (strcmp(kv->key, key) == 0) {
                    return CRABDB_ERR_KEY_NOT_FOUND; // Key already exists
                }
                kv = kv->next;
            }

            fossil_crabdb_keyvalue_t *new_kv = (fossil_crabdb_keyvalue_t*) malloc(sizeof(fossil_crabdb_keyvalue_t));
            if (!new_kv) return CRABDB_ERR_MEM;

            new_kv->key = _custom_fossil_strdup(key);
            new_kv->value = _custom_fossil_strdup(value);
            new_kv->next = current->data;
            current->data = new_kv;

            return CRABDB_OK;
        }
        current = current->next;
    }

    return CRABDB_ERR_NS_NOT_FOUND;
}

fossil_crabdb_error_t fossil_crabdb_get(fossil_crabdb_t *db, const char *namespace_name, const char *key, char **value) {
    if (!db || !namespace_name || !key || !value) return CRABDB_ERR_MEM;

    fossil_crabdb_namespace_t *current = db->namespaces;
    while (current) {
        if (strcmp(current->name, namespace_name) == 0) {
            fossil_crabdb_keyvalue_t *kv = current->data;
            while (kv) {
                if (strcmp(kv->key, key) == 0) {
                    *value = _custom_fossil_strdup(kv->value);
                    return CRABDB_OK;
                }
                kv = kv->next;
            }
            return CRABDB_ERR_KEY_NOT_FOUND;
        }
        current = current->next;
    }

    return CRABDB_ERR_NS_NOT_FOUND;
}

fossil_crabdb_error_t fossil_crabdb_update(fossil_crabdb_t *db, const char *namespace_name, const char *key, const char *value) {
    if (!db || !namespace_name || !key || !value) return CRABDB_ERR_MEM;

    fossil_crabdb_namespace_t *current = db->namespaces;
    while (current) {
        if (strcmp(current->name, namespace_name) == 0) {
            fossil_crabdb_keyvalue_t *kv = current->data;
            while (kv) {
                if (strcmp(kv->key, key) == 0) {
                    free(kv->value);
                    kv->value = _custom_fossil_strdup(value);
                    return CRABDB_OK;
                }
                kv = kv->next;
            }
            return CRABDB_ERR_KEY_NOT_FOUND;
        }
        current = current->next;
    }

    return CRABDB_ERR_NS_NOT_FOUND;
}

fossil_crabdb_error_t fossil_crabdb_delete(fossil_crabdb_t *db, const char *namespace_name, const char *key) {
    if (!db || !namespace_name || !key) return CRABDB_ERR_MEM;

    fossil_crabdb_namespace_t *current = db->namespaces;
    while (current) {
        if (strcmp(current->name, namespace_name) == 0) {
            fossil_crabdb_keyvalue_t *prev = cnullptr;
            fossil_crabdb_keyvalue_t *kv = current->data;
            while (kv) {
                if (strcmp(kv->key, key) == 0) {
                    if (prev) {
                        prev->next = kv->next;
                    } else {
                        current->data = kv->next;
                    }
                    free(kv->key);
                    free(kv->value);
                    free(kv);
                    return CRABDB_OK;
                }
                prev = kv;
                kv = kv->next;
            }
            return CRABDB_ERR_KEY_NOT_FOUND;
        }
        current = current->next;
    }

    return CRABDB_ERR_NS_NOT_FOUND;
}

static fossil_crabdb_error_t parse_and_execute(fossil_crabdb_t *db, char *command, char **tokens, int token_count) {
    if (strcmp(command, "create_namespace") == 0) {
        if (token_count == 1) {
            return fossil_crabdb_create_namespace(db, tokens[0]);
        }
    } else if (strcmp(command, "create_sub_namespace") == 0) {
        if (token_count == 2) {
            return fossil_crabdb_create_sub_namespace(db, tokens[0], tokens[1]);
        }
    } else if (strcmp(command, "erase_namespace") == 0) {
        if (token_count == 1) {
            return fossil_crabdb_erase_namespace(db, tokens[0]);
        }
    } else if (strcmp(command, "erase_sub_namespace") == 0) {
        if (token_count == 2) {
            return fossil_crabdb_erase_sub_namespace(db, tokens[0], tokens[1]);
        }
    } else if (strcmp(command, "insert") == 0) {
        if (token_count == 3) {
            return fossil_crabdb_insert(db, tokens[0], tokens[1], tokens[2]);
        }
    } else if (strcmp(command, "get") == 0) {
        if (token_count == 2) {
            char *value;
            fossil_crabdb_error_t err = fossil_crabdb_get(db, tokens[0], tokens[1], &value);
            if (err == CRABDB_OK) {
                printf("Value: %s\n", value);
                free(value);
            }
            return err;
        }
    } else if (strcmp(command, "update") == 0) {
        if (token_count == 3) {
            return fossil_crabdb_update(db, tokens[0], tokens[1], tokens[2]);
        }
    } else if (strcmp(command, "delete") == 0) {
        if (token_count == 2) {
            return fossil_crabdb_delete(db, tokens[0], tokens[1]);
        }
    }
    return CRABDB_ERR_INVALID_QUERY;
}

fossil_crabdb_error_t fossil_crabdb_execute_query(fossil_crabdb_t *db, const char *query) {
    if (!db || !query) return CRABDB_ERR_INVALID_QUERY;

    char *query_copy = _custom_fossil_strdup(query);
    if (!query_copy) return CRABDB_ERR_MEM;

    char *command = strtok(query_copy, "(");
    if (!command) {
        free(query_copy);
        return CRABDB_ERR_INVALID_QUERY;
    }

    char *args = strtok(cnullptr, ")");
    if (!args) {
        free(query_copy);
        return CRABDB_ERR_INVALID_QUERY;
    }

    // Trim spaces from the command
    while (isspace((unsigned char)*command)) command++;
    char *end = command + strlen(command) - 1;
    while (end > command && isspace((unsigned char)*end)) end--;
    end[1] = '\0';

    // Tokenize the arguments
    char *token;
    char *tokens[10]; // Assuming a max of 10 arguments
    int token_count = 0;
    token = strtok(args, ",");
    while (token) {
        while (isspace((unsigned char)*token)) token++;
        char *end = token + strlen(token) - 1;
        while (end > token && isspace((unsigned char)*end)) end--;
        end[1] = '\0';
        tokens[token_count++] = token;
        token = strtok(cnullptr, ",");
    }

    fossil_crabdb_error_t result = parse_and_execute(db, command, tokens, token_count);

    free(query_copy);
    return result;
}
