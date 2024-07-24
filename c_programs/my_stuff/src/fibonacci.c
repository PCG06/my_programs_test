// C program to print N numbers of the Fibonacci series

#include <stdio.h>

void main()
{
    int n, i;
    unsigned long int f1 = 0, f2 = 1, next;

    printf("Enter a number of series to be printed: ");
    scanf("%d", &n);

    printf("Fibonacci series:\n");
    for (i = 1; i <= n; i++)
    {
        printf("%lu ", f1);
        next = f1 + f2;
        f1 = f2;
        f2 = next;
    }
    printf("\n");
}