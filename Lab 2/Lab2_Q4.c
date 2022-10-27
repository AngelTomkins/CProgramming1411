// Angel Tomkins <atomkins@lakeheadu.ca>
// 1187799
// Sept 24, 2022
// Fedora Linux 36, GCC 12.1.0

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
void square(void);
void rectangle(void);
void circle(void);

int main (void) 
{
    // Loop in case the input is not one of the options, if a proper option
    // is chosen the program will return successful
    do {
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
                break;
            case 1:
                square();
                return 0;
            case 2:
                rectangle();
                return 0;
            case 3: 
                circle();
                return 0;
        }
    //Loop is always running, the only way to escape is choosing a menu option
    } while (1);
}

void square(void) 
{
    // Unsigned variable input since squares cannot have negative side lengths
    printf("\nEnter side length of a square in cm: ");
    unsigned long s;
    scanf("%u", &s);
    printf("Perimiter of square: %u cm\nArea of square: %u cm^2\n", s*4, s*s);
    return;
}

void rectangle(void)
{
    // Length and height are unsigned since they cannot have negative values
    printf("\nEnter length of a rectangle in cm: ");
    unsigned int l;
    scanf("%u", &l);

    printf("Enter width of a rectangle in cm: ");
    unsigned int w;
    scanf("%u", &w);

    printf("Perimeter of rectangle: %u cm"
            "\nArea of rectangle: %u\n",
            2*(l+w), l * w);
    return;
}

void circle(void)
{
    printf("Enter radius of circle in cm: ");
    unsigned int r;
    scanf("%lu", &r);

    // Formulas used: P = 2πr, A = πr^2
    printf("Perimeter of Circle: %f cm"
           "\nArea of circle: %f cm\n", 2 * PI * r, PI * r * r);

    return;
}