code = files(
    'tofu.c',
    # Jellyfish AI components
    'jellyfish.c', 'deepsea.c',
    'anomaly.c',   'dolphin.c',
    'fishgpt.c',   'neural.c',
    'braincoral.c',
    # Multi-threading components
    'barrier.c',    'mutexs.c',
    'semaphores.c', 'thread.c',
    'threadpool.c', 'threadlocal.c',
    'condition.c',  'spinlocks.c',
    # Algorithms components
    'sort.c',   'search.c',
    'greedy.c', 'dynamic.c',
    'summary.c',
    # Data structures
    'queue.c',  'pqueue.c',
    'dqueue.c', 'flist.c',
    'dlist.c',  'tree.c',
    'set.c',    'stack.c',
    'map.c',    'vector.c',
    # IO compoments
    'fstream.c', 'istream.c',
    'ostream.c', 'soap.c',
    # String components
    'bstring.c', 'cstring.c',
    'letter.c',  'cipher.c',
    'number.c',  'format.c',
    'manip.c',   'number.c',
    'strfrom.c', 'strto.c',
    'wstring.c', 'strstream.c',
    # Standard low-level components
    'command.c', 'random.c', 'filesystem.c',
    'arguments.c', 'bitwise.c', 'money.c',
    'memory.c', 'hostsystem.c', 'smartptr.c'
    )

fossil_sdk_lib = library('fossil-sdk',
    code,
    dependencies : code_deps,
    install: true,
    include_directories: dir)

fossil_sdk_dep = declare_dependency(
    link_with: fossil_sdk_lib,
    dependencies : code_deps,
    include_directories: dir)
