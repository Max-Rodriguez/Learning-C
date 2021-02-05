#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Void Function (Does not return data)
void function() {

    printf("Ran a function!\n");

}

// Integer Function (Returns an integer)
int sum(int value1, int value2) {

    return value1 + value2;

}

int main() {

    // ---------- Hello World ---------- //

    printf("Hello World! \n");

    /*
        Block Comment
    */

    // ---------- C Data Types ---------- //

    int integer = 21; // Integer Variable (Int Data Type)
    float decimal = 6.5; // Decimal Variable (Float Data Type)
    double long_decimal = 3.56789; // Longer Decimal Variable (Double Data Type)

    char character = 'A'; // Variable (Character Data Type)
    char charString[] = "formatted!"; // Variable (Multiple Characters, String Data Type)

    const int constant = 36; // Constant Declaration (Variable cannot be modified)
    const char constChar = 'C'; // This constant declaration works on any variable data type.

    int array[] = {3, 5, 1, 4, 2}; // Arrays can hold any data type, declared with '[]'.

    int picked = array[1]; // Will get the second array item in 'array' variable. Arrays start at 0. 
    array[0] = 17; // Square brackets can also be used for modifying array items.

    // ---------- Formatting Strings ---------- //

    printf("This is %s \n", charString); // Formatting a string using identifiers and variable parameters.

    printf("A formatted number: %d \n", 3); // '%d' identifier specifies to include an integer as a string.

    // ---------- Functions ---------- //

    function(); // Calls function referenced outside of main(). Will execute the code under its scope.

    printf("Sum returned by function: %d \n", sum(2, 3)); // Runs 'sum' function, which returns an integer.

    // ---------- Conditional Statements ---------- //

    char initial = 'J';
    int age = 32;

    if (initial == 'J' && age == 32) { // If Statement

        printf("Welcome back, Jim!\n");

    } else if (age != 32) { // Else if Combined Statements

        printf("You're not of Jim's age!\n");

    } else { // Else Statement

        printf("You are not the real Jim!\n");

    }

    char grade = 'B';
    printf("Current Grade: %c  |  Feedback: ", grade);

    switch (grade) { // Switch Statement

        case 'A':

            printf("Excellent grade!\n");
            break; // Needed to end case, since it does not use curly brackets.

        case 'B':

            printf("Good job!\n");
            break; // Ends Switch Execution

        case 'C':

            printf("You need to improve!\n");
            break; // Ends Switch Execution

    }

    // ---------- Loop Statements ---------- //

    int count = 1;

    while (count <= 5) { // While Loop Statement

        printf(" %d ..", count); // Print current count.

        count++; // Add to the total count.

    }

    printf("\n");

    const int countTo = 10;

    for (int i = 1; i <= 10; i++) { // For Loop Statement

        printf("%d - ", i);

        // No need to increment here, since it is done in the parameters above.

    }

    printf("\n");

    // ---------- Structs [Data Structure, not a class] ---------- //

    struct Student {

        int id;
        char name[40]; // Max 40 characters
        char major[20]; // Max 20 Characters
        int age;
        float gpa;

    };

    void printStudent(struct Student s) {

        printf("\n| ---------------- Student Information ---------------- |\n");

        printf("ID: %i | Name: %s | Age: %i | Major: %s | GPA: %g \n\n", s.id, s.name, s.age, s.major, s.gpa);

    }

    struct Student student1; // Create Data Structure from 'Student' struct.

    student1.id = 1;
    student1.age = 18;
    student1.gpa = 2.9;
    strcpy(student1.major, "Computer Science");
    strcpy(student1.name, "John Doe");

    printStudent(student1); // Pass struct formed to function.

    struct Student student2;

    student2.id = 2;
    student2.age = 17;
    student2.gpa = 3.7;
    strcpy(student2.major, "Engineering");
    strcpy(student2.name, "Foo Bar");

    printStudent(student2);

    // ---------- 2-Dimensional Arrays ---------- //

    int nums[3][5] = {  // First [] does not require a fixed size, but the second [] does.

        {4, 1, 3, 2, 5},
        {6, 10, 7, 9, 8},     // Basically an array of arrays
        {14, 11, 15, 13, 12}

    };

    for (int i = 0; i < 3; i++) { // Iterate through arrays

        printf("{ ");

        for (int x = 0; x < 5; x++) { // Iterate through items of each array

            printf("%i, ", nums[i][x]);

        }

        printf("} \n\n"); // New line after every array listed

    }

    // ---------- Memory Address Pointers ---------- //

    char words[] = "Hello World!";

    printf("Mem Addr: 0x%p \n", &words); // %p stands for pointer. Will print the memory address of the variable.

    // Memory Addresses go by hexadecimals (0 - F) (16 Symbols)

    float dec = 3.5;
                            // Use same data type for pointers.
    float *pDec = &dec;

    // ---------- Dereferencing Pointers ---------- //

    printf("0x%p \n", pDec); // Will output pointer value.
    printf("%g \n", *pDec); // Will output data of whats inside the memory address pointed by the pointer.
    printf("%g \n", *&dec); // Same output, referencing and dereferencing pointer of 'dec'.

    // ---------- Using The File System ---------- //

    FILE *filepointer = fopen("writing.txt", "w"); // Creates 'employees.txt' file in memory.

    // Will place file to relative directory from this process.

    fprintf(filepointer, "This text was written by the program."); // 'print' to file (first argument)

    fclose(filepointer); // Closes 'employees.txt' file pointer from memory.


    FILE *fpointer = fopen("appending.txt", "a"); // Appends data to 'appending.txt'

    fprintf(fpointer, "This text is appended every time the program executes.\n");

    fclose(fpointer);

    // --- Reading Files --- //

    char line[255];

    FILE *fRead = fopen("read.txt", "r"); // Read Only Mode

    fgets(line, 255, fRead);
    printf("%s", line);

    fclose(fRead); // Clear from memory

    return 0; // main() functions in C need to return an exit code. Exit code 0 means a successful process.

}