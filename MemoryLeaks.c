/*
    ===== MemoryLeaks.c =====

    A memory leak is when a process allocates memory space, but
    does not free the memory after it is done using it.

    This can happen in loops and the way memory is allocated
    in the program, and in what scopes memory is allocated.

    For example, if you need a temporary variable to be allocated
    in memory for a quick task, you would want that variable
    to be alloacted in a certain scope, to avoid memory leaks since
    once the program exits a scope all memory allocated in that
    scope is unallocated and freed.
*/

// TODO: Find out why windows made this stupidly harder.
// TODO: Also find out why windows ONLY had C++ examples of this.

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32

    #include <windows.h>
    #include <psapi.h>
    #define CLEAR "cls"

    void memUsage() {

        // Form structure for Process' Memory Data
        typedef struct _PROCESS_MEMORY_COUNTERS {

            DWORD  cb;
            DWORD  PageFaultCount;
            SIZE_T PeakWorkingSetSize;
            SIZE_T WorkingSetSize; // Current Memory Allocated
            SIZE_T QuotaPeakPagedPoolUsage;
            SIZE_T QuotaPagedPoolUsage;
            SIZE_T QuotaPeakNonPagedPoolUsage;
            SIZE_T QuotaNonPagedPoolUsage;
            SIZE_T PagefileUsage;
            SIZE_T PeakPagefileUsage;

        } PROCESS_MEMORY_COUNTERS;

        // Create structure
        struct _PROCESS_MEMORY_COUNTERS usageData;

        printf("Current Memory Usage: %d KB\n\n", 
            (usageData.WorkingSetSize / 1024)); // Print Usage

    }

#endif

#ifdef __unix__

    #include <sys/resource.h>
    #define CLEAR "clear"

    void memUsage() {
        
        struct rusage usageData; // Get Mem Usage
        getrusage(RUSAGE_SELF, &usageData);

        printf("Current Memory Usage: %ld KB\n\n", 
            usageData.ru_maxrss); // Print Usage

    }

#endif

int main() {

    system(CLEAR); // Console Clear
    printf("======== Memory Leaks ========\n\n");

    memUsage(); // Current Mem Allocated

    // Memory Allocated v v
    int addition(int a, int b) {

        // Memory Allocated
        int sum = a + b;

        // Making Memory Allocated Noticable
        long long noticeableMemory1;
        long long noticeableMemory2;
        long long noticeableMemory3;
        long long noticeableMemory4;
        long long noticeableMemory5;

        memUsage(); // Current Mem Allocated

        return sum; // Exits scope

        /*
            All memory allocated in this scope
            is unallocated at exit, freeing
            these temporary variables like
            the parameters and 'sum' variable.
        */

    }

    printf("Addition Task Returned: %i \n\n", 
        addition(5, 5)); // Returns, no memory leak.

    memUsage(); // Current Mem Allocated

    return EXIT_SUCCESS;

}