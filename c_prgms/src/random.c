// C program to print a random 16-bit number

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Random(void)
{
    srand((unsigned int)time(NULL));
    // Generate a random number and mask it to fit within 16 bits
    return (int)(rand() & 0xFFFF);
}

int main(void)
{
    unsigned int num = 0;
    
    printf("Enter maximum limit: ");
    scanf("%u", &num);

    const int random = (Random() % num + 1);

    printf("Random 16-bit number: %u\n", random);

    return EXIT_SUCCESS;
}