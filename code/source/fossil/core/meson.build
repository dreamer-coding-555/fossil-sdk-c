fossil_sdk_core_lib = library('fossil-sdk-core',
    files('command.c', 'random.c', 'filesystem.c', 'arguments.c',
          'bitwise.c', 'money.c', 'memory.c', 'hostsystem.c',
          'smartptr.c', 'datetime.c', 'fson.c', 'regex.c'),
    dependencies : code_deps,
    install: true,
    include_directories: dir)

fossil_sdk_core_dep = declare_dependency(
    link_with: [fossil_sdk_core_lib],
    dependencies : code_deps,
    include_directories: dir)