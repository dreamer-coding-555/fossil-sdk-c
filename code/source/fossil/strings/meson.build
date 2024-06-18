fossil_sdk_strings_lib = library('fossil-sdk-strings',
    files('bstring.c', 'cstring.c', 'letter.c',  'cipher.c',
          'number.c',  'format.c', 'manip.c',   'number.c',
          'strfrom.c', 'strto.c', 'wstring.c', 'strstream.c'),
    dependencies : code_deps,
    install: true,
    include_directories: dir)

fossil_sdk_strings_dep = declare_dependency(
    link_with: [fossil_sdk_strings_lib],
    dependencies : code_deps,
    include_directories: dir)