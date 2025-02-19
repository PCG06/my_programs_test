// Program to perform queue operations using arrays

#include <stdio.h>

#define MAX 100

// Global variables for queue
int queue[MAX];
int front = -1, rear = -1;

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
    return rear == MAX - 1;
}

// Check if the queue is empty
int isEmpty(void)
{
    return front == -1 || front > rear;
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
        {
            front = 0;
        }
        queue[++rear] = value;
        printf("Enqueued %d into the queue.\n", value);
    }
}

// Dequeue operation
void dequeue(void)
{
    if (isEmpty())
        printf("Queue underflow! Cannot dequeue.\n");
    else
    {
        printf("Dequeued value: %d\n", queue[front++]);
        if (front > rear)
        {
            front = rear = -1;  // Reset the queue when it's empty
        }
    }
}

// Display queue contents
void display(void)
{
    int i;
    if (isEmpty())
        printf("Queue underflow!\n");
    else
    {
        printf("Queue contents: ");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
