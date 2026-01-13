#include <stdio.h>
#include <stdlib.h>
#define N 3

typedef struct {
    int que[N];
    int f, r;
} Que;

// Priority enqueue (ascending order)
void enque(Que *q, int ele, int *c)
{
    if (*c == N) {
        printf("Overflow\n");
        return;
    }

    int j = q->r;

    // Shift elements to maintain ascending order
    while (j >= q->f && q->que[j] > ele) {
        q->que[j + 1] = q->que[j];
        j--;
    }

    q->que[j + 1] = ele;
    q->r++;
    (*c)++;
}

// Dequeue (always from front)
int deque(Que *q, int *c)
{
    if (*c == 0)
        return -1;

    int ele = q->que[q->f];
    q->f++;
    (*c)--;
    return ele;
}

void display(Que q, int c)
{
    if (c == 0) {
        printf("Queue is Empty\n");
        return;
    }

    for (int i = q.f; i <= q.r; i++)
        printf("%d ", q.que[i]);
    printf("\n");
}

int main()
{
    Que q1;
    q1.f = 0;
    q1.r = -1;

    int ch, ele, c = 0;

    while (1) {
        printf("\n1 Insert\n2 Delete\n3 Display\n4 Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Enter element (time): ");
            scanf("%d", &ele);
            enque(&q1, ele, &c);
            break;

        case 2:
            ele = deque(&q1, &c);
            if (ele == -1)
                printf("Queue Empty\n");
            else
                printf("%d deleted\n", ele);
            break;

        case 3:
            display(q1, c);
            break;

        case 4:
            exit(0);
        }
    }
}
