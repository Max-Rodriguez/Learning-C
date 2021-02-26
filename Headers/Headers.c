/* -----------------------------------------
	Example of Using a Header File in C
	This header file defines boolean values
*/

#include "include/header.h"

#include <stdio.h>
#include <stdlib.h>

int main() {

	// Use defined macros from header
	boolean bool1 = true;
	boolean bool2 = false;

	printf("Boolean 1 Value: %i\n", bool1);
	printf("Boolean 2 Value: %i\n", bool2);

	return EXIT_SUCCESS;

}