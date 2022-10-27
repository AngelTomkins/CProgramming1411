// Angel Tomkins <atomkins@lakeheadu.ca>
// 1187799
// Oct 25, 2022
// Arch Linux, GCC 12.2.0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Type definiton of coin
#define coin_t unsigned char

// Macros for potential coin_t's: easier to read and code
#define HEADS 1
#define TAILS 0
#define EMPTY_COIN 2 // Effectively null in this case

// You are allowed to change the number of players:
// If two players have the same # of heads, everyone loses
// implementation for better ties would be a good use of dynamic programming

// Programming for expandability is a good way to look at problems.

// Keep this at 2 for a proper implementation of the given question 
#define NUM_PLAYERS 2

// Return either 1 or 0, defined as per HEADS or TAILS
#define TOSS() (rand() % 2)

// Counts and returns the number of heads a player flipped
int num_heads(coin_t * coins, int size)
{
    int output = 0;
    for (int i = 0; i < size; i++) {
        // adds one if the given coin is heads since it adds the output of
        // a relational operator. Either: {0, 1}
        output += coins[i] == HEADS;
    }
    return output;
}

int main (void)
{
    // Set random string based on unix time
    srand(time(NULL));

    // Print title
    printf("---------------- Coin Toss game -----------------\n\n");

    // n represents the number of coin tosses each player will do
    int n;

    printf("Enter the number of times each player tosses the coin: ");
    scanf("%d", &n);
    printf("\n");   // newline for formatting purposes

    // Checking if n is negative since negative flipps cannot happen
    if (n < 1) {
        printf( "At least one coin must be flipped, "
                "please input a strictly positive value");
    }

    // --- Manual Memory Allocation with malloc() ---
    // Because at compile time, we do not know how many flips each player wants
    // to make... We cannot create an array of the preferred # of tosses since
    // that is declared in runtime. Because of this, to not waste memory by
    // initializing an array of an arbitrary size, instead we will have memory
    // allocated of size n for each player. This means that there can be the
    // integer max # of coin flips.

    // Create an array of pointers, one pointer per player
    coin_t *arrayPlayer[NUM_PLAYERS];

    for (int i = 0; i < NUM_PLAYERS; i++) {
        // Allocate memory for each player of size n
        arrayPlayer[i] = (coin_t*) malloc(sizeof(coin_t) * n);

        // Initialize the array with empty the coin representation, so we know 
        // if a coin has actually been flipped or not
        for (int j = 0; j < n; j++) {
            arrayPlayer[i][j] = EMPTY_COIN;
        }
    }

    // Toss all the coins for every player here
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < n; j++) {
            arrayPlayer[i][j] = TOSS();
        }
    }

    // Count how many heads each player has and print 
    int heads[NUM_PLAYERS] = {0};
    for (int i = 0; i < NUM_PLAYERS; i++) {
        heads[i] = num_heads(arrayPlayer[i], n);
        // Prints out the # of heads and tails for each player
        printf( "--- Total count for Player %d ---\n"
                "Heads was tossed %d times\n"
                "Tails was tossed %d times\n\n",
                i+1, heads[i], n - heads[i]);
    }
    
    // Top is a temporary counting number for checking max and mins
    int top = 0;
    // Winner is the index(player number) of the player with the most heads
    int winner = 0;

    // Check who is the winner
    for (int i = 1; i <= NUM_PLAYERS; i++) {
        // Recursively compare all the players' # of heads to find who has
        // the most
        if (top < heads[i-1]) {
            winner = i;
            top = heads[i-1];
        } else if (top == heads[i-1]) {
            // If there is a tie, the winner is nobody, represented as -1
            winner = -1;
        }
    }

    // Print winning remarks
    if (winner == -1) {
        printf("There was a tie, nobody wins\n");
    } else {
        printf("Player %d WON the game!\n", winner);
    }


    // Unallocate memory to ensure no memory leaks
    // Confirmed with valgrind
    for (int i = 0; i < NUM_PLAYERS; i++) {
        free(arrayPlayer[i]);    
    }

    return 0;
}