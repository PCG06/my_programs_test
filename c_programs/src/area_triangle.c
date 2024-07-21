/* C program to find area of a triangle 
Formula: https://en.wikipedia.org/wiki/Area_of_a_triangle#Using_side_lengths_(Heron's_formula) */

#include <stdio.h>
#include <math.h>

void main()
{
    float a, b, c, sides, area;

    printf("Enter 3 sides: ");
    scanf("%f%f%f", &a, &b, &c);

    sides = (a + b + c) / 2.0;
    area = sqrt(sides * (sides - a) * (sides - b) * (sides - c));

    printf("\nArea of triangle = %.2f\n", area);
}