// C program to find simple interest

#include <stdio.h>

int main()
{
    int p, t, r, si;

    printf("Enter the principle amount: ");
    scanf("%d", &p);
    printf("Enter the time: ");
    scanf("%d", &t);
    printf("Enter the rate: ");
    scanf("%d", &r);

    si = (p*t*r)/100;

    printf("\nSimple interest = %d\n", si);
}
