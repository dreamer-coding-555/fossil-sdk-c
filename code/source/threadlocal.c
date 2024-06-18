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

// Thread-local storage management

int32_t fossil_thread_local_create(fossil_xthread_local_t *key, void (*destructor)(void*)) {
    if (!key) return FOSSIL_ERROR;

#ifdef _WIN32
    key->key = TlsAlloc();
    (void)destructor;
    if (key->key == TLS_OUT_OF_INDEXES) return FOSSIL_ERROR;
    // Note: Windows does not provide a built-in way to call destructors on thread exit.
    // This requires additional handling to track and call destructors manually if needed.
    return FOSSIL_SUCCESS;
#else
    return pthread_key_create(&key->key, destructor) == 0 ? FOSSIL_SUCCESS : FOSSIL_ERROR;
#endif
}

int32_t fossil_thread_local_erase(fossil_xthread_local_t key) {
#ifdef _WIN32
    return TlsFree(key.key) ? FOSSIL_SUCCESS : FOSSIL_ERROR;
#else
    return pthread_key_delete(key.key) == 0 ? FOSSIL_SUCCESS : FOSSIL_ERROR;
#endif
}

void* fossil_thread_local_get(fossil_xthread_local_t key) {
#ifdef _WIN32
    return TlsGetValue(key.key);
#else
    return pthread_getspecific(key.key);
#endif
}

int32_t fossil_thread_local_set(fossil_xthread_local_t key, const void *value) {
#ifdef _WIN32
    return TlsSetValue(key.key, (LPVOID)value) ? FOSSIL_SUCCESS : FOSSIL_ERROR;
#else
    return pthread_setspecific(key.key, value) == 0 ? FOSSIL_SUCCESS : FOSSIL_ERROR;
#endif
}
