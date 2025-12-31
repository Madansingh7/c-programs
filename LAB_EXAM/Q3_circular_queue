#include<stdio.h>
#include<stdlib.h>
#define N 3

typedef struct
{
    int que[N];
    int f, r;
}Que;

void enque(Que *q, int ele,int *c)
{
    if((*c)==N) 
    {
        printf("Over flow\n");
        return;
    }
    q->r=(q->r+1) % N;
    (*c)++;
    q->que[(q->r)]=ele;
}

int deque(Que *q, int *c)
{
    int ele;
    if((*c)==0)
    {
        return -1;
    }
    ele=q->que[(q->f)];
    (*c)--;
    q->f=(q->f+1) % N;
    
    return ele;
}

void display(Que q, int c)
{
    if(c==0)
    {
        printf("Queue is Empty\n");
        return;
    }
    for(int i= 0; i<c; i++){
        printf("Q[%d] is %d\n",q.f,q.que[q.f]);
        q.f=(q.f+1) % N;
    }
}

void main()
{
    Que q1;
    q1.f=0;
    q1.r=-1;
    int ch,ele,c=0;

    while(1)
    {
        printf("\n");
        printf("1 for Insert\n2 for deletion\n3 for display\n4 for exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d",&ele);
            enque(&q1,ele,&c);
            break;

        case 2 :
            ele=deque(&q1,&c);
            if(ele==-1){
            printf("Queue empty\n");
            }
            else{
            printf("%d deleted from Queue\n",ele);
            }
            break;

        case 3:
            display(q1,c);
            break;

        case 4:
            printf("program Exited !!\n");
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }

    }
}
