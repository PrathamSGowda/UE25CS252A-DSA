#include <stdio.h>
#include "queue.h"

int main()
{
    queue_t q;
    int key;
    int opt;
    init_queue(&q);

    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &opt);

    while(opt != 4)
    {
        switch(opt)
        {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &key);

                enqueue(&q, key);
                break;

            case 2:
                if(is_empty_queue(&q))
                {
                    printf("Queue is empty\n");
                }
                else
                {
                    printf("Dequeued: %d\n", dequeue(&q));
                }
                break;

            case 3:
                display_queue(&q);
                break;

            default:
                printf("Invalid choice\n");
        }

        printf("\nEnter your choice: ");
        scanf("%d", &opt);
    }
    return 0;
}