fs = import('fs')

if get_option('with_test').enabled()
    fs.copyfile('sample-data.fson', 'sample-data.fson')
    run_command(['python3', 'generate-runner.py'], check: true)

    test_src = ['xunit_runner.c']
    test_cubes = [
        'threaded',
    ]

    foreach cube : test_cubes
        test_src += ['xtest_' + cube + '.c']
    endforeach

    pizza = executable('runner', test_src,
        include_directories: dir,
        dependencies: [
            dependency('fossil-test', default_options: ['c_std=c17']),
            dependency('fossil-mock', default_options: ['c_std=c17']),
            fossil_sdk_dep])

    test('xunit_tests', pizza)  # Renamed the test target for clarity
endif
