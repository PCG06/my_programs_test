// C program to convert Celsius to Fahrenheit

#include <stdio.h>

void main()
{
    float cels, fahr;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &cels);

    fahr = (cels * 9 / 5) + 32;

    printf("\nTemperature %.2f°C is %.2f°F\n", cels, fahr);
}
