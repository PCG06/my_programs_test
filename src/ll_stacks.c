#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

struct node
{
    int val;
    struct node *next;
};

struct node *top = NULL;

void main()
{
    int choice;

    do
    {
        printf("\n--- Stack Operations ---\n");
        printf("1. Insert (Push)\n");
        printf("2. Delete (Pop)\n");
        printf("3. Display Stack\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
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

void push()
{
    int val;
    struct node *ptr;

    ptr = (struct node *) malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("Stack overflow! Cannot push.\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &val);

    ptr->val = val;
    ptr->next = top;
    top = ptr;

    printf("Item pushed\n");
}

void pop()
{
    struct node *ptr;

    if (top == NULL)  
    {  
        printf("Stack underflow! Cannot pop.\n");
        return;
    }

    ptr = top;
    top = top->next;
    free(ptr);

    printf("Item popped\n");
}

void display()
{
    struct node *ptr;

    if (top == NULL)
    {  
        printf("Stack Underflow!\n");
        return;
    }

    printf("Stack contents: ");
    ptr = top;
    while (ptr != NULL)
    {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}
