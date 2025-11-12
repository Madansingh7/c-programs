//double ended
#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct {
    int que[N];
    int f, r;
} Que;

// Insert at rear
void insertRear(Que *q, int ele) {
    if ((q->f == 0 && q->r == N - 1) || (q->f == q->r + 1)) {
        printf("Overflow at rear\n");
        return;
    }

    if (q->f == -1) { // First element
        q->f = q->r = 0;
    } 
    else if (q->r == N - 1) {
        q->r = 0;
    } 
    else {
        q->r++;
    }

    q->que[q->r] = ele;
    printf("%d inserted at rear\n", ele);
}

// Insert at front
void insertFront(Que *q, int ele) {
    if ((q->f == 0 && q->r == N - 1) || (q->f == q->r + 1)) {
        printf("Overflow at front\n");
        return;
    }

    if (q->f == -1) { // First element
        q->f = q->r = 0;
    } 
    else if (q->f == 0) {
        q->f = N - 1;
    } 
    else {
        q->f--;
    }

    q->que[q->f] = ele;
    printf("%d inserted at front\n", ele);
}

// Delete from front
int deleteFront(Que *q) {
    if (q->f == -1) {
        printf("Underflow at front\n");
        return -1;
    }

    int ele = q->que[q->f];
    if (q->f == q->r) { // Only one element
        q->f = q->r = -1;
    } 
    else if (q->f == N - 1) {
        q->f = 0;
    } 
    else {
        q->f++;
    }

    return ele;
}

// Delete from rear
int deleteRear(Que *q) {
    if (q->r == -1) {
        printf("Underflow at rear\n");
        return -1;
    }

    int ele = q->que[q->r];
    if (q->f == q->r) { // Only one element
        q->f = q->r = -1;
    } 
    else if (q->r == 0) {
        q->r = N - 1;
    } 
    else {
        q->r--;
    }

    return ele;
}

// Display
void display(Que q) {
    if (q.f == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    int i = q.f;
    while (1) {
        printf("%d ", q.que[i]);
        if (i == q.r)
            break;
        i = (i + 1) % N;
    }
    printf("\n");
}

int main() {
    Que q;
    q.f = q.r = -1;
    int ch, ele;

    while (1) {
        printf("\n--- DOUBLE ENDED QUEUE (CIRCULAR) ---\n");
        printf("1. Insert @ Front\n");
        printf("2. Insert @ Rear\n");
        printf("3. Delete @ Front\n");
        printf("4. Delete @ Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                insertFront(&q, ele);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &ele);
                insertRear(&q, ele);
                break;

            case 3:
                ele = deleteFront(&q);
                if (ele != -1)
                    printf("%d deleted from front\n", ele);
                break;

            case 4:
                ele = deleteRear(&q);
                if (ele != -1)
                    printf("%d deleted from rear\n", ele);
                break;

            case 5:
                display(q);
                break;

            case 6:
                printf("Program terminated\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
