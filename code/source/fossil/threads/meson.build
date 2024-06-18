fossil_sdk_threads_lib = library('fossil-sdk-threads',
    files('barrier.c', 'mutexs.c', 'semaphores.c', 'thread.c',
          'threadpool.c', 'threadlocal.c', 'condition.c',  'spinlocks.c'),
    dependencies : code_deps,
    install: true,
    include_directories: dir)

fossil_sdk_threads_dep = declare_dependency(
    link_with: [fossil_sdk_threads_lib],
    dependencies : code_deps,
    include_directories: dir)