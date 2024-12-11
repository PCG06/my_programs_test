// C program to sort numbers in ascending order using bubble sort

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n);

int main()
{
    int arr[25] = {0};
    int n = 0, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Array before sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    // Call the bubble sorting function
    bubbleSort(arr, n);

    printf("\nArray after sorting:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return EXIT_SUCCESS;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
