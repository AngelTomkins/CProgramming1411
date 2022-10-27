// Angel Tomkins <atomkins@lakeheadu.ca>
// 1187799
// Oct 3, 2022
// Arch Linux, GCC 12.2.0

#include <stdio.h>
#include <stdlib.h>

void max_min(float* f1, float* f2, float* f3, float* f4);

int main (void)
{
    // Gets four numbers from the user
    float numbers[4];
    for (unsigned char i = 0; i < 4; i++) {
        printf("Enter number %hhi: ", i + 1 );
        scanf("%f", &numbers[i]);
    }

    // Checks for if the values are the same, returns an error if it is
    for (unsigned char i = 1; i < 4; i++) {
        if (numbers[0] == numbers[i]) {
            printf("The entered values are not distinct.\n");
            return 1;
        }
    }

    max_min(&numbers[0], &numbers[1], &numbers[2], &numbers[3]);
    return 0;
}


// Inserts pointers since there is no reason to copy the variables in memory
void max_min(
    float* f1,
    float* f2,
    float* f3,
    float* f4
) {
    // a and b are temporary values which will be manipulated twice.
    float a, b;
    float max, min;

    // The way that these max and min functions work is by taking advantage of
    // relational operators. In c a relational operator evaluates as an int
    // as either true (1) false (0) This can be used in mathematical equations.
    // This method of calculating maximum and minimum values is more efficient
    // due to it being branchless. The cpu can preload the variables in the
    // cache before the calculations are done. This is more efficient than
    // using if statements since the cpu needs to guess the outcome beforehand.

    // the first half of the expression is as such:
    // num1 * (num1 > num2)
    // If it is true that num1 is bigger than num2 then num1 will multiply by
    // the true value (1) and will equate to num1. Repeat this logic for all
    // other calculations in the section.

    // Finds the max of the first two numbers and second two numbers seperately
    // and then find the maximum of those two maximums.
    a = *f1 * (*f1 > *f2) + *f2 * (*f2 > *f1);
    b = *f3 * (*f3 > *f4) + *f4 * (*f4 > *f3);
    max = a * (a > b) + b * (b > a);

    // relational operator swapped to '<' for minimum
    a = *f1 * (*f1 < *f2) + *f2 * (*f2 < *f1);
    b = *f3 * (*f3 < *f4) + *f4 * (*f4 < *f3);
    min = a * (a < b) + b * (b < a);
    
    printf("The maximum is %f, The minimum is %f\n", max, min);
    return;
}