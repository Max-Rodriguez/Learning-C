#include <stdio.h>

int main() {

    printf(
        "|| ---------- Pointers ---------- ||\n\n"
    );

    printf("Memory Addresses are formatted as Hexadecimals.\n\n");

    // --------- Memory Address Pointers --------- //

    int a = 350;      // Declare 'a'          NOTE: 'int' data type takes 4 bytes of memory.

    printf("Value of int 'a': %i \n", a);

    int *p;     // Declare pointer 'p'
    p = &a;     // (&) Operator gets Memory Address value of variable specified.

    printf("Mem Addr of 'a': %p \n", p); // Prints Memory Address Pointer Value

    printf("Size of Int 'a': %i bytes\n", sizeof(a)); // Proof that integer variable takes 4 bytes of memory.

    printf("Mem Addr (+1 Int): %p \n", p + 1); // Prints memory address + 4 bytes (Since an Integer takes 4 bytes.)


    printf("\n^ ^ 4 Bytes ahead of original address.\n");
    printf("----- %p => %p [4 Hexadecimals Ahead]\n", p, p + 1);


    // Accessing memory ahead of pointer address

    printf("\nInteger Value at address 4-bytes ahead of *p: %i \n\n", *(p + 1));

    // --------- Interesting Point about Pointer Variables --------- //

    /*

        Why does adding 1 to a pointer add the size of the data type of the variable pointed to?

        Why are pointers strong types (declared with a data type ex. int, char)?


        Pointers need to be declared with the data type of the variable they are pointing to,
        in order to be able to DEREFERENCE pointers, a.k.a getting the value back from the pointer data.

        In order to get the value of the pointer variable, we need to know its data type to know its size
        in the memory, so that is why pointers are declared by data types though they all hold memory addresses.

        Memory Sizes of different Data Types:

            Int - 4 Bytes
            Char - 1 Byte
            Float - 4 Bytes

    */

    // Example for point mentioned above.

    char character = 'D';

    char * pChar = &character; // Note: Same data type, * operator to declare pointer.

    printf("Value of char variable: %c \n", character);

    printf("Mem Addr of 'char': %p \n", pChar);

    printf("Size of Char Variable: %i Byte \n", sizeof(character));

    printf("Mem Addr (+1 Char): %p \n", pChar + 1); // +1 Char Space, 1 Address Ahead (1 Byte)


    printf("----- %p => %p [1 Hexadecimal Ahead]", pChar, pChar + 1);

    return 0;

}