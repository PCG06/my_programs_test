// C program to convert Fahrenheit to Celsius 

#include <stdio.h>

void main()
{
    float fahr, cels;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahr);

    cels = (fahr - 32) * 5 / 9;

    printf("\nTemperature %.2f in Fahrenheit is %.2f in Celsius\n", fahr, cels);
}
