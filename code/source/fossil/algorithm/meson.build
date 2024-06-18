fossil_sdk_algorithm_lib = library('fossil-sdk-algorithm',
    files('sort.c', 'search.c', 'greedy.c', 'dynamic.c', 'summary.c'),
    dependencies : code_deps,
    install: true,
    include_directories: dir)

fossil_sdk_algorithm_dep = declare_dependency(
    link_with: [fossil_sdk_algorithm_lib],
    dependencies : code_deps,
    include_directories: dir)