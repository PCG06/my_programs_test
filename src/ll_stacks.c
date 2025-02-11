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

int main()   
{   
    int choice;    

    printf("\nChoose one from the below options...\n");   
    printf("\n1. Push\n2. Pop\n3. Show\n4. Exit");   

    do
    {   
        printf("\nEnter your choice: ");         
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
            case 4:    
                printf("Exiting....\n");   
                break;    
            default:   
                printf("Please enter a valid choice\n");   
        }   
    } while (choice != 4);  

    return 0;
}   

void push()   
{   
    int val;   
    struct node *ptr;    

    ptr = (struct node *) malloc(sizeof(struct node));    
    if (ptr == NULL)   
    {   
        printf("Not able to push the element\n");    
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
        printf("Underflow\n");   
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
        printf("Stack is empty\n");   
        return;
    }   
    
    printf("Printing Stack elements:\n");   
    ptr = top;   
    while (ptr != NULL)   
    {   
        printf("%d ", ptr->val);   
        ptr = ptr->next;   
    }   
    printf("\n");
}
