#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node *NODE;

NODE get_node();
NODE ins_end(NODE first, int item);
NODE del_pos(NODE first, int position);
void display(NODE first);

void main()
{
    int choice, item, position;
    NODE first = NULL;

    do
    {
        printf("\n1. Insert at the End");
        printf("\n2. Delete at Given Position");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &item);
                first = ins_end(first, item);
                break;

            case 2:
                printf("Enter the position of the element to be deleted: ");
                scanf("%d", &position);
                first = del_pos(first, position);
                break;

            case 3:
                display(first);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }
    while (choice != 4);
}

// Function to create a new node
NODE get_node()
{
    NODE x = (NODE)malloc(sizeof(struct Node));

    if (x == NULL)
    {
        printf("No Free Space\n");
        exit(0);
    }
    return x;
}

// Function to insert an element at the end of the list
NODE ins_end(NODE first, int item)
{
    NODE temp = get_node();
    temp->data = item;
    temp->link = NULL;

    if (first == NULL)
    {
        return temp;
    }

    NODE curr = first;
    while (curr->link != NULL)
    {
        curr = curr->link;
    }

    curr->link = temp;
    return first;
}

// Function to delete a node at a given position
NODE del_pos(NODE first, int position)
{
    if (first == NULL)
    {
        printf("Linked List is empty\n");
        return first;
    }

    NODE curr = first, prev = NULL;
    
    // Deleting the first node
    if (position == 1)
    {
        printf("Deleted element: %d\n", first->data);
        first = first->link;
        free(curr);
        return first;
    }

    // Traversing to the given position
    for (int i = 1; i < position && curr != NULL; i++)
    {
        prev = curr;
        curr = curr->link;
    }

    // If position is out of bounds
    if (curr == NULL)
    {
        printf("Invalid position!\n");
        return first;
    }

    prev->link = curr->link;
    printf("Deleted element: %d\n", curr->data);
    free(curr);
    
    return first;
}

// Function to display the linked list
void display(NODE first)
{
    if (first == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }

    NODE curr = first;
    printf("The Linked List is:\n");

    while (curr != NULL)
    {
        printf("%d\t", curr->data);
        curr = curr->link;
    }
    
    printf("\n");
}
