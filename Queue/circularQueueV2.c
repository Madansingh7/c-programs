#include<stdio.h>
#include<stdlib.h>

void enque(int *q, int *r, int ele,int *c, int N)
{
    if((*c)==N) 
    {
        printf("Over flow\n");
        return;
    }
    *r = (*r + 1) % N;
    q[*r]=ele;
    (*c)++;
}

int deque(int *q, int *f, int *c, int N)
{
    int ele;
    if((*c)==0)
    {
        return -1;
    }
    ele=q[*f];
    *f = (*f + 1) % N;
    (*c)--;
    return ele;
}

void display(int q[],int f, int r, int c,int N)
{
    if(c==0)
    {
        printf("Queue is Empty\n");
        return;
    }
    printf("Content of Queue is : ");
    for(int i= 0; i<c; i++){
        printf("%3d",q[(f + i) % N]);
    }
}

void main()
{   
    int N;
    printf("Enter size of Queue : ");
    scanf("%d",&N);

    int q1[N], f=0, r=-1;
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
            enque(q1,&r,ele,&c,N);
            break;

        case 2 :
            ele=deque(q1,&f,&c,N);
            if(ele==-1){
            printf("Queue empty\n");
            }
            else{
            printf("%d deleted from Queue\n",ele);
            }
            break;

        case 3:
            display(q1,f,r,c,N);
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
