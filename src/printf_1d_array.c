// C program to read and write a 1d array

#include <stdio.h>

void main()
{
    int a[20], i, n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("\nThe array elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    
    printf("\n");
}