fossil_sdk_generic_lib = library('fossil-sdk-generic',
    files('tofu.c'),
    dependencies : code_deps,
    install: true,
    include_directories: dir)

fossil_sdk_generic_dep = declare_dependency(
    link_with: [fossil_sdk_generic_lib],
    dependencies : code_deps,
    include_directories: dir)