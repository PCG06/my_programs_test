// C program to generate a pattern using for loop

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
            printf("%c", sym);
        }
        printf("\n");
    }
}
