// C program to perform addition and subtraction on 2 equal matrices

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a1[10][10], a2[10][10], add[10][10], sub[10][10], r1, r2, c1, c2, i, j;

    printf("Enter row size for array 1: ");
    scanf("%d", &r1);

    printf("Enter column size for array 1: ");
    scanf("%d", &c1);

    printf("Enter the elements for array 1:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", &a1[i][j]);
        }
    }

    printf("Enter row size for array 2: ");
    scanf("%d", &r2);

    printf("Enter column size for array 2: ");
    scanf("%d", &c2);

    printf("Enter the elements for array 2:\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            scanf("%d", &a2[i][j]);
        }
    }

    if (r1 == r2 && c1 == c2)
    {
        for (i = 0; i < r2; i++)
        {
            for (j = 0; j < c2; j++)
            {
                add[i][j] = a1[i][j] + a2[i][j];
                sub[i][j] = a1[i][j] - a2[i][j];
            }
        }

        printf("The sum of two matrices are:\n");
        for (i = 0; i < r2; i++)
        {
            for (j = 0; j < c2; j++)
            {
                printf("%d\t", add[i][j]);
            }
            printf("\n");
        }

        printf("The difference of two matrices are:\n");
        for (i = 0; i < r2; i++)
        {
            for (j = 0; j < c2; j++)
            {
                printf("%d\t", sub[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Two matrices are incompatible!\nMatrix addition and subtraction is not possible!\n");
        exit(0);
    }
}
