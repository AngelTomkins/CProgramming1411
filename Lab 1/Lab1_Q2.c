// Angel Tomkins <atomkins@lakeheadu.ca>
// 1187799
// 19 Sept. 2022
// Arch Linux x86_64, GCC 12.2.0 

// Following similar coding style to the linux foundation, lines should not
// surpass 80 lines for ease of readibility

#include <stdio.h>

int main (void)
{
    // Since the assignment is not explicit for data type, int will be used.
    int numOne, numTwo;

    // scanf does not have error checking therefore the user could input
    // a non integer value, which can lead to undefined behaviour.
    printf("Enter first number for numOne: ");
    scanf("%d", &numOne);

    printf("Enter second number for numTwo: ");
    scanf("%d", &numTwo);


    // Keeping to a consistant coding style, lines should not surpass 80 lines
    printf("The multiplication of %d and %d is = %d\n",
            numOne, numTwo, numOne * numTwo);
    printf("The division of of %d and %d is = %d\n",
            numOne, numTwo, numOne / numTwo);
    printf("The remainder of %d and %d is = %d\n",
            numOne, numTwo, numOne % numTwo);
    
    // Return 0 is successful, non-zero return values often indicate error(s)
    return 0;
}