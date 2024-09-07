// C program to check whether a given number is armstrong number or not

#include <stdio.h>

int isArmstrong(int num); 

void main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num == isArmstrong(num))
        printf("%d is an armstrong number\n", num);
    else
        printf("%d is not an armstrong number\n", num);
}

int isArmstrong(int num)
{
    int rem, sum = 0;

    while (num > 0)
    {
        rem = num % 10;
        sum = sum + (rem * rem * rem);
        num /= 10;
    }

    return sum;
}

