#include <stdio.h>

int main() {

    printf("|| ---------- Pointers ---------- ||\n\n");

    printf("Memory Addresses are formatted as Hexadecimals. \n\n");

    printf("Hexadecimals hold 16 symbols: \n\n");

    printf("0 1 2 3 4 5 6 7 8 9 A B C D E F \n\n");

    // --------- Memory Address Pointers --------- //

    int a = 350;      // Declare 'a'          NOTE: 'int' data type takes 4 bytes of memory.

    printf("Value of int 'a': %i \n", a);

    int* p;     // Declare pointer 'p'
    p = &a;     // (&) Operator gets Memory Address value of variable specified.

    printf("Mem Addr of 'a': 0x%p \n", p); // Prints Memory Address Pointer Value

    printf("Size of Int 'a': %i bytes\n", sizeof(a)); // Proof that integer variable takes 4 bytes of memory.

    int* p1 = p + 1;

    printf("Mem Addr (+1 Int): 0x%p \n", p1); // Prints memory address + 4 bytes (Since an Integer takes 4 bytes.)


    printf("\n^ ^ 4 Bytes ahead of original address. \n");
    printf("----- 0x%p => 0x%p [4 Hexadecimals Ahead] \n", p, p1);


    // Accessing memory ahead of pointer address

    printf("\nInteger Value at address 4-bytes ahead of *p: %i \n\n", *(p1));

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

    char* pChar = &character; // Note: Same data type, * operator to declare pointer.

    printf("Value of char variable: %c \n", character);

    printf("Mem Addr of 'char': 0x%p \n", pChar);

    printf("Size of Char Variable: %i Byte \n", sizeof(character));

    char* pChar1 = pChar + 1;

    printf("Mem Addr (+1 Char): 0x%p \n", pChar1); // +1 Char Space, 1 Address Ahead (1 Byte)


    printf("----- 0x%p => 0x%p [1 Hexadecimal Ahead]\n\n", pChar, pChar1);

    // Type Casting Pointers

    printf("==== Type Casting Pointers ==== \n\n");

    int integer = 1025; // Binary: 00000000 00000000 00000100 00000001 [4 Bytes for Int]
    int* pI = &integer;

    printf("Value of Integer var: %i \n", integer);
    printf("Mem Addr in Int Pointer: 0x%p \n\n", pI);

    char* pC = (char*)pI; // Type cast integer pointer as character pointer.

    /*

        Type casting from integer to character will force to cut down the data from
        4 bytes (int), to 1 byte (char) for the pointer. 

        This means it will translate 1025: 00000000 00000000 00000100 00000001

        To a type casted char value: 00000001 [It will cut down the last 3 bytes]

        This translates to binary 1. So when the char pointer is dereferenced,
        it will output 1 as the value of the pointed memory.


        Adding to pointers is pointer arithmetic. (int* p; p + 1 = 4 bytes ahead, etc.)

    */

    printf("Size of a character is %i byte.\n", sizeof(char));
    printf("Mem Addr in Char Pointer: 0x%p \nDereferenced Pointer Value: %i \n\n", pC, *pC);

    printf("Char Pointer Mem Addr (+1 Char): 0x%p \n", pC + 1);
    printf("Next Mem Address (+1 Char) Value: %i \n\n", *(pC + 1));

    /*

        Why does it print out 4 when reading the next byte (next char) after the pC address?

        The full integer this pointer, 'pC', is based off is 4 bytes of binary:

        | 00000000 00000000 00000100 00000001 |  --- Integer 1025
        |  Byte 4   Byte 3   Byte 2   Byte 1  |  --- Int Bytes
        | 0061FEFF 0061FEFE 0061FEFD 0061FEFC |  --- Memory Addresses

        When typecasted from int pointer to char, we took only the first byte, which is binary 1.

        If we output the value of the pointer mem addr by 1 char(1 byte), a.k.a (pC + 1),
        we get the next byte which is Byte 2 of the original integer in memory, which stores binary 4.

        This is why it prints out 4 as the value of (pC + 1), as its part of the whole
        integer binary that represents the original integer, 1025.

    */

    // ----- Pointer To Pointer ----- //

    printf("==== Pointer to Pointer ==== \n\n");

    char x = 'E'; // char 'x' value is 'E'

    char* u = &x; // Pointer to char 'x'

    char** q = &u; // ** = Pointer of Pointer

    char*** r = &q; // *** = Pointer to Pointer to Pointer

    printf("'r' pointer value: 0x%p \n", r);
    printf("'r' points to 'q': 0x%p \n", *r);
    printf("'q' points to 'u': 0x%p \n", *q);
    printf("'u' points to char 'x': %c \n\n", *u);

    return 0;

}