// Program for binary search method

#include <stdio.h>

int binarySearch(int arr[], int n, int se);

void main()
{
    int arr[100], n, i, se, pos;

    // Input
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the search element: ");
    scanf("%d", &se);

    printf("The array elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Process
    pos = binarySearch(arr, n, se);

    // Output
    if (pos > 0)
        printf("Element found at location %d", pos);
    else
        printf("Search unsuccessful");
    printf("\n");
}

int binarySearch(int arr[], int n, int se)
{
    int loc = -1, low = 0, high = n - 1, mid;

    // Process - binary search logic
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (se == arr[mid]) // element found
        {
            loc = mid;
            break;
        }
        else if (se < arr[mid]) // search left half
            high = mid - 1;
        else // search right half
            low = mid + 1;
    }
    return loc + 1;
}
