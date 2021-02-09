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
#include <stdbool.h>
#include <time.h>

#ifdef _WIN32

    #include <windows.h>
    #include <psapi.h>
    #define CLEAR "cls"

    void memUsage() {

        /* I just CANT make this work.
           Microsoft's documentation on psapi.h
           actually sucks, prints incredibly
           unrealistic data, just use the task
           manager to see the memory leak on Win32.
        */

        // Redefine Struct
        typedef struct {

            DWORD  cb;
            DWORD  PageFaultCount;
            SIZE_T PeakWorkingSetSize;
            SIZE_T WorkingSetSize;
            SIZE_T QuotaPeakPagedPoolUsage;
            SIZE_T QuotaPagedPoolUsage;
            SIZE_T QuotaPeakNonPagedPoolUsage;
            SIZE_T QuotaNonPagedPoolUsage;
            SIZE_T PagefileUsage;
            SIZE_T PeakPagefileUsage;
            SIZE_T PrivateUsage;

        } PROCESS_MEMORY_COUNTERS_EX;

        // Initialize Struct
        PROCESS_MEMORY_COUNTERS_EX usageData;

        printf("Current Memory Usage: %zu KB [Broken on Win32! Use task manager.]\n\n", 
            (usageData.WorkingSetSize / 1024)); // Print Usage

    }

#endif

#ifdef __unix__

    #include <sys/resource.h>
    #define CLEAR "clear"

    void memUsage() {
        
        struct rusage usageData; // Get Mem Usage
        getrusage(RUSAGE_SELF, &usageData);

        printf("Current Memory Usage: %ld KB \n\n", 
            usageData.ru_maxrss); // Print Usage

    }

#endif

void delay(int ms) {
  
    // Store Current Time
    clock_t start_time = clock();
  
    // Loop until difference requirement
    while (clock() < start_time + ms);

}

int main() {

    system(CLEAR); // Console Clear

    int addition(int a, int b) {

        int sum = a + b;

        // Dynamically Allocating 102 Bytes (.1 KB)
        char *allocation = (char*) malloc(102);

        return sum; // Exit scope without freeing memory

        /*
            Dynamically Alloacted Memory, a.k.a
            allocation methods from standard library, 
            will not get freed at the exit of a scope.

            This is a simple example of a memory leak.
        */

    }

    while (true) {

        // Pseudo Random Generator seed
        srand(time(NULL));

        int a = rand() % 50;
        int b = rand() % 50;

        printf("Addition Task Returned: %i \n\n", 
            addition(a, b)); // Returns, memory leaked.

        memUsage(); // Print Current Memory Allocated

        delay(1000);

    }

    return EXIT_SUCCESS;

}