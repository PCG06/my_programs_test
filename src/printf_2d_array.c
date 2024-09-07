// C program to read and write a 2d array

#include <stdio.h>

void main()
{
    int a[20][20], rowsize, colsize, i, j;

    printf("Enter the row size of the array: ");
    scanf("%d", &rowsize);

    printf("Enter the column size of the array: ");
    scanf("%d", &colsize);

    printf("Enter the elements:\n");
    for (i = 0; i < rowsize; i++)
    {
        for (j = 0; j < colsize; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nThe 2D array elements are:\n");
    for (i = 0; i < rowsize; i++)
    {
        for (j = 0; j < colsize; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}