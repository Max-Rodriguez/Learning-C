/*

    M E M O R Y   L E A K S  -  E X A M P L E

    |=====|--- Simple Betting Game ---|=====|

    Jack Queen King - Program Shuffles Card Positions

    Player has to guess the position of the queen.

    If player wins, he takes home (3x) the bet.

    If he loses, he loses cash by bet amount set.

    Cash variable initializes at $100.

*/

// TODO: Fix scanning input string for bet.
// TODO: Why doesnt vscode have todo

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BET_SIZE 64

// Global Variable
int cash = 100;

void playGame(int bet) {

    char card[3] = {'J', 'Q', 'K'};

    srand(time(NULL));

    for (int i = 0; i < 5; i++) {

        int x = rand() % 3;
        int y = rand() % 3;

        int temporary = card[x];
        card[x] = card[y];       // Swaps Chars at positions x and y.
        card[y] = temporary; 


    }

    printf(" What's Your Guess on the Queen's Position? [1, 2, or 3] : ");

    int guess;
    scanf("%i", &guess);

    if (guess > 3) {

        printf("\n Invalid Guess, the only card positions are 1 to 3! \n");

        return; // End Round, Money not affected.

    }

    if (card[guess - 1] == 'Q') {

        cash += bet * 3; // Triple bet amount

        printf("\n You Won! || Results = %c, %c, %c || Total Cash : $%i\n", 
            card[0], card[1], card[2], cash);

    } else {

        cash -= bet; // Take away cash by bet placed.

        printf("\n You Lost! || Results = %c, %c, %c || Total Cash : $%i\n",
            card[0], card[1], card[2], cash);

    }

}

// Main
int main() {

    int bet; // Initialize bet variable.

    printf("\n=============================\n\n");

    while (cash > 0) {

        bet = 0; // Reset Bet Variable

        int getBet() {

            char input[MAX_BET_SIZE];

            printf(" What's your bet? $: ");
            scanf("%s", &input);

            int in = atoi(input); // Filter Characters
            bet = in; // Set Bet

            return 1; // Success

        }

        int inputFlag = getBet(); // Get Player Input

        // Deny invalid bet amount
        if (inputFlag == 0 || bet == 0 || bet > cash) {
            
            printf("\n That is an invalid bet amount, please try again.\n\n");

            return EXIT_SUCCESS; // Exit

        }

        printf("\n=============================\n\n");

        playGame(bet); // Begin Round

        printf("\n=============================\n\n");

    }

    printf("Game Over, you reached $%i cash.\n\n", cash);

    return EXIT_SUCCESS;

}