// C program to print factorial of a number

#include <stdio.h>

int factorialNum(int num);

void main()
{
    int num, fact;

    printf("Enter the number: ");
    scanf("%d", &num);

    fact = factorialNum(num);

    printf("The factorial of %d is %d\n", num, fact);
}

int factorialNum(int num)
{
    int i, fact = 1;

    for (i = 1; i <= num; i++)
        fact *= i;
    
    return fact;
} 