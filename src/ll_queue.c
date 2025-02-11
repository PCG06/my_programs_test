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
    int ch, item;

    do
    {
        printf("\n1. Insert at end\n2. Delete from beginning\n3. Display\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch)
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
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }
    while (ch < 4);
}

NODE getnode()
{
    NODE x = (NODE) malloc(sizeof(struct node));
    if (x == NULL) 
    {
        printf("\nNo free space");
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
        printf("\nEmpty list");
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
        printf("\nNo elements to be displayed");
        return;
    }

    printf("\nContents: ");
    NODE curr = first;
    while (curr != NULL)
    {
        printf("%d\t", curr->info);
        curr = curr->link;
    }
}
