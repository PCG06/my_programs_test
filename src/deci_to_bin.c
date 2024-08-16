// C program to convert decimal numbers to binary numbers

#include <stdio.h>

void main()
{
    unsigned long int deci, bin = 0, rem, place = 1, temp;

    printf("Enter the decimal number: ");
    scanf("%lu", &deci);

    temp = deci;

    while (temp > 0)
    {
        rem = temp % 2;
        bin = bin + rem * place;
        temp /= 2;
        place *= 10;
    }

    printf("Binary value of %lu is %lu\n", deci, bin);
}
