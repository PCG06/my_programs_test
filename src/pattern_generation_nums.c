// C program to generate a pattern using numbers and symbols for loop

#include <stdio.h>

void main()
{
    char sym;
    int i, j, num;

    printf("Enter the character to be used: ");
    scanf(" %c", &sym);

    printf("Enter the number of times to be printed: ");
    scanf("%d", &num);

    for (i = 0; i <= num; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%c%d", sym, j);
        }
        printf("\n");
    }
}