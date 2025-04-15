// Program to evaluate a postfix expression

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int compute(char sym, int op1, int op2);

void main()
{
    char postfix[25], sym;
    int stack[25], top = -1, i, res = 0, op1, op2;
    
    // Input
    printf("Enter the postfix expression: ");
    scanf("%[^\n]s", postfix);

    // Process
    for (i = 0; i < strlen(postfix); i++)
    {
        sym = postfix[i];
        if (isspace(sym))
            continue;
        else if (isdigit(sym))
            stack[++top] = sym - '0'; // Since its a symbol, we need to minus by '0' to get the real number
        else
        {
            op2 = stack[top--];
            op1 = stack[top--];
            res = compute(sym, op1, op2);
            stack[++top] = res;
        }
    }
    res = stack[top];

    // Output
    printf("Evaluation is %d\n", res);
}

int compute(char sym, int op1, int op2)
{
    switch (sym)
    {
        case '+': return (op1 + op2);
        case '-': return (op1 - op2);
        case '*': return (op1 * op2);
        case '/': return (op1 / op2);
        case '%': return (op1 % op2);
        case '^': return (pow(op1, op2));
        default: return 0;
    }
}