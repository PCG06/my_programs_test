// C program to check whether number read is a prime number or not 

#include <stdio.h>

void main()
{
    unsigned long int num, i, primeNum = 0;

    printf("Enter a number: ");
    scanf("%lu", &num);

    for (i = 2; i < num; i++)
    // for (i = 2; i <= n/2; i++) also works
    {
        if (num % i == 0)
        {
            // Not a prime number
            primeNum = 1;
            break;
        }
    }

    if (primeNum == 0)
    {
        printf("\n%lu is a prime number.\n", num);
    }
    else
    {
        printf("\n%lu is not a prime number.\n", num);
    }
}
