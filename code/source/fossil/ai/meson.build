fossil_sdk_ai_lib = library('fossil-sdk-ai',
    files('anomaly.c', 'braincoral.c', 'dolphin.c', 'fishgpt.c', 'jellyfish.c', 'neural.c'),
    dependencies : [code_deps],
    install: true,
    include_directories: dir)

fossil_sdk_ai_dep = declare_dependency(
    link_with: [fossil_sdk_ai_lib],
    dependencies : [code_deps],
    include_directories: dir)