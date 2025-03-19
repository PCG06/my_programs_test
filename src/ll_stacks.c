// Program to perform stack operations using linked list

#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();

struct node
{
    int info;
    struct node *link;
};

struct node *top = NULL; // Initialize top pointer

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
    int info;
    struct node *ptr;

    ptr = (struct node *) malloc(sizeof(struct node)); // Allocate memory for new node
    if (ptr == NULL)
    {
        printf("Stack overflow! Cannot push.\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &info);

    ptr->info = info;
    ptr->link = top; // Point to top as link node
    top = ptr; // Update top to point to the new node

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

    ptr = top; // Remove top element
    top = top->link; // Top moves to the link node
    free(ptr); // Free memory of the removed node

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
    ptr = top; // Start from top and traverse till end
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->link; // Keep traversing
    }
    printf("\n");
}
