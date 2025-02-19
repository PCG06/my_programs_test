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
    NODE first = NULL;
    int choice, item;

    do
    {
        printf("\n--- Queue Operations ---\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display Queue\n");
        printf("0. Exit\n");
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

NODE del_beg(NODE first)
{
    if (first == NULL)
    {
        printf("Queue underflow! Cannot dequeue.\n");
        return NULL;
    }

    printf("\nDeleted element is %d", first->info);
    NODE temp = first;
    first = first->link;
    free(temp);

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
