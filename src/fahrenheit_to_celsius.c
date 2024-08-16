// C program to convert Fahrenheit to Celsius 

#include <stdio.h>

void main()
{
    float fahr, cels;

    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahr);

    cels = (fahr - 32) * 5 / 9;

    printf("\nTemperature %.2f°F is %.2f°C\n", fahr, cels);
}
