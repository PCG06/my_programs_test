/* C program to find largest of 3 numbers
- Using conditional operators */

#include <stdio.h>
void main()
{
    int a, b, c, great;

    input:
    {
        printf("Enter the three no's: ");
        scanf("%d%d%d", &a, &b, &c);
    }

    // In case all values are the same, return to input
    if ((a == b) && (b == c))
    {
        printf("Enter three different values!\n\n");
        goto input;
    }
    else 
        great = ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c));

    if (great == a)
    {
        printf("\nA = %d is greater than B = %d and C = %d\n", a, b, c);
    }
    else if (great == b)
    {
        printf("\nB = %d is greater than A = %d and C = %d\n", b, a, c);
    }
    else
    {
        printf("\nC = %d is greater than A = %d and B = %d\n", c, a, b);
    }
}