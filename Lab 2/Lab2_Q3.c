// Angel Tomkins <atomkins@lakeheadu.ca>
// 1187799
// Sept 24, 2022
// Fedora Linux 36, GCC 12.1.0

#include <stdio.h>

int main (void) 
{
    // Store both numbers as a 2 dimensional integer array for easy access
    int num[2];

    printf("Input a number: ");
    scanf("%d", &num[0]);

    printf("Input another number: ");
    scanf("%d", &num[1]);

    // Use a counter to skip the inefficiencies of if-else-if statements
    unsigned char counter = 0;
    for (int i = 0; i < 2; i++) {
        // modulus outputs a boolean, therefore in bit representation is 1 or 0
        // bitshifting by i means that the second number will change the second
        // bit in the counter variable. therefore, the three outputs for this
        // can be 00, 01, 10, 11, and will be used in the switch statement
        counter += (num[i] % 2) << i;
    }


    // a switch statement is more efficient than an if statement for multiple
    // possible cases
    switch (counter) {
        case 0:
            printf("You have entered two even numbers.\n");
            break;
        case 1:
        // 2 in decimal is the same as 10 in binary
        case 2:
            printf("You have entered one even number and one odd number.\n");
            break;
        // 3 in decimal is the same as 11 in binary
        case 3:
            printf("You have entered two odd numbers.\n");
            break;
    }

    return 0;
}