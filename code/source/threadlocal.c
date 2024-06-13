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

int32_t fossil_thread_local_create(fossil_xthread_local_t *key, void (*destructor)(void*)) {
    if (!key) return FOSSIL_ERROR;

#ifdef _WIN32
    *key = TlsAlloc();
    if (*key == TLS_OUT_OF_INDEXES) return FOSSIL_ERROR;
    if (destructor) TlsSetValue(*key, cnullptr); // Set initial value to NULL
    return FOSSIL_SUCCESS;
#else
    return pthread_key_create(key, destructor);
#endif
}

int32_t fossil_thread_local_erase(fossil_xthread_local_t key) {
    if (key == 0) return FOSSIL_ERROR; // Zero is not a valid key

#ifdef _WIN32
    return TlsFree(key) ? FOSSIL_SUCCESS : FOSSIL_ERROR;
#else
    return pthread_key_delete(key);
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
    return pthread_setspecific(key, value);
#endif
}
