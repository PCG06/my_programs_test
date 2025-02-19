// Program to perform preorder, postorder and inorder in a binary search tree

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *rlink;
    struct node *llink;
};

typedef struct node *NODE;

NODE getnode();
void preorder(NODE root);
void inorder(NODE root);
void postorder(NODE root);
NODE insert(NODE root, int item);

void main()
{
    NODE root = NULL;
    int choice, item;

    do
    {
        printf("\n--- Queue Operations ---\n");
        printf("1. Insert\n");
        printf("2. Preorder\n");
        printf("3. Inorder\n");
        printf("4. Postorder\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter the item: ");
                scanf("%d", &item);
                root = insert(root, item);
                break;
            case 2:
                preorder(root);
                printf("\n");
                break;
            case 3:
                inorder(root);
                printf("\n");
                break;
            case 4:
                postorder(root);
                printf("\n");
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
    return x;
}

void preorder(NODE root)
{
    if (root == NULL)
        return;
    printf("%d ", root->info);
    preorder(root->llink);
    preorder(root->rlink);
}

void inorder(NODE root)
{
    if (root == NULL)
        return;
    inorder(root->llink);
    printf("%d ", root->info);
    inorder(root->rlink);
}

void postorder(NODE root)
{
    if (root == NULL)
        return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d ", root->info);
}

NODE insert(NODE root, int item)
{
    NODE temp = getnode();
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = NULL;

    if (root == NULL)
        return temp;
    
    NODE prev = NULL, curr = root;
    while (curr != NULL)
    {
        prev = curr;
        if (item < curr->info)
            curr = curr->llink;
        else
            curr = curr->rlink;
    }
    if (item < prev->info)
        prev->llink = temp;
    else
        prev->rlink = temp;

    return root;
}