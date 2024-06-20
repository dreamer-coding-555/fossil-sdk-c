subdir('io')
subdir('ai')
subdir('core')
subdir('strings')
subdir('threads')
subdir('generic')
subdir('algorithm')
subdir('structure')

fossil_sdk_dep = declare_dependency(
    link_with: [
        fossil_sdk_io_lib,
        fossil_sdk_ai_lib,
        fossil_sdk_core_lib,
        fossil_sdk_strings_lib,
        fossil_sdk_algorithm_lib,
        fossil_sdk_structure_lib,
        fossil_sdk_threads_lib,
        fossil_sdk_generic_lib],
    dependencies : code_deps,
    include_directories: dir)
