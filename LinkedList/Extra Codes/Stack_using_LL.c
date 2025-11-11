//Program to perform push, pop, display operations on stack using linked list
#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};
typedef struct node* NODE;

NODE push(NODE top, int ele)
{
    NODE newnode = (NODE)malloc(sizeof(*newnode));
    if(newnode == NULL)
    {
        printf("Stack empty | Memory not allocated\n");
        return NULL;
    }
    newnode->info = ele;
    newnode->next = top;
    printf("%d pushed into the stack\n",ele);
    return newnode;
}

NODE pop(NODE top)
{
    int ele;
    if(top == NULL)
    {
        printf("Stack empty\n");
        return NULL;   // stack empty
    }
    NODE curr=top;
    top=top->next;
    printf("%d poped from stack",curr->info);
    free(curr);
    return top;
}

void display(NODE top)
{
    if(top == NULL)
    {
        printf("Stack Underflow or Stack Empty\n");
        return;
    }
    printf("Contents of stack are:\n");
    while(top != NULL)
    {
        printf("%d\n", top->info);
        top = top->next;
    }
}

void main()
{
    NODE top = NULL;
    int choice, ele;

    for(;;)
    {
        printf("\n1:Push\t2:Pop\t3:Display\t4:Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &ele);
                top=push(top, ele);
                break;

            case 2:
                top = pop(top);
                break;

            case 3:
                display(top);
                break;

            default:
                exit(0);
        }
    }
}
