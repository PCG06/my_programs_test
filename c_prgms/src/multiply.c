// C program to multiply 2 numbers

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a = 0, b = 0;

    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);

    const int c = a * b;

    printf("\nThe product of %d and %d is = %d\n", a, b, c);

    return EXIT_SUCCESS;
}
