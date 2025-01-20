// Program to perform merge sort

#include <stdio.h>

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);

void main()
{
    int n, i, arr[100];

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

    // Call merge sort
    mergeSort(arr, 0, n - 1);

    // Output
    printf("Sorted array is:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to perform merge sort
void mergeSort(int arr[], int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;

        // Recursively sort the two halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the two sorted halves
        merge(arr, low, mid, high);
    }
}

// Function to merge two sorted halves
void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low, b[100];

    // Merge the two halves into arr temporary array b
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }

    // Copy remaining elements of the left half (if any)
    while (i <= mid)
        b[k++] = arr[i++];

    // Copy remaining elements of the right half (if any)
    while (j <= high)
        b[k++] = arr[j++];

    // Copy the sorted elements back to the original array
    for (i = low; i <= high; i++)
        arr[i] = b[i];
}
