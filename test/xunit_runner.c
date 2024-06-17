
// Generated Fossil Logic Test

#include <fossil/unittest.h>


// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test List
// * * * * * * * * * * * * * * * * * * * * * * * *

FOSSIL_TEST_EXPORT(localthreads_group);
FOSSIL_TEST_EXPORT(sem_group);
FOSSIL_TEST_EXPORT(cond_group);
FOSSIL_TEST_EXPORT(poolthreads_group);
FOSSIL_TEST_EXPORT(threads_group);
FOSSIL_TEST_EXPORT(spinlocks_group);
FOSSIL_TEST_EXPORT(mutexs_group);

// * * * * * * * * * * * * * * * * * * * * * * * *
// * Fossil Logic Test Runner
// * * * * * * * * * * * * * * * * * * * * * * * *
int main(int argc, char **argv) {
    FOSSIL_TEST_CREATE(argc, argv);
    FOSSIL_TEST_IMPORT(localthreads_group);
    FOSSIL_TEST_IMPORT(sem_group);
    FOSSIL_TEST_IMPORT(poolthreads_group);
    FOSSIL_TEST_IMPORT(threads_group);
    FOSSIL_TEST_IMPORT(spinlocks_group);
    FOSSIL_TEST_IMPORT(mutexs_group);

    FOSSIL_TEST_RUN();
    return FOSSIL_TEST_ERASE();
} // end of func
