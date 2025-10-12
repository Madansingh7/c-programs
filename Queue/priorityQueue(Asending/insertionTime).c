#include<stdio.h>
#include<stdlib.h>
#define N 5

typedef struct
{
    int que[N];
    int f, r;
}Que;

void enque(Que *q, int ele)
{
    if(q->r == N-1)
    {
        printf("Overflow!\n");
        return;
    }
    int j=q->r;
    while(j>=0 && ele<=q->que[j])
    {
        q->que[j+1]=q->que[j];
        j--;
    }
    q->r++;
    q->que[++(j)]=ele;
}

int deque(Que *q)
{
    if(q->f > q->r)
    {
        printf("under flow : Queue is empty\n");
        return -1;
    }
    return q->que[(q->f)++];
}

void display(Que q){
    if(q.f > q.r){
        printf("Queue is Empty\n");
        return;
    }
    for(int i= q.f; i<=q.r; i++){
        printf("Q[%d] is %d\n",i,q.que[i]);
    }
}

void main()
{
    Que q1;
    q1.f=0;
    q1.r=-1;
    int ch,ele;

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
            enque(&q1,ele);
            break;

        case 2 :
            ele=deque(&q1);
            if(ele==-1)
            {
                break;
            }
            printf("%d deleted from Queue\n",ele);
            break;

        case 3:
            display(q1);
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("Invalid choice\n");
            break;
        }

    }
}
