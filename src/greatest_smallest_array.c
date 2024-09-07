// C program to read an array and find the greates and smallest element along with its position

#include <stdio.h>

void main()
{
    int a[20], i, n, great, small, gpos = 1, spos = 1;


    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    great = small = a[0];
    for (i =0; i < n; i ++)
    {
        if (a[i] > great)
        {
            great = a[i];
            gpos = i + 1;
        }
        else if (a[i] < small)
        {
            small = a[i];
            spos = i + 1;
        }
    }

    printf("\nThe greatest is %d and its position is %d", great, gpos);
    printf("\nThe smallest is %d and its position is %d\n", small, spos);
}