#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double ScanExpression(const char *expr);
double ProcessExpression(double a, double b, char operator);

int main(void)
{
    char expression[250];

    // Prompt the user for an expression
    printf("Enter an expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Remove newline character if present
    expression[strcspn(expression, "\n")] = 0;

    // Evaluate the expression
    double result = ScanExpression(expression);

    printf("Result: %.2f\n", result);

    return 0;
}

double ScanExpression(const char *expr)
{
    double numbers[50]; // Array to store numbers
    char operators[50]; // Array to store operators
    int num_index = 0, op_index = 0;

    // Temporary variable to store the current number
    double current_num = 0;
    int has_num = 0;
    
    // Loop through the expression and parse numbers and operators
    for (int i = 0; i < strlen(expr); i++)
    {
        char ch = expr[i];
        
        if (isdigit(ch) || ch == '.')
        {
            // Build the current number
            current_num = current_num * 10 + (ch - '0');
            has_num = 1;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            if (has_num)
            {
                numbers[num_index++] = current_num;  // Push current number to the stack
                current_num = 0;  // Reset for the next number
                has_num = 0;
            }
            operators[op_index++] = ch;  // Push the operator to the stack
        }
    }
    
    // Push the last number to the stack
    if (has_num)
    {
        numbers[num_index++] = current_num;
    }

    // Evaluate multiplication and division first
    for (int i = 0; i < op_index; i++) {
        if (operators[i] == '*' || operators[i] == '/')
        {
            double a = numbers[i];
            double b = numbers[i + 1];
            numbers[i + 1] = ProcessExpression(a, b, operators[i]);  // Perform the operation
            // Shift operators and numbers to the left
            for (int j = i; j < op_index - 1; j++)
            {
                operators[j] = operators[j + 1];
            }
            for (int j = i; j < num_index - 1; j++)
            {
                numbers[j] = numbers[j + 1];
            }
            num_index--; op_index--; i--;  // Adjust indices after operation
        }
    }

    // Evaluate addition and subtraction
    double result = numbers[0];
    for (int i = 0; i < op_index; i++)
    {
        result = ProcessExpression(result, numbers[i + 1], operators[i]);
    }

    return result;
}

double ProcessExpression(double a, double b, char operator)
{
    switch (operator) 
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}
