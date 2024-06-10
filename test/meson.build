if get_option('with_test').enabled()
    run_command(['python3', 'generate-runner.py'], check: true)

    test_src = ['xunit_runner.c']
    test_cubes = [
        'tofu',
        # jellyfish AI test cases
        'deepsea', 'anomaly',
        'dolphin', 'fishgpt',
        'neural', 'braincoral',
        # thread test cases
        'barrier', 'mutexs',
        'semaphores', 'thread',
        'threadpool', 'threadlocal',
        'condition', 'spinlocks',
        # algorithms test cases
        'sort', 'search',
        'greedy', 'dynamic',
        'summary',
        # data structures test cases
        'queue', 'pqueue',
        'dqueue', 'flist',
        'dlist', 'tree',
        'set', 'stack',
        'map', 'vector',
        # IO test cases
        'fstream', 'istream',
        'ostream', 'soap',
        # String test cases
        'bstring', 'cstring',
        'letter',  'cipher',
        'number',  'format',
        'manip',   'number',
        'strfrom', 'strto',
        'wstring', 'strstream',
    ]

    foreach cube : test_cubes
        test_src += ['xtest_' + cube + '.c']
    endforeach

    pizza = executable('runner', test_src,
        include_directories: dir,
        dependencies: [dependency('fossil-test-c'), fossil_sdk_c_dep])

    test('xunit_tests', pizza)  # Renamed the test target for clarity
endif
