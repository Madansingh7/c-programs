#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;              // unused for header
    int count;             // used only by header
    struct node *prev;
    struct node *next;
};

typedef struct node* NODE;

/* Create header node */
NODE create_header() {
    NODE h = malloc(sizeof(*h));
    h->count = 0;
    h->next = h;
    h->prev = h;
    return h;
}

/* Create data node */
NODE create_node(int ele) {
    NODE temp = malloc(sizeof(*temp));
    temp->info = ele;
    temp->next = temp->prev = NULL;
    return temp;
}

/* Enqueue (insert at rear) */
void enqueue(NODE h, int ele) {
    NODE temp = create_node(ele);

    temp->next = h;
    temp->prev = h->prev;
    h->prev->next = temp;
    h->prev = temp;

    h->count++;
    printf("Inserted %d\n", ele);
}

/* Dequeue (delete from front) */
void dequeue(NODE h) {
    if (h->count == 0) {
        printf("Queue Empty\n");
        return;
    }

    NODE temp = h->next;
    h->next = temp->next;
    temp->next->prev = h;

    printf("Deleted %d\n", temp->info);
    free(temp);
    h->count--;
}

/* Display queue */
void display(NODE h) {
    if (h->count == 0) {
        printf("Queue Empty\n");
        return;
    }

    NODE cur = h->next;
    printf("Queue: ");
    while (cur != h) {
        printf("%d ", cur->info);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    NODE h = create_header();
    int ch, ele;

    for (;;) {
        printf("\n1 Enqueue\n2 Dequeue\n3 Display\n4 Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                enqueue(h, ele);
                break;

            case 2:
                dequeue(h);
                break;

            case 3:
                display(h);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
