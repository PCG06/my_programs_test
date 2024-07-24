/* C program to accept student marks in 5 subjects.
 - Find the total and percentage.
 - Print grade declaration if pass.
 - If fail, print fail. */

#include <stdio.h>

void main()
{
    int m1, m2, m3, m4, m5, total;
    float perc;

    printf("Enter the marks in first subject: ");
    scanf("%d", &m1);
    printf("Enter the marks in second subject: ");
    scanf("%d", &m2);
    printf("Enter the marks in third subject: ");
    scanf("%d", &m3);
    printf("Enter the marks in fourth subject: ");
    scanf("%d", &m4);
    printf("Enter the marks in fifth subject: ");
    scanf("%d", &m5);

    total = m1 + m2 + m3 + m4 + m5;
    perc = total / 5.0;

    printf("\nTotal marks = %d", total);
    printf("\nAverage marks = %.2f\n", perc);

    if (m1 >= 35 && m2 >= 35 && m3 >= 35 && m4 >= 35 && m5 >= 35)
    {

        if (perc >= 70)
        {
            printf("\nResult is DISTINCTION!\n");
        }
        else if (perc >= 60)
        {
            printf("\nResult is FIRST CLASS!\n");
        }
        else if (perc >= 50)
        {
            printf("\nResult is SECOND CLASS!\n");
        }
        else
        {
        printf("\nResult is PASS CLASS!\n");
        }
    }
    else
    {
        printf("\nResult is FAIL.\n");
    }
}