#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    int que[SIZE];
    int front;   // always 0
    int rear;    // starts at -1
} DEQUE;


// Insert at rear
void insertRear(DEQUE *q, int ele) {
    if (q->rear == SIZE - 1) {
        printf("Deque Overflow! Cannot insert at rear.\n");
        return;
    }

    q->que[++(q->rear)] = ele;
    printf("Inserted %d at rear.\n", ele);
}

// Insert at front (shift elements right)
void insertFront(DEQUE *q, int ele) {
    if (q->rear == SIZE - 1) {
        printf("Deque Overflow! Cannot insert at front.\n");
        return;
    }

    // Shift right
    for (int i = q->rear; i >= 0; i--) {
        q->que[i + 1] = q->que[i];
    }

    q->que[0] = ele;
    q->rear++;

    printf("Inserted %d at front.\n", ele);
}

// Delete from front (shift left)
int deleteFront(DEQUE *q) {
    if(q->rear == -1) {
        printf("Deque Underflow! Cannot delete from front.\n");
        return -1;
    }

    int ele = q->que[0];

    // Shift left
    for (int i = 0; i < q->rear; i++) {
        q->que[i] = q->que[i + 1];
    }

    q->rear--;
    return ele;
}

// Delete from rear
int deleteRear(DEQUE *q) {
    if(q->rear == -1) {
        printf("Deque Underflow! Cannot delete from rear.\n");
        return -1;
    }

    int ele = q->que[q->rear];
    q->rear--;
    return ele;
}

// Display deque
void display(DEQUE q) {
    if (q.rear == SIZE - 1) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque contents: ");
    for (int i = 0; i <= q.rear; i++) {
        printf("%d ", q.que[i]);
    }
    printf("\n");
}

int main() {
    DEQUE q;
    q.front = 0;
    q.rear = -1;

    int choice, ele;

    while (1) {
        printf("\n--- DEQUE MENU ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at front: ");
                scanf("%d", &ele);
                insertFront(&q, ele);
                break;

            case 2:
                printf("Enter element to insert at rear: ");
                scanf("%d", &ele);
                insertRear(&q, ele);
                break;

            case 3:
                ele = deleteFront(&q);
                if (ele != -1)
                    printf("Deleted from front: %d\n", ele);
                break;

            case 4:
                ele = deleteRear(&q);
                if (ele != -1)
                    printf("Deleted from rear: %d\n", ele);
                break;

            case 5:
                display(q);
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
