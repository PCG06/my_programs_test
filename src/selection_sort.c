// Program to perform selection sort (ascending order)

#include <stdio.h>

void selectionSort(int arr[], int n);

void main()
{
    int arr[100], n, i;

    // Input
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("The array elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Process
    selectionSort(arr, n);

    // Output
    printf("Sorted array is:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void selectionSort(int arr[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])  // Find the minimum element
                min = j;
        }

        // Swap if minimum is not at the current position
        if (min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    return;
}