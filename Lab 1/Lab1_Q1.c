// Angel Tomkins <atomkins@lakeheadu.ca>
// 1187799
// 19 Sept. 2022
// Arch Linux x86_64, GCC 12.2.0 

// Following similar coding style to the linux foundation, lines should not
// surpass 80 lines for ease of readibility

#include <stdio.h>

int main (void)
{
    // unsigned short contains all potential course numbers 0 to 9999
    unsigned short course_num;
    // int contains all potential student ids 0 to 9999999
    unsigned int student_id;

    // scanf does not have error checking therefore the user could input
    // a non integer value, which can lead to undefined behaviour.
    printf("Enter your course number: ");
    scanf("%hu", &course_num);

    printf("Enter your student ID: ");
    scanf("%d", &student_id);


    // Multiple lines for long printf function input for ease of readibility.
    // The compiler performs string concatenation thus performance is 
    // not hindered
    printf("\nI study in Lakehead University\n"
            "\tMy course number is %hu,\n"
            "\t\tand my student ID is %d\n",
            course_num, student_id);

    // Return 0 is successful, non-zero return values often indicate error(s)
    return 0;
}