// Program to perform bubble sort (ascending order)

#include <stdio.h>

void bubbleSort(int arr[], int n);

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
    bubbleSort(arr, n);

    // Output
    printf("Sorted array is:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    // Process - bubble sort logic
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return;
}
