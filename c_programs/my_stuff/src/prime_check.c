// C program to check whether number read is a prime number or not 

#include <stdio.h>

void main()
{
    unsigned long int num, i, primeNum = 1;

    printf("Enter a number: ");
    scanf("%lu", &num);

    if (num <= 1)
    {
        primeNum = 0;
    }
    else
    {
        for (i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                primeNum = 0;
                break;
            }
        }
    }

    if (primeNum)
    {
        printf("%lu is a prime number.\n", num);
    }
    else
    {
        printf("%lu is not a prime number.\n", num);
    }
}
