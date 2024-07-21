/* C program to swap 2 numbers
- Without using a temporary variable */

#include <stdio.h>

int main()
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

    printf("\nValues of A and B before swapping = %d %d", a, b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("\nValues of A and B after swapping = %d %d\n", a, b);

    return 0;
}