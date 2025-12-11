#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    int data[SIZE];
    int front;   // always 0
    int rear;    // starts at -1
} DEQUE;

// Initialize deque
void init(DEQUE *dq) {
    dq->front = 0;
    dq->rear = -1;
}

// Check empty
int isEmpty(DEQUE *dq) {
    return (dq->rear == -1);
}

// Check full
int isFull(DEQUE *dq) {
    return (dq->rear == SIZE - 1);
}

// Insert at rear
void insertRear(DEQUE *dq, int ele) {
    if (isFull(dq)) {
        printf("Deque Overflow! Cannot insert at rear.\n");
        return;
    }

    dq->rear++;
    dq->data[dq->rear] = ele;
    printf("Inserted %d at rear.\n", ele);
}

// Insert at front (shift elements right)
void insertFront(DEQUE *dq, int ele) {
    if (isFull(dq)) {
        printf("Deque Overflow! Cannot insert at front.\n");
        return;
    }

    // Shift right
    for (int i = dq->rear; i >= 0; i--) {
        dq->data[i + 1] = dq->data[i];
    }

    dq->data[0] = ele;
    dq->rear++;

    printf("Inserted %d at front.\n", ele);
}

// Delete from front (shift left)
int deleteFront(DEQUE *dq) {
    if (isEmpty(dq)) {
        printf("Deque Underflow! Cannot delete from front.\n");
        return -1;
    }

    int ele = dq->data[0];

    // Shift left
    for (int i = 0; i < dq->rear; i++) {
        dq->data[i] = dq->data[i + 1];
    }

    dq->rear--;
    return ele;
}

// Delete from rear
int deleteRear(DEQUE *dq) {
    if (isEmpty(dq)) {
        printf("Deque Underflow! Cannot delete from rear.\n");
        return -1;
    }

    int ele = dq->data[dq->rear];
    dq->rear--;
    return ele;
}

// Display deque
void display(DEQUE *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque contents: ");
    for (int i = 0; i <= dq->rear; i++) {
        printf("%d ", dq->data[i]);
    }
    printf("\n");
}

int main() {
    DEQUE dq;
    init(&dq);

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
                insertFront(&dq, ele);
                break;

            case 2:
                printf("Enter element to insert at rear: ");
                scanf("%d", &ele);
                insertRear(&dq, ele);
                break;

            case 3:
                ele = deleteFront(&dq);
                if (ele != -1)
                    printf("Deleted from front: %d\n", ele);
                break;

            case 4:
                ele = deleteRear(&dq);
                if (ele != -1)
                    printf("Deleted from rear: %d\n", ele);
                break;

            case 5:
                display(&dq);
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