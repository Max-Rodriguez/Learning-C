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

        char name[40]; // Max 40 characters
        char major[20]; // Max 20 Characters
        int age;
        float gpa;

    };

    struct Student student1; // Create Data Structure from 'Student' struct.

    student1.age = 18;
    student1.gpa = 2.9;
    strcpy(student1.major, "Computer Science");
    strcpy(student1.name, "John Doe");

    printf("---------------- Student Information ----------------\n");

    printf("Name: %s | Age: %i | Major: %s | GPA: %g \n", 
        student1.name, student1.age, student1.major, student1.gpa);

    return 0; // main() functions in C need to return an exit code. Exit code 0 means a successful process.

}