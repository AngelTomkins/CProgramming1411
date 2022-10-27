// Angel Tomkins <atomkins@lakeheadu.ca>
// 1187799
// Oct 3, 2022
// Arch Linux, GCC 12.2.0

#include <stdio.h>

#if 1
// Assignment says to use 3.1429 even though that is not pi,
// pi should be 3.1415 or 3.141592653589 depending on importance of accuracy.
// Change the if statement to 0 if you want a more accurate pi value
#define PI 3.1429

#else

// Proper value of pi
#define PI 3.141592653589

#endif


// Define functions before main()
float square(void);
float rectangle(void);
float circle(void);

int main (void) 
{
    float area;

    printf("Menu Options:\n"
    "[1] Find area and perimeter of a square\n"
    "[2] Find area and perimeter of a rectangle\n"
    "[3] Find Area and perimeter of a circle\n"
    "Selection: ");

    // unsigned char was chosen since its range satisfies our range of 1-3
    // and uses the least amount of memory. 
    // Unsigned since it should not be negative
    unsigned char input;
    scanf("%hhi", &input);
    switch (input) {
        // If a case which is not 1, 2, or 3, default will run
        default:
            printf("\nError: Wrong menu choice\n");
            return 1;
        case 1:
            area = square();
            break;
        case 2:
            area = rectangle();
            break;
        case 3: 
            area = circle();
            break;
    }
    printf("Area is: %f\n", area);
}

float square(void) 
{
    // Unsigned variable input since squares cannot have negative side lengths
    printf("\nEnter side length of a square in cm: ");
    float s;
    scanf("%f", &s);
    return s*s;
}

float rectangle(void)
{
    // Length and height are unsigned since they cannot have negative values
    printf("\nEnter length of a rectangle in cm: ");
    float l;
    scanf("%f", &l);

    printf("Enter width of a rectangle in cm: ");
    float w;
    scanf("%f", &w);

    return l * w;
}

float circle(void)
{
    printf("Enter radius of circle in cm: ");
    float r;
    scanf("%f", &r);

    // Formula used: A = πr^2
    return PI * r * r;
}