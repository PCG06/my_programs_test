// C program to print N number of numbers
// Honestly no idea what I'm doing lol

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 0;
    
    printf("Enter the number of numbers to be printed: ");
    scanf("%d", &n);

    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    return EXIT_SUCCESS;
}