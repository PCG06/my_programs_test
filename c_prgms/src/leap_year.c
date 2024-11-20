// C program to check whether a year is a leap year or not

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int year = 2000, isLeap = 0;
    printf("Enter a year: ");
    scanf("%d", &year);

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        isLeap = 1;

    if (isLeap)
        printf("It is a leap year\n");
    else
        printf("It is not a leap year\n");

    return EXIT_SUCCESS;
}