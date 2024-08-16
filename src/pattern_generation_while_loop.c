// C program to generate a pattern using while loop

#include <stdio.h>

int main()
{
    char sym;
    int i = 1, j, num;

    printf("Enter the character to be used: ");
    scanf(" %c", &sym);

    printf("Enter the number of times to be printed: ");
    scanf("%d", &num);

    while (i <= num)
    {
        j = 1;
        while(j <= i)
        {
            printf("%c", sym);
            j++;
        }
        i++;
        printf("\n");
    }

    return 0;
}
