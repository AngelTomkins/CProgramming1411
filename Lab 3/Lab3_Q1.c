// Angel Tomkins <atomkins@lakeheadu.ca>
// 1187799
// Oct 3, 2022
// Arch Linux, GCC 12.2.0

#include <stdio.h>

int main (void)
{
    // Range of values wanted is 0 to 10, unsigned char satisfies this
    unsigned char n;
    printf("Enter an integer between 1 and 10 > ");
        scanf("%hhi", &n);
        // If input is not within the target range, return main with an error
        if (n > 10) {
            printf("input should be between 1 and 10\n");
            return 1;
        }

    // Printing the stars, with new lines between each row
    for (unsigned char i = 0; i <= n; i++){
        for (unsigned char j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}