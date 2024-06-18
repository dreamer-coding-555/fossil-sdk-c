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
#include "fossil/threads/threadlocal.h"
#include "fossil/common/common.h"

// Thread-local storage destructor list node
typedef struct fossil_tls_dtor_node {
    fossil_xthread_local_t key;
    void (*destructor)(void*);
    struct fossil_tls_dtor_node *next;
} fossil_tls_dtor_node_t;

#ifdef _WIN32
// Thread-local storage key for managing destructors
static DWORD tls_dtor_key = TLS_OUT_OF_INDEXES;

// Function to call destructors on thread exit
static void NTAPI tls_dtor_callback(void) {
    fossil_tls_dtor_node_t *node = (fossil_tls_dtor_node_t*)TlsGetValue(tls_dtor_key);
    while (node) {
        void *value = TlsGetValue(node->key);
        if (value && node->destructor) {
            node->destructor(value);
        }
        node = node->next;
    }
}

static int32_t initialize_tls_dtor_key(void) {
    if (tls_dtor_key == TLS_OUT_OF_INDEXES) {
        tls_dtor_key = TlsAlloc();
        if (tls_dtor_key == TLS_OUT_OF_INDEXES) return FOSSIL_ERROR;
        if (!TlsSetValue(tls_dtor_key, NULL)) return FOSSIL_ERROR;
        if (!Fossil_AddThreadExitCallback(tls_dtor_callback)) return FOSSIL_ERROR; // Custom API to register thread exit callback
    }
    return FOSSIL_SUCCESS;
}
#endif

int32_t fossil_thread_local_create(fossil_xthread_local_t *key, void (*destructor)(void*)) {
    if (!key) return FOSSIL_ERROR;

#ifdef _WIN32
    if (initialize_tls_dtor_key() != FOSSIL_SUCCESS) return FOSSIL_ERROR;

    *key = TlsAlloc();
    if (*key == TLS_OUT_OF_INDEXES) return FOSSIL_ERROR;

    if (destructor) {
        fossil_tls_dtor_node_t *node = (fossil_tls_dtor_node_t*)malloc(sizeof(fossil_tls_dtor_node_t));
        if (!node) return FOSSIL_ERROR;
        node->key = *key;
        node->destructor = destructor;
        node->next = (fossil_tls_dtor_node_t*)TlsGetValue(tls_dtor_key);
        if (!TlsSetValue(tls_dtor_key, node)) {
            free(node);
            return FOSSIL_ERROR;
        }
    }
    return FOSSIL_SUCCESS;
#else
    return pthread_key_create(key, destructor) == 0 ? FOSSIL_SUCCESS : FOSSIL_ERROR;
#endif
}

int32_t fossil_thread_local_erase(fossil_xthread_local_t key) {
    if (key == 0) return FOSSIL_ERROR; // Zero is not a valid key

#ifdef _WIN32
    if (!TlsFree(key)) return FOSSIL_ERROR;
    // Remove destructor node if exists
    fossil_tls_dtor_node_t *prev = NULL;
    fossil_tls_dtor_node_t *node = (fossil_tls_dtor_node_t*)TlsGetValue(tls_dtor_key);
    while (node) {
        if (node->key == key) {
            if (prev) {
                prev->next = node->next;
            } else {
                TlsSetValue(tls_dtor_key, node->next);
            }
            free(node);
            break;
        }
        prev = node;
        node = node->next;
    }
    return FOSSIL_SUCCESS;
#else
    return pthread_key_delete(key) == 0 ? FOSSIL_SUCCESS : FOSSIL_ERROR;
#endif
}

void* fossil_thread_local_get(fossil_xthread_local_t key) {
#ifdef _WIN32
    return TlsGetValue(key);
#else
    return pthread_getspecific(key);
#endif
}

int32_t fossil_thread_local_set(fossil_xthread_local_t key, const void *value) {
#ifdef _WIN32
    return TlsSetValue(key, (LPVOID)value) ? FOSSIL_SUCCESS : FOSSIL_ERROR;
#else
    return pthread_setspecific(key, value) == 0 ? FOSSIL_SUCCESS : FOSSIL_ERROR;
#endif
}
