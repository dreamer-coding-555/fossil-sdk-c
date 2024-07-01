/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include "fossil/core/hostsystem.h"
#include "fossil/common/common.h"

#ifdef _WIN32
    #include <windows.h>
    #include <tchar.h>
    #include <lmcons.h>
#elif __linux__
    #include <sys/utsname.h>
    #include <unistd.h>
    #include <sys/sysinfo.h>
#elif __APPLE__
    #include <sys/utsname.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/sysctl.h>
#endif

static fossil_bool_t fossil_hostsys_get_endian(fossil_hostsystem_t *info) {
    unsigned int num = 1;
    char *endian_check = (char*)&num;

    if (*endian_check == 1) {
        info->is_big_endian = FOSSIL_FALSE;
    } else {
        info->is_big_endian = FOSSIL_TRUE;
    }

    return FOSSIL_TRUE;
}

#ifdef _WIN32
static fossil_bool_t fossil_hostsys_get_windows(fossil_hostsystem_t *info) {
    OSVERSIONINFO osvi;
    SYSTEM_INFO si;
    MEMORYSTATUSEX memInfo;

    memset(info, 0, sizeof(fossil_hostsystem_t));
    ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    
    if (!GetVersionEx(&osvi)) {
        fprintf(stderr, "Error getting Windows version information\n");
        return FOSSIL_FALSE;
    }

    strncpy(info->os_name, "Windows", sizeof(info->os_name));
    snprintf(info->os_version, sizeof(info->os_version), "%ld.%ld",
             osvi.dwMajorVersion, osvi.dwMinorVersion);

    GetNativeSystemInfo(&si);
    snprintf(info->cpu_model, sizeof(info->cpu_model), "Intel");

    info->cpu_cores = si.dwNumberOfProcessors;

    if (!GlobalMemoryStatusEx(&memInfo)) {
        fprintf(stderr, "Error getting memory information\n");
        return FOSSIL_FALSE;
    }

    info->total_memory = memInfo.ullTotalPhys / (1024 * 1024);  // in MB
    info->free_memory = memInfo.ullAvailPhys / (1024 * 1024);  // in MB

    return FOSSIL_TRUE;
}

#elif defined(__linux__)
static fossil_bool_t fossil_hostsys_get_linux(fossil_hostsystem_t *info) {
    struct utsname unameData;
    FILE *cpuinfo;
    char line[256];

    memset(info, 0, sizeof(fossil_hostsystem_t));

    if (uname(&unameData) != 0) {
        fprintf(stderr, "Error getting uname information\n");
        return FOSSIL_FALSE;
    }

    strncpy(info->os_name, unameData.sysname, sizeof(info->os_name));
    strncpy(info->os_version, unameData.release, sizeof(info->os_version));

    cpuinfo = fopen("/proc/cpuinfo", "r");
    if (cpuinfo) {
        while (fgets(line, sizeof(line), cpuinfo)) {
            if (strstr(line, "model name")) {
                char *pos = strchr(line, ':');
                if (pos) {
                    strncpy(info->cpu_model, pos + 2, sizeof(info->cpu_model));
                    break;
                }
            }
        }
        fclose(cpuinfo);
    } else {
        fprintf(stderr, "Error opening /proc/cpuinfo\n");
        return FOSSIL_FALSE;
    }

    info->cpu_cores = sysconf(_SC_NPROCESSORS_ONLN);

    long pages = sysconf(_SC_PHYS_PAGES);
    long page_size = sysconf(_SC_PAGE_SIZE);
    info->total_memory = pages * page_size / (1024 * 1024);  // in MB

    struct sysinfo memInfo;
    if (sysinfo(&memInfo) == 0) {
        info->free_memory = memInfo.freeram / (1024 * 1024);  // in MB
    } else {
        fprintf(stderr, "Error getting memory information\n");
        return FOSSIL_FALSE;
    }

    return FOSSIL_TRUE;
}

