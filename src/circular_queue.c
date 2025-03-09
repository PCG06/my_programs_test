// Program to perform operations on a circular queue using arrays

#include <stdio.h>

#define MAX 10

// Global variables for circular queue
int queue[MAX];
int front = -1, rear = -1, count = 0, n = 5;

// Function declarations
int isFull(void);
int isEmpty(void);
void enqueue(void);
void dequeue(void);
void display(void);

void main()
{
    int choice;

    do
    {
        printf("\n--- Circular Queue Operations ---\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
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

// Check if the queue is full
int isFull(void)
{
    return (count == n);
}

// Check if the queue is empty
int isEmpty(void)
{
    return (count == 0);
}

// Enqueue operation
void enqueue(void)
{
    int value;
    if (isFull())
        printf("Queue overflow! Cannot enqueue.\n");
    else
    {
        printf("Enter value to enqueue: ");
        scanf("%d", &value);
        
        if (front == -1)
            front = 0;
        
        rear = (rear + 1) % n;
        queue[rear] = value;
        count++;
        printf("Enqueued %d into the queue.\n", value);
    }
}

// Dequeue operation
void dequeue(void)
{
    int value;
    if (isEmpty())
        printf("Queue underflow! Cannot dequeue.\n");
    else
    {
        value = queue[front];
        printf("Dequeued value: %d\n", value);
        count--;
        if (isEmpty())
            front = rear = -1;  // Reset the queue when empty
        else
            front = (front + 1) % MAX;
    }
}

// Display queue contents
void display(void)
{
    int i, f1 = front;
    if (isEmpty())
        printf("Queue is empty!\n");
    else
    {
        printf("Queue contents:\n");
        for (i = 0; i < count; i++)
        {
            printf("%d ", queue[f1]);
            printf("Address: %p\n", &queue[f1]);
            f1 = (f1 + 1) % n;
        }
        printf("\n");
    }
}
