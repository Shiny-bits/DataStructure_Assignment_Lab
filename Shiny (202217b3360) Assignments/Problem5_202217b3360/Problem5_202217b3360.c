#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int main()
{
    int queue[SIZE], choice = 1, front = 0, rear = 0, i, itemCount = 1;

    printf("Queue using Array");
    printf("\n1. Insertion \n2. Deletion \n3. Display \n4. Exit");

    while (choice)
    {
        printf("\nEnter your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (rear == SIZE)
                    printf("\nQueue is Full");
                else
                {
                    printf("\nEnter number %d: ", itemCount++);
                    scanf("%d", &queue[rear++]);
                }
                break;

            case 2:
                if (front == rear)
                    printf("\nQueue is empty");
                else
                {
                    printf("\nDeleted Element is %d", queue[front++]);
                }
                break;

            case 3:
                printf("\nQueue Elements are:\n");
                if (front == rear)
                    printf("\nQueue is Empty");
                else
                {
                    for (i = front; i < rear; i++)
                    {
                        printf("%d ", queue[i]);
                    }
                }
                printf("\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid Choice: Please select from the options");
        }
    }

    return 0;
}