#elif defined(__APPLE__)
static fossil_bool_t fossil_hostsys_get_macos(fossil_hostsystem_t *info) {
    struct utsname unameData;

    memset(info, 0, sizeof(fossil_hostsystem_t));

    if (uname(&unameData) != 0) {
        fprintf(stderr, "Error getting uname information\n");
        return FOSSIL_FALSE;
    }

    strncpy(info->os_name, unameData.sysname, sizeof(info->os_name));
    strncpy(info->os_version, unameData.release, sizeof(info->os_version));

    int mib[2];
    size_t len;
    char cpu_model[256];

    // Get the CPU model
    mib[0] = CTL_HW;
    mib[1] = HW_MODEL;
    len = sizeof(cpu_model);
    if (sysctl(mib, 2, &cpu_model, &len, NULL, 0) == 0) {
        strncpy(info->cpu_model, cpu_model, sizeof(info->cpu_model));
    } else {
        fprintf(stderr, "Error getting CPU model information using sysctl\n");
        return FOSSIL_FALSE;
    }

    // Get the number of CPU cores
    mib[1] = HW_NCPU;
    len = sizeof(info->cpu_cores);
    if (sysctl(mib, 2, &info->cpu_cores, &len, NULL, 0) != 0) {
        fprintf(stderr, "Error getting CPU cores information using sysctl\n");
        return FOSSIL_FALSE;
    }

    // Get the total memory
    mib[1] = HW_MEMSIZE;
    len = sizeof(info->total_memory);
    if (sysctl(mib, 2, &info->total_memory, &len, NULL, 0) != 0) {
        fprintf(stderr, "Error getting total memory information using sysctl\n");
        return FOSSIL_FALSE;
    }
    info->total_memory /= (1024 * 1024); // Convert to MB

    // Get the free memory
    int64_t free_memory;
    len = sizeof(free_memory);
    mib[0] = CTL_VM;
    mib[1] = VM_STATISTICS;
    if (sysctl(mib, 2, &free_memory, &len, NULL, 0) == 0) {
        info->free_memory = free_memory / (1024 * 1024); // Convert to MB
    } else {
        fprintf(stderr, "Error getting free memory information using sysctl\n");
        return FOSSIL_FALSE;
    }

    return FOSSIL_TRUE;
}
#endif

/**
 * @brief Retrieves the system information and stores it in the provided fossil_hostsystem_t structure.
 * 
 * This function retrieves various system information such as the operating system name,
 * version, CPU model, number of CPU cores, total memory, and free memory. The information
 * is stored in the provided fossil_hostsystem_t structure.
 * 
 * @param info Pointer to the fossil_hostsystem_t structure where the system information will be stored.
 * @return Returns true if the system information was successfully retrieved, otherwise false.
 */
fossil_bool_t fossil_hostsys_get(fossil_hostsystem_t *info) {
    fossil_bool_t result = FOSSIL_FALSE;

    #ifdef _WIN32
        result = fossil_hostsys_get_windows(info);
    #elif __linux__ || __APPLE__
        result = fossil_hostsys_get_linux(info);
    #else
        fprintf(stderr, "Unsupported platform\n");
    #endif

    if (result) {
        return fossil_hostsys_get_endian(info);
    } else {
        return FOSSIL_FALSE;
    }
}

/**
 * @brief Returns a string indicating the endianness of the system.
 * 
 * This function checks the endianness of the system and returns a string indicating
 * whether the system is big endian or little endian.
 * 
 * @param info Pointer to the fossil_hostsystem_t structure containing the system information.
 * @return Returns a string "Big Endian" if the system is big endian, otherwise "Little Endian".
 */
const char* fossil_hostsys_endian(fossil_hostsystem_t *info) {
    if (info->is_big_endian) {
        return "Big Endian";
    } else {
        return "Little Endian";
    }
}

/**
 * @brief Prints the system information to the standard output.
 * 
 * This function prints the retrieved system information to the standard output,
 * including the operating system name, version, CPU model, number of CPU cores,
 * total memory, free memory, and endianness.
 * 
 * @param info Pointer to the fossil_hostsystem_t structure containing the system information.
 */
void fossil_hostsys_print(fossil_hostsystem_t *info) {
    printf("Operating System: %s %s\n", info->os_name, info->os_version);
    printf("CPU: %s\n", info->cpu_model);
    printf("Number of Cores: %d\n", info->cpu_cores);
    printf("Total Memory: %d MB\n", (int)info->total_memory);
    printf("Free Memory: %d MB\n", (int)info->free_memory);
    printf("Endian: %s\n", fossil_hostsys_endian(info));
}
