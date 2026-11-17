#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void addJob()
{
    int job;

    if (rear == SIZE - 1)
    {
        printf("Printer Queue is Full\n");
    }
    else
    {
        printf("Enter Job ID: ");
        scanf("%d", &job);

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = job;

        printf("Job Added Successfully\n");
    }
}

void printJob()
{
    if (front == -1 || front > rear)
    {
        printf("No Jobs Available\n");
    }
    else
    {
        printf("Printing Job ID: %d\n", queue[front]);
        front++;
    }
}

void displayJobs()
{
    int i;

    if (front == -1 || front > rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Pending Printer Jobs:\n");

        for (i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Printer Job Management System ---\n");
        printf("1. Add Printer Job\n");
        printf("2. Print Job\n");
        printf("3. Display Jobs\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addJob();
                break;

            case 2:
                printJob();
                break;

            case 3:
                displayJobs();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid Choice\n");
        }
    }
}
