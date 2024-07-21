/* C program to find area of a triangle 
Formula: https://en.wikipedia.org/wiki/Area_of_a_triangle#Using_side_lengths_(Heron's_formula) */

#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    float sides, area;

    printf("Enter the sides = ");
    scanf("%d%d%d", &a, &b, &c);

    sides = (a + b + c) / 2.0;
    area = sqrt(sides * (sides - a) * (sides - b) * (sides - c));

    printf("\nArea of triangle with sides %d, %d, %d = %.2f\n", a, b, c, area);

    return 0;
}