// Angel Tomkins <atomkins@lakeheadu.ca>
// 1187799
// Oct 3, 2022
// Arch Linux, GCC 12.2.0

#include <stdio.h>
#include <stdlib.h>


// Come back to this one
int main (void)
{
    char input;
    char should_exit = 0;
    
    do {
        printf("Enter A or a > ");
        scanf(" %c", &input);

        if (input == 'a' || input == 'A') {
            should_exit = 1;
        } else {
            printf("Sorry you did not type A or a, try again\n");
        }

    } while (!should_exit);

    return 0;
}

