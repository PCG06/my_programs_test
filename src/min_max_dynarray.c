// Program to find the largest and smallest element in a dynamic array

#include <stdio.h>
#include <stdlib.h>

void main()
{
    int *arr, n, i, large, small, lpos = 1, spos = 1;

    // Input
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *) malloc(n * sizeof(int)); // Finding the size of the array

    if (arr != NULL) // In case of successful memory allocation
    {
        printf("Enter the elements:\n");
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        printf("The array elements are:\n");
        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);

        // Process
        large = small = arr[0];
        for (i = 1; i < n; i++)
        {
            if (arr[i] > large)
            {
                large = arr[i];
                lpos = i + 1;
            }
            else if (arr[i] < small)
            {
                small = arr[i];
                spos = i + 1;
            }
        }

        // Output
        printf("\nThe largest element is %d at position %d", large, lpos);
        printf("\nThe smallest element is %d at position %d", small, spos);
    }
    else
        printf("Dynamic allocation failed");
    printf("\n");

    // Free dynamically allocated memory
    free(arr);
}
