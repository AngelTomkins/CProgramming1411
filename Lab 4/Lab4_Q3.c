// Angel Tomkins <atomkins@lakeheadu.ca>
// 1187799
// Oct 25, 2022
// Arch Linux, GCC 12.2.0

#include <stdio.h>
#include <stdlib.h>

// unsigned eight bit integer {0,...,255}
#define u8 unsigned char

// The best way to implement this program would to likely have a file that 
// contains all the questions, so that it is easier to add/remove questions
// and keeps the code looking pretty. I do not believe that it is the scope
// of this project to use fopen() or other methods of reading data from the
// drive. The following method is very archaic and should only be done for
// educational purposes.

// Function that with 2 indicies will return the string for each question:
// The title of the question and its answers
char* get_text(u8 q, u8 i)
{
    // It is notable that all of the stirings being returned are ternimaned
    // in a null character. This is so that we can stick it into printf()
    // without worrying about keeping track of the size of the strings

    // Also the return type is a pointer to a character. This is how C
    // stores strings internally.
    switch (q) {
        default:
            return "\0";
        // Question 1
        case 1:
            switch (i) {
                default:
                    return "\0";
                case 0:
                    return "When did C first appear\0";
                case 1:
                    return "1991\0";
                case 2:
                    return "1963\0";
                case 3:
                    return "1972\0";
            }
        // Question 2
        case 2:
            switch (i) {
                default:
                    return "\0";
                case 0:
                    return "Why was C created?\0";
                case 1:
                    return "Ritchie was interested in improving B to utilize more features of newer hardware\0";
                case 2:
                    return "To help eat icecream\0";
                case 3:
                    return "Bill Gates needed a language to build the Windows operating system\0";
            }
        // Question 3
        case 3:
            switch (i) {
                default:
                    return "\0";
                case 0:
                    return "What is one of the type disciplines of C?\0";
                case 1:
                    return "Inferred\0";
                case 2:
                    return "Weak\0";
                case 3:
                    return "Dynamic\0";
            }
        // Question 4
        case 4:
            switch (i) {
                default:
                    return "\0";
                case 0:
                    return "How many reserved words does C89 have?\0";
                case 1:
                    return "9001\0";
                case 2:
                    return "52\0";
                case 3:
                    return "32\0";
            }
    }
}

    // Returns the correct answer index per question{i}
u8 get_correct(u8 i)
{
    switch (i) {
        default:
            return -1;
        // Question 1
        case 1:
            return 3;
        // Question 2
        case 2:
            return 1;
        // Question 3
        case 3:
            return 2;
        // Question 4
        case 4:
            return 3;
    }
}

void print_score(u8 score)
{
    // Prints out relevent message based on user score
    switch (score) {
        default:
            break;
        case 0:
        case 1:
        case 2:
            printf("Time to brush up on your knowledge of C programming\n");
            break;
        case 3:
            printf("Very good\n");
            break;
        case 4:
            printf("Excellent\n");
            break;
    }
    return;
}


// Starts the questions part of the program
void start_questions()
{
    // Variable used to store user input temporarily
    int selection = 0;
    // Variable counter for how many correct questions the player got
    u8 score = 0;


    // loops over all questions
    for (u8 i = 1; i <= 4; i++) {

        // Pretty formatting
        printf("------------------\n");

        // Loops over all strings to be printed
        for (u8 j = 0; j < 4; j++) {
            char* str = get_text(i, j);
            if (j != 0) {
                printf("[%d] ", j);
            }
            printf("%s\n", str);
        }

        // Get user input
        printf("Answer [1-3]: ");
        scanf("%d", &selection);

        // Check user input
        if (selection == get_correct(i)) {
            score++;
        }
    }

    print_score(score);

    return;
}


int main(void)
{
    start_questions();
    return 0;
}