// Program to perform queue operations using linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode();
NODE ins_end(NODE first, int item);
NODE del_beg(NODE first);
void display(NODE first);

void main()
{
    NODE first = NULL; // Initialize first pointer
    int choice, item;

    do
    {
        printf("\n--- Queue Operations ---\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display Queue\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter the value: ");
                scanf("%d", &item);
                first = ins_end(first, item);
                break;
            case 2:
                first = del_beg(first);
                break;
            case 3:
                display(first);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
}

NODE getnode()
{
    NODE x = (NODE) malloc(sizeof(struct node)); // Allocate memory for a new node
    if (x == NULL) 
    {
        printf("\nNo free space\n");
        exit(0);
    }
    return x;
}

NODE ins_end(NODE first, int item)
{
    NODE temp = getnode(); // Create new node
    temp->info = item; // Assign value to new node
    temp->link = NULL; // Last node points to NULL
    NODE curr;

    if (first == NULL)
        first = temp; // If list is empty, new node becomes the first node
    else
    {
        curr = first; // Traverse to the end of the list
        while (curr->link != NULL)
            curr = curr->link;
        
        curr->link = temp; // Link the new node at the end
    }
    return first;
}

NODE del_beg(NODE first)
{
    NODE temp;
    if (first == NULL)
        printf("Queue underflow! Cannot dequeue.\n");
    else
    {
        printf("\nDeleted element is %d", first->info); // Display deleted element
        temp = first; // Store current first node to free later
        first = first->link; // Move first pointer to the next node
        free(temp); // Free memory of deleted node
    }
    return first;
}

void display(NODE first)
{
    NODE curr;
    if (first == NULL)
        printf("Queue underflow!\n");
    else
    {
        printf("Queue contents:\n");
        curr = first; // Traverse from first to end
        while (curr != NULL)
        {
            printf("%d ", curr->info);
            curr = curr->link; // Move to the next node
        }
    }
    printf("\n");
}
