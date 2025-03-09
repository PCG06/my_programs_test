// Program to perform quick sort (ascending order)

#include <stdio.h>

void quick_sort(int arr[], int l, int h);

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
    quick_sort(arr, 0, n - 1);

    // Output
    printf("Sorted array is:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Quick sort function
void quick_sort(int arr[], int l, int h)
{
    int i, j, t, key, flag = 0;

    if (l < h)
    {
        i = l;
        j = h + 1;
        key = arr[l]; // Pivot element

        do
        {
            // Move i to the right until an element >= key is found
            do
            {
                i++;
            } while (arr[i] < key);

            // Move j to the left until an element <= key is found
            do
            {
                j--;
            } while (arr[j] > key);

            // Swap elements if i and j haven't crossed
            if (i < j)
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
            // Swap pivot with the correct position element
            else
            {
                flag = 1;
                t = arr[j];
                arr[j] = arr[l];
                arr[l] = t;
            }
        } while (flag == 0);

        // Recursively sort the left and right partitions
        quick_sort(arr, l, j - 1);
        quick_sort(arr, j + 1, h);
    }
}
