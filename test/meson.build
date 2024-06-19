fs = import('fs')

if get_option('with_test').enabled()
    fs.copyfile('sample-data.fson', 'sample-data.fson')
    run_command(['python3', 'generate-runner.py'], check: true)

    test_src = ['unit_runner.c']
    test_cubes = [
        'strings', 'io',
    ]

    foreach cube : test_cubes
        test_src += ['test_' + cube + '.c']
    endforeach

    pizza = executable('runner', test_src,
        include_directories: dir,
        dependencies: [
            dependency('fossil-test'),
            dependency('fossil-mock'),
            fossil_sdk_dep])

    test('xunit_tests', pizza)  # Renamed the test target for clarity
endif
