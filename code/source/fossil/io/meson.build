fossil_sdk_io_lib = library('fossil-sdk-io',
    files('fstream.c', 'istream.c', 'ostream.c', 'soap.c'),
    dependencies : code_deps,
    install: true,
    include_directories: dir)

fossil_sdk_io_dep = declare_dependency(
    link_with: [fossil_sdk_io_lib],
    dependencies : code_deps,
    include_directories: dir)