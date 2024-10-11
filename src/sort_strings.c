// C program to sort a list of strings in ascending order using pointers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char *y[], int m);

void main()
{
    char *x[20];
    int n, i;

    printf("Enter the no. of strings: ");
    scanf("%d", &n);

    printf("Enter the strings:\n");
    for (i = 0; i < n; i++)
    {
        x[i] = (char *)malloc(20 * sizeof(char));
        scanf("%s", x[i]);
    }

    sort(x, n);

    printf("Sorted strings are\n");
    for (i = 0; i < n; i++)
        printf("%s\n", x[i]);
}

void sort(char *y[], int m)
{
    char t[20];
    int i, j;

    for (i = 0; i < m - 1; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            if (strcmp(y[i], y[j]) > 0)
            {
                strcpy(t, y[i]);
                strcpy(y[i], y[j]);
                strcpy(y[j], t);
            }
        }
    }

    return;
}