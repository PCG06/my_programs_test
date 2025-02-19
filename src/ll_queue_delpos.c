// Program to perform queue operations using linked lists and deleting an element at a given position

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
NODE del_pos(NODE first, int pos);
void display(NODE first);

void main()
{
    NODE first = NULL;
    int choice, item, pos;

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
                printf("\nEnter the item: ");
                scanf("%d", &item);
                first = ins_end(first, item);
                break;
            case 2:
                printf("\nEnter the position: ");
                scanf("%d", &pos);
                first = del_pos(first, pos);
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
    NODE x = (NODE) malloc(sizeof(struct node));
    if (x == NULL) 
    {
        printf("\nNo free space\n");
        exit(0);
    }
    x->link = NULL;
    return x;
}

NODE ins_end(NODE first, int item)
{
    NODE temp = getnode();
    temp->info = item;
    temp->link = NULL;

    if (first == NULL)
        return temp;

    NODE curr = first;
    while (curr->link != NULL)
        curr = curr->link;
    
    curr->link = temp;
    return first;
}

NODE del_pos(NODE first, int pos)
{
    NODE curr, prev;

    if (first == NULL)
    {
        printf("Queue underflow! Cannot dequeue.\n");
        return NULL;
    }
    else if (pos == 1)
    {
        printf("Deleted element is %d\n", first->info);
        first = first->link;
    }
    else
    {
        curr = first;
        for (int i = 1; i < pos; i ++)
        {
            prev = curr;
            curr = curr->link;
        }
        prev->link = curr->link;
        printf("Deleted element is %d\n", curr->info);
        free(curr);
    }

    return first;
}

void display(NODE first)
{
    if (first == NULL)
    {
        printf("Queue underflow!\n");
        return;
    }

    printf("Queue contents: ");
    NODE curr = first;
    while (curr != NULL)
    {
        printf("%d ", curr->info);
        curr = curr->link;
    }
}
