// C program to sort numbers in ascending order using insertion sort

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n);

int main()
{
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Array before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Call the insertion sorting function
    insertionSort(arr, n);

    printf("\nSorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return EXIT_SUCCESS;
}

void insertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Shift elements of arr[0...i-1] that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;  // Insert key into its correct position
    }
}
