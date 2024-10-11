// C program to print factorial of a number

#include <stdio.h>

int factorial(int num);

void main()
{
    int n, num, i, fact;

    printf("Enter the value for n: ");
    scanf("%d", &n);

    printf("Enter the number: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num);
        fact = factorial(num);
        printf("The factorial of %d is %d\n", num, fact);
    }
}

int factorial(int num)
{
    if (num > 1)
        return (num * factorial(num - 1));
    else
        return 1;
} 