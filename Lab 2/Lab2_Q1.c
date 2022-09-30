// Angel Tomkins <atomkins@lakeheadu.ca>
// 1187799
// Sept 24, 2022
// Fedora Linux 36, GCC 12.1.0

#include <stdio.h>

int main (void) 
{

    printf("Enter percent grade: ");

    // By using an unsigned char, the maximum the variable can be is 255, so
    // the grade range of 0 to 100 is satisfied. The reason to use unsigned
    // is that it cannot be negative, so it can never be negative and does not
    // need to be checked for negative.

    unsigned char grade;
    // %hhi is for unsigned char types represented as an integer.
    scanf("%hhi", &grade);  

    // Out of range check, note lack of negative check with unsigned char type.
    // Returns 1 if the grade is not valid, in C a non-zero return value
    // implies a failure.
    if (grade > 100) {
        printf("That is not a valid grade\n");
        return 1;
    }


    // After one of the if statements are satisfied, return since there is no
    // reason to continue checking for other possible grades.

    // Between 100 and 90
    if (grade > 90) {
        printf("Grade is: A\n");
        return 0;
    }

    // Between 90 and 80
    if (90 > grade && grade > 80 ) {
        printf("Grade is: B\n");
        return 0;
    }

    // Between 80 and 70
    if (80 > grade && grade > 70) {
        printf("Grade is: C\n");
        return 0;
    }

    // Between 70 and 60
    if (70 > grade && grade > 60) {
        printf("Grade is: D\n");
        return 0;
    }

    // Below 60 (unsigned type so also above 0)
    if (grade < 60) {
        printf("Grade is: F\n");
        return 0;
    }


    // Return an error here if no if statements were true, this is an unusual
    // case and assuming no bugs, this should never be run
    return 1;
}