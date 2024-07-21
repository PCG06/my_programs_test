/* C program to find largest of 2 numbers
- Using if condition */

#include <stdio.h>

void main()
{
    int a, b;

    input:
    {
        printf("Enter the two no's: ");
        scanf("%d%d", &a, &b);
    }

    // In case both values are the same, return to input
    if (a == b)
    {
        printf("Enter two different values!\n\n");
        goto input;
    }
    else if (a > b)
    {
        printf("\nA = %d is greater than B = %d\n", a, b);
    }
    else
    {
        printf("\nB = %d is greater than A = %d\n", b, a);
    }
}