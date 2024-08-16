// C program to convert binary numbers to decimal numbers

#include <stdio.h>

int main()
{
    unsigned long int bin, deci = 0, place = 1, rem;

    printf("Enter the bin number: ");
    scanf("%lu", &bin);

    while (bin > 0)
    {
        rem = bin % 10;
        deci += rem * place;
        bin /= 10;
        place *= 2;
    }

    printf("Decimal value is %lu\n", deci);

    return 0;
}
