#include<stdio.h> 

void quick_sort(int arr[],int l,int h) 
{
    int i, j, t, key, flag = 0;

    if (l < h) 
    { 
        i = l; 
        j = h + 1; 
        key = arr[l]; 
        do 
        { 
            do 
            { 
                i++; 
            } while (arr[i] < key); 
            do 
            { 
                j--; 
            } while (arr[j] > key); 

            if (i < j) 
            { 
                t = arr[i]; 
                arr[i] = arr[j]; 
                arr[j] = t; 
            } 
            else 
            { 
                flag = 1; 
                t = arr[j]; 
                arr[j] = arr[l]; 
                arr[l] = t; 
            } 
        } while (flag == 0); 

    quick_sort(arr, l, j-1); 
    quick_sort(arr, j+1, h); 
    } 
} 

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