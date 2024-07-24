// C program to add 2 numbers using scanf

#include <stdio.h>

void main()
{
    int a, b, c;

    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);

    c = a + b;

    printf("\nThe sum of %d and %d is = %d\n", a, b, c);
}
