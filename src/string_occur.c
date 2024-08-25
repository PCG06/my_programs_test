// C program to count the number of occurrences of a character

#include <stdio.h>

void main()
{
    char str[20], ch;
    int i, occur=0;

    printf("Enter the string: ");
    scanf("%[^\n]s", str);
    printf("Enter the character to count occurrences of: ");
    scanf(" %c", &ch);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
        {
            occur++;
        }
    }

    if (occur > 0)
    {
        if (occur == 1)
        {
            printf("\nThere is 1 occurrence of %c\n", ch);
        }
        else 
        {
            printf("\nThere are %d occurrences of %c\n", occur, ch);
        }
    }
    else
    {
        printf("\nThere are no occurrences of %c\n", ch);
    }
}
