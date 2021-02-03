#include <stdio.h>
#include <stdlib.h>

int main() {

    int secret = 5;
    int count = 0;
    int guess;

    while (guess != secret && count < 3) {

        printf("Enter your guess: ");

        scanf("%i", &guess); // Let input be assigned to the value of 'guess'

        if (guess == secret) {

            printf("You guessed the correct number of %i!\n", secret);

            return 0; // Exit process

        } else {

            printf("Incorrect guess, try again.\n");

            count++;

        }

    }

    printf("Game Over! You ran out of guesses.\n");

    return 0;

}