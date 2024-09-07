/* C program to write a string
- Count thew number of letters, vowels, consonents, digits, spaces and special characters present in it */

#include <stdio.h>
#include <ctype.h>

void main()
{
    char str[20], ch;
    int lc = 0, vc = 0, cc = 0, dc = 0, sp = 0, sc = 0, i;

    printf("Enter the string: ");
    scanf("%[^\n]s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if(isalpha(str[i]))
        {
            lc++;
            ch = str[i];

            switch (toupper(ch))
            {
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    vc++;
                    break;
                default:
                    cc++;
                    break;
            }
        }

        else if (isdigit(str[i]))
                dc++;

        else if (isspace(str[i]))
                sp++;

        else
            sc++;
    }

    printf("\nNumber of letters: %d", lc);
    printf("\nNumber of vowels: %d", vc);
    printf("\nNumber of consonents: %d", cc);
    printf("\nNumber of digits: %d", dc);
    printf("\nNumber of spaces: %d", sp);
    printf("\nNumber of special characters: %d\n", sc);
}