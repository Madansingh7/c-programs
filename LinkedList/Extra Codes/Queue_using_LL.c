//Program to perform enqueue, dequeue and display operations on Queue using Linked list
#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};
typedef struct node* NODE;

NODE enque(NODE rear, int ele, NODE *front)
{
    NODE newnode = (NODE)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Queue Overflow (Memory not allocated)\n");
        return rear;
    }
    newnode->info = ele;
    newnode->next = NULL;

    if(*front == NULL)   // First node being inserted
        *front = newnode;
    else
        rear->next = newnode;
    printf("%d inserted in queue\n",newnode->info);
    return newnode; // new rear
}

NODE deque(NODE front, NODE *rear, int *deleted)
{
    NODE temp;
    if(front == NULL)
    {
        printf("Queue Underflow (Queue is empty)\n");
        *deleted = -1;
        return front;
    }

    temp = front;
    *deleted = temp->info;
    front = front->next;

    if(front == NULL)   // If queue becomes empty, rear must also become NULL
        *rear = NULL;

    free(temp);
    return front;
}

void display(NODE front)
{
    if(front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Contents of queue are:\n");
    while(front != NULL)
    {
        printf("%d\n", front->info);
        front = front->next;
    }
}

void main()
{
    NODE front = NULL, rear = NULL;
    int ch, ele, deleted;

    while(1)
    {
        printf("\n1 for Insert\n2 for Deletion\n3 for Display\n4 for Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&ele);
                rear = enque(rear, ele, &front);
                break;

            case 2:
                front = deque(front, &rear, &deleted);
                if(deleted != -1)
                    printf("%d deleted from Queue\n", deleted);
                break;

            case 3:
                display(front);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
