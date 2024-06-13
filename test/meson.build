fs = import('fs')

if get_option('with_test').enabled()
    fs.copyfile('sample-data.fson', 'sample-data.fson')
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
        'fstream',
        'ostream', 'soap',
        # String test cases
        'bstring', 'cstring',
        'letter',  'cipher',
        'number',  'format',
        'manip',   'number',
        'strfrom', 'strto',
        'wstring', 'strstream',
        # Low level test cases
        'command', 'random',
        'filesystem', 'hostsystem',
        'arguments', 'money',
        'memory', 'bitwise',
        'smartptr',
        # Addintal Fossil Platform test cases
        'fossil', 'datetime',
        'fson', 'regex',
        'bluecrab'
    ]

    foreach cube : test_cubes
        test_src += ['xtest_' + cube + '.c']
    endforeach

    pizza = executable('runner', test_src,
        include_directories: dir,
        dependencies: [dependency('fossil-test'), dependency('fossil-mock'), fossil_sdk_dep])

    test('xunit_tests', pizza)  # Renamed the test target for clarity
endif
