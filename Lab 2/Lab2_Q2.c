// Angel Tomkins <atomkins@lakeheadu.ca>
// 1187799
// Sept 24, 2022
// Fedora Linux 36, GCC 12.1.0

#include <stdio.h>

int main (void) 
{
    // Lab shows using int, but for characters in the UTF-8 standard,
    // char is the preferred type.
    char grade;
    printf("Enter the studen letter grade (A, B, C, D, or F) : ");

    // %c for character
    scanf("%c", &grade);

    // Both A and B have the same printf string, therefore they can be in the
    // same if statement with "||" (or) to be true if any one of them are true
    if (grade == 'A' || grade == 'a' || grade == 'B' || grade == 'b') {
        printf("Good standing\n");
    } else if (grade == 'C' || grade == 'c') {
        printf("O.K.\n");
    } else if (grade == 'D' || grade == 'd' || grade == 'F' || grade == 'f') {
        printf("Poor, student is on probation\n");
    } else {
        printf("Invalid letter grade\n");
        // Return non-zero implies an error has occured
        return 1;
    }

    return 0;
}