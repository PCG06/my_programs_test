// C program to mimic a simple calculator with basic arithmetic functions using switch statements

#include <stdio.h>

void main()
{
    char operator;
    double a, b, c;
    int intA, intB, intC;

    input:
    {   
        printf("Select an operation to perform: +, -, *, /, %%.\n");
        printf("Enter an arithmetic operator: ");
        scanf(" %c", &operator);
    }

    if ((operator != '+') && (operator != '-') && (operator != '*') && (operator != '/') && (operator != '%'))
    {
        printf("\nInvalid operator!\n\n");
        goto input;
    }
    else
    {
        printf("\nEnter two numbers: ");
        scanf("%lf%lf", &a, &b);
    }

    printf("\n");

    switch(operator)
    {
        case '+':
        {
            c = a + b;
            printf("Sum of %.2lf + %.2lf = %.2lf", a, b, c);
        }
        break;
        case '-':
        {
            c = a - b;
            printf("Difference of %.2lf - %.2lf = %.2lf", a, b, c);
        }
        break;
        case '*':
        {
            c = a * b;
            printf("Product of %.2lf * %.2lf = %.2lf", a, b, c);
        }
        break;
        case '/':
        {
            c = a / b;
            printf("Quotient of %.2lf / %.2lf = %.2lf", a, b, c);
        }
        break;
        case '%':
        {
            intA = (int) a;
            intB = (int) b;

            intC = intA % intB;
            printf("Remainder of %d %% %d = %d", intA, intB, intC);
        }
        break;
        default:
        {
            printf("Invalid.");
        }
    }

    printf("\n");
}
