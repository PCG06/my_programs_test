// Program to perform stack operations using arrays

#include <stdio.h>

#define MAX 10

// Global variables for stack
int stack[MAX];
int top = -1;

// Function declarations
int isFull(void);
int isEmpty(void);
void push(void);
void pop(void);
void display(void);

void main()
{
    int choice;

    do
    {
        printf("\n--- Stack Operations ---\n");
        printf("1. Insert (Push)\n");
        printf("2. Delete (Pop)\n");
        printf("3. Display Stack\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
}

// Check if the stack is full
int isFull(void)
{
    return top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(void)
{
    return top == -1;
}

// Push operation
void push(void)
{
    int value;

    if (isFull())
        printf("Stack overflow! Cannot push.\n");
    else
    {
        printf("Enter value to push: ");
        scanf("%d", &value);
        stack[++top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

// Pop operation
void pop(void)
{
    if (isEmpty())
        printf("Stack underflow! Cannot pop.\n");
    else
        printf("Popped value: %d\n", stack[top--]);
}

// Display stack contents
void display(void)
{
    if (isEmpty())
        printf("Stack underflow!\n");
    else
    {
        printf("Stack contents: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}
