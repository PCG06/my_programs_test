/* C program to read numbers and stop when read 999. 
 Find the sum total value of all positive numbers */

#include <stdio.h>

void main()
{
    int n = 0, sum = 0;

    printf("Enter the number continously.\nPress 999 to stop! ");

    do
    {
        scanf("%d", &n);

        if (n > 0 && n != 999)
        {
            sum += n;
        }
    } while (n < 999);

    printf("Sum of positive integers is: %d\n", sum);
}