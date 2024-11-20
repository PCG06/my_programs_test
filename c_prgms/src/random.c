// C program to print a random 16-bit number

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Random()
{
    srand((unsigned int)time(NULL));
    // Generate a random number and mask it to fit within 16 bits
    return (int)(rand() & 0xFFFF);
}

void main()
{
    unsigned int num, random;

    printf("Enter maximum limit: ");
    scanf("%u", &num);

    random = (Random() % num + 1);

    printf("Random 16-bit number: %u\n", random);
}