/* C program to read a number and reverse it
- And print the sum total. */

#include <stdio.h>

void main()
{
    // This program only works for positive numbers, so might as well take `long unsigned int` over `long int`
    long unsigned int num, rev = 0, sum = 0, temp, rem;

    printf("Enter a number: ");
    scanf("%ld", &num);

    temp = num;
    while (num > 0)
    {
        rem = num % 10;
        sum = sum + rem;
        rev = (rev * 10) + rem;
        num = num / 10;
    }
    num = temp;

    printf("\nThe reverse of %ld is %ld", num, rev);
    printf("\nThe sum of individual numbers is %ld\n", sum);
}