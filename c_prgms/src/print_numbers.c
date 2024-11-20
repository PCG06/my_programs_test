// C program to print N number of numbers
// Honestly no idea what I'm doing lol

#include <stdio.h>

void main()
{
    int n;
    unsigned long int i;

    printf("Enter the number of numbers to be printed: ");
    scanf("%d", &n);

    printf("\n");
    for (i = 1; i <= n; i++)
    {
        printf("%lu ", i);
    }
    printf("\n");
}