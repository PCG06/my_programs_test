/* C program to add two distances in the inch-feet format using structures
- If inch is greater than 12, convert it to feet */

#include <stdio.h>

void main()
{
    struct distance
    {
        int feet;
        float inches;
    } d1, d2, sum;

    printf("Enter the first distance in feet: ");
    scanf("%d", &d1.feet);
    printf("Enter the first distance in inches: ");
    scanf("%f", &d1.inches);
    printf("Enter the second distance in feet: ");
    scanf("%d", &d2.feet);
    printf("Enter the second distance in inches: ");
    scanf("%f", &d2.inches);

    sum.feet = d1.feet + d2.feet;
    sum.inches = d1.inches + d2.inches;

    while (sum.inches >= 12)
    {
        sum.inches -= 12;
        sum.feet++;
    }

    printf("\nAdded distance is %d feet %.2f inches\n", sum.feet, sum.inches);
}