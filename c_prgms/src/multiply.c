// C program to multiply 2 numbers

#include <stdio.h>

void main(void)
{
    int a, b, c;

    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);

    c = a * b;

    printf("\nThe product of %d and %d is = %d\n", a, b, c);
}
