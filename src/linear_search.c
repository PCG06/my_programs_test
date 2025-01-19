// Program for linear search method

#include <stdio.h>

int linearSearch(int arr[], int n, int se);

void main()
{
    int arr[100], n, i, se, loc;

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
    loc = linearSearch(arr, n, se);

    // Output
    if (loc > 0)
        printf("Element found at location %d", loc);
    else
        printf("Search unsuccessful");
    printf("\n");
}

int linearSearch(int arr[], int n, int se)
{
    int i, loc = -1;

    // Process - linear search logic
    for (i = 0; i < n; i++)
    {
        if (se == arr[i])
        {
            loc = i;
            break;
        }
    }
    return loc + 1;
}
