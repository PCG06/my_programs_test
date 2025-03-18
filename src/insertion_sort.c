// Program to perform insertion sort (ascending order)

#include <stdio.h>

void insertionSort(int arr[], int n);

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
    insertionSort(arr, n);

    // Output
    printf("Sorted array is:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertionSort(int arr[], int n)
{
    int i, j, key;
    // Process - insertion sort logic
    for (i = 1; i < n; i++)  // Start from second element
    {
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > key; j--) // Shift elements that are greater than key
            arr[j + 1] = arr[j];
        arr[j + 1] = key;  // Place key in the correct position
    }
}
