// C program to check whether number read is a prime number or not 

#include <stdio.h>
#include <stdbool.h>

// Declaring the function before defining it let's me call the function before it's definition.
static bool isPrimeNumber(int num);

void main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPrimeNumber(num) == true)
    {
        printf("\n%d is a prime number!\n", num);
    }
    else
    {
        printf("\n%d is not a prime number!\n", num);
    }
}

static bool isPrimeNumber(int num)
{
    int i;

    if (num <= 1)
    {
        return false;
    }
    else
    {
        for (i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    return false;
}
