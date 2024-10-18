#ifndef	CUSTOM_H
#define CUSTOM_H

#include <string.h>

char *strrev(char *str)
{
    char *start = str;
    char *end = str + strlen(str) - 1;
    char temp;

    // Swap characters from start and end towards the middle
    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    return str;
}

#endif // CUSTOM_H