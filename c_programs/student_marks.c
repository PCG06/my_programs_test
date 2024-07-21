/* C program to accept student marks in 3 subjects.
 - Find the total and average. */

#include <stdio.h>

int main()
{
    int m1, m2, m3, total;
    float avg;

    printf("Enter the marks in first subject = ");
    scanf("%d", &m1);
    printf("Enter the marks in second subject = ");
    scanf("%d", &m2);
    printf("Enter the marks in third subject = ");
    scanf("%d", &m3);

    total = m1 + m2 + m3;
    avg = total / 3.0;

    printf("\nTotal marks = %d", total);
    printf("\nAverage marks = %.2f\n", avg);

    return 0;
}