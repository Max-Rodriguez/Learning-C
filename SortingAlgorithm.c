/* ======================================
	 Selection Sort - Sorting Algorithm
   ======================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
	#define CLEAR "cls"
#endif

#ifdef __unix__
	#define CLEAR "clear"
#endif

#define MAX_NUM 255

int main() {

	system(CLEAR); // Clear CLI

	printf("========================\n\n");

	printf("Enter Array Length: ");
	int length; scanf("%i", &length);

	printf("\n========================\n\n");

	if (length < 2) {

		printf("Invalid Array Size!\n\n");
		return EXIT_SUCCESS;

	}

	srand(time(NULL));
	int array[length];

	printf("Random Generated Array: \n\n{ ");

	for (int i = 0; i < length; i++) {

		// Randomize Array Entries
		int random = rand() % MAX_NUM;
		array[i] = random;
		printf("%i", random);

		if (i != length - 1) printf(", ");

	}

	printf(" }\n\n");

	// ------- Selection Sort Algorithm ------- //

	/* 	==== Algorithm Logic ====

		Example Generated Array: { 5 99 0 21 67 }

		{ 0 99 5 21 67 } -- 0 Is Lower, 5 and 0 Swap
		{ 0 5 99 21 67 } -- 5 Is Lower, 99 and 5 Swap
		{ 0 5 21 99 67 } -- 21 Is Lower, 99 and 21 Swap
		{ 0 5 21 67 99 } -- 67 Is Lower, 99 and 67 Swap

		For loop on index, for loop on comparisons.
		Meaning 2 for loops and 1 Conditional Statement.

	*/

	int swaps = 0;
	int comparisons = 0;
	int accesses = 0;

	clock_t start = clock(); // Get Start Timestamp

	for (int i = 0; i < length; i = i + 1) {

		int min_pos = i;

		for (int x = i + 1; x < length; x = x + 1) {

			if (array[x] < array[min_pos]) min_pos = x;

			accesses = accesses + 2;
			comparisons = comparisons + 1;

		}

		int swap = array[i];
		array[i] = array[min_pos];
		array[min_pos] = swap;

		accesses = accesses + 4;
		swaps = swaps + 1;

	}

	float duration = (float)clock() - (float)start; // Get Total Time

	printf("Sorting Algorithm Output: \n\n{ ");

	for (int i = 0; i < length; i++) {

		printf("%i", array[i]);

		if (i != length - 1) printf(", ");

	}

	printf(" }\n\n");

	// ------- Sorting Algorithm Stats ------- //

	printf(
		"  Comparisons: %i  |  Swaps: %i  |  Array Accesses: %i  |  Algorithm Time: %i ms\n\n", 
		comparisons, swaps, accesses, (int)(duration)
	);

	return EXIT_SUCCESS;

}