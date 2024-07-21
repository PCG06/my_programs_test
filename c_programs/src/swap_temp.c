/* C program to swap 2 numbers
- Using a temporary variable */

#include <stdio.h>

int main()
{
    int a, b, temp;

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

    temp = a;
    a = b;
    b = temp;

    printf("\nValues of A and B after swapping = %d %d\n", a, b);

    return 0;
}