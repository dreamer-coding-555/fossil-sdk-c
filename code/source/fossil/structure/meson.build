fossil_sdk_structure_lib = library('fossil-sdk-structure',
    files('queue.c', 'pqueue.c', 'dqueue.c', 'flist.c',
          'dlist.c', 'tree.c', 'set.c', 'stack.c',
          'vector.c'),
    dependencies : [code_deps, fossil_sdk_generic_dep],
    install: true,
    include_directories: dir)

fossil_sdk_structure_dep = declare_dependency(
    link_with: [fossil_sdk_structure_lib],
    dependencies : [code_deps, fossil_sdk_generic_dep],
    include_directories: dir)