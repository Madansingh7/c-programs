//Program to perform push, pop, display operations on stack
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct {
    int stk[SIZE];
    int top;
}stack;
void push(stack *s, int item)
{
    if(s->top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    s->stk[++(s->top)] = item;
}

int pop(stack *s)
{
    if(s->top == -1)
    {
        return 0;
    }

return s->stk[(s->top)--];
}

void display(stack *s)
{
    int i;
    if(s->top == -1)
    {
        printf("Stack Underflow or Stack Empty\n");
        return;
    }
    printf("Contents of stack are: \n");
    for(int i = 0; i <= s->top; i++)
    {
        printf("%d\n", s->stk[i]);
    }
}

void main()
{
    stack s1;
    s1.top=-1;
    int item, choice, popItem;
    for(;;)
    {
        printf("\n1:Push\t2:Pop\t3:display\t4:exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &item);
                push(&s1,item);
                break;
            case 2:
                popItem = pop(&s1);
                if(popItem == 0)
                {
                    printf("Stack empty\n");
                }
                else
                {
                    printf("Item popped or deleted is %d\n", popItem);
                }
                break;
            case 3:
                display(&s1);
                break;
            default:
                exit(0);
        }
    }
}
