// C Program with dynamic number of arguments

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int sum(int count, ...)
{
    va_list args;
    va_start(args, count); // Initialize the argument list

    int total = 0;
    for (int i = 0; i < count; i++)
        total += va_arg(args, int); // Retrieve next argument

    va_end(args); // Clean up
    return total;
}

int main()
{
    printf("Sum: %d\n", sum(3, 10, 20, 30));
    printf("Sum: %d\n", sum(5, 1, 2, 3, 4, 5));

    return EXIT_SUCCESS;
}
