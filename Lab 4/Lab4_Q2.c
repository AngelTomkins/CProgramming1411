// Angel Tomkins <atomkins@lakeheadu.ca>
// 1187799
// Oct 25, 2022
// Arch Linux, GCC 12.2.0

#include <stdio.h>
#include <stdlib.h>
// math.h requires GCC to be run with -lm to compile
#include <math.h>   

// Specific implementation of +/- for the for statement that 0 <= i <= 1 
#define PLUS_OR_MINUS(i) ( (i==0)-(i==1) )


// Find and return the roots of a quadratic with real roots
// Returns a pointer to a two dimensional array of floats. This pointer must
// be freed before the end of the program.
float* find_roots(float* a, float* b, float* c)
{   
    // Memory representation of pointer roots:
    // [0] = [root 1]
    // [1] = [root 2]
    float *roots = (float*) malloc(sizeof(float) * 2);

    // For each root, calculate += sqrt() using a macro 
    for (int i = 0; i < 2; i++) {
        roots[i] =
            (-*b +                                         // -b
            PLUS_OR_MINUS(i) * sqrt(*b * *b - 4 * *a * *c))// +- sqrt(b^2 - 4ac)
            * ( 1 / ( 2.0 * *a) );                         // / 2a
    }

    return roots;
}

// Find and return the roots of a quadratic with complex roots
// Returns a pointer to a two dimensional array of floats. This pointer must
// be freed before the end of the program.
float* find_roots_imaginary(float* a, float* b, float* c)
{
    // Memory representation of pointer roots:
    // [0] = [real part of root 1]
    // [1] = [imagnary part of root 1]
    // [2] = [real part of root 2]
    // [3] = [imaginary part of root 2]
    float *roots = (float*) malloc(sizeof(float) * 4);

    // For each root, calculate += sqrt() using a macro 
    for (int i = 0; i < 2; i++) {

        // Real part of roots
        // -b / 2a
        roots[2*i+i] = (-*b) / (2.0 * *a);  
        
        // imaginary part of the roots
        // [ +-sqrt(b^2 - 4ac) ] / 2a
        roots[2*i+1] = 
            PLUS_OR_MINUS(i) * sqrt(-(*b * *b - 4 * *a * *c))
            / (2.0 * *a);
    }
    return roots;
}



void CheckRoots(float* a, float* b, float* c)
{   
    if ((*b * *b - (4 * *a * *c)) < 0) {
        // Real roots do not exist
        float * roots = find_roots_imaginary(a, b, c);     
        printf( "The roots of this function are complex:\n"
                "y = %.3fx^2 + %.3fx + %.3f are:\n"
                "x = %.3f + %.3fi\nx = %.3f + %.3fi\n",
                *a, *b, *c, roots[0], roots[1], roots[2], roots[3]);
        free(roots);

    } else {
        // Real roots do exist
        float * roots = find_roots(a, b, c);
        printf( "The roots of this function are real\n"
                "y = %.3fx^2 + %.3fx + %.3f are: \n"
                "x = %.3f\nx = %.3f\n",
                *a, *b, *c, roots[0], roots[1]);
        free(roots);
    }
}


int main(void) 
{
    float a, b, c;

    printf("Input variables for a function in terms of ax^2 + bx + c = 0\n");

    printf("a: ");
    scanf("%f", &a);
    
    printf("b: ");
    scanf("%f", &b);
    
    printf("c: ");
    scanf("%f", &c);

    CheckRoots(&a, &b, &c);

    return 0;
}