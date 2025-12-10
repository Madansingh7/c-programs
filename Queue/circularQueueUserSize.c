//implemented Circular Queue but it is user input size of queue
#include<stdio.h>
#include<stdlib.h>

void enque(int q[], int ele,int *c, int N, int *f, int *r)
{
    if((*c)==N) 
    {
        printf("Over flow\n");
        return;
    }
    *r=(*r+1) % N;
    (*c)++;
    q[*r]=ele;
}

int deque(int q[], int *c, int N, int *f, int *r)
{
    int ele;
    if((*c)==0)
    {
        return -1;
    }
    ele=q[*f];
    (*c)--;
    *f=(*f+1) % N;
    
    return ele;
}

void display(int q[], int c, int N, int f, int r)
{
    if(c==0)
    {
        printf("Queue is Empty\n");
        return;
    }
    for(int i= 0; i<c; i++){
        printf("Q[%d] is %d\n",f,q[f]);
        f=(f+1) % N;
    }
}

void main()
{
    int f=0, r=-1, c=0;
    int ch,ele, N;

    printf("Enter Queue size: ");
    scanf("%d",&N);
    
    int q[N];
    
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
            enque(q,ele,&c,N,&f,&r);
            break;

        case 2 :
            ele=deque(q,&c,N,&f,&r);
            if(ele==-1){
            printf("Queue empty\n");
            }
            else{
            printf("%d deleted from Queue\n",ele);
            }
            break;

        case 3:
            display(q,c,N,f,r);
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
