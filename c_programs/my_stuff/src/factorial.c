// C program to print factorial of a number

#include <stdio.h>

void main()
{
    int number, i, j;
    unsigned long long result = 1;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("\nCalculating factorial of %d:\n", number);

    for (int i = 1; i <= number; ++i)
    {
        if (i <= number - 1) // To show the * sign everytime except the last time
            printf("%d * ", i);
        else
            printf("%d\n", i);

        result *= i;
    }

    printf("\nFactorial of %d is %llu\n", number, result);
}
