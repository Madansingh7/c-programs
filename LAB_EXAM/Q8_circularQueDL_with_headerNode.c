#include <stdio.h>
#include <stdlib.h>

/* Doubly linked list node */
struct node {
    int info;
    struct node *next;
    struct node *prev;
};
typedef struct node* NODE;

/* Header node with metadata */
struct header {
    int count;      // number of nodes
    NODE next;      // first node
    NODE prev;      // last node
};
typedef struct header* HEADER;

/* Create header node */
HEADER create_header() {
    HEADER h = (HEADER)malloc(sizeof(*h));
    h->count = 0;
    h->next = (NODE)h;   // circular link
    h->prev = (NODE)h;
    return h;
}

/* Create data node */
NODE create_node(int ele) {
    NODE temp = (NODE)malloc(sizeof(*temp));
    temp->info = ele;
    temp->next = temp->prev = NULL;
    return temp;
}

/* INSERT AT FRONT */
void insert_front(HEADER h, int ele) {
    NODE temp = create_node(ele);

    temp->next = h->next;
    temp->prev = (NODE)h;
    h->next->prev = temp;
    h->next = temp;

    h->count++;
    printf("Inserted %d at front\n", ele);
}

/* DELETE AT REAR */
void delete_rear(HEADER h) {
    if (h->count == 0) {
        printf("List empty, cannot delete\n");
        return;
    }

    NODE temp = h->prev;
    printf("Deleted %d from rear\n", temp->info);

    h->prev = temp->prev;
    temp->prev->next = (NODE)h;
    free(temp);

    h->count--;
}

/* DISPLAY LIST + HEADER COUNT */
void display(HEADER h) {
    if (h->count == 0) {
        printf("List empty\n");
        printf("Node count = %d\n", h->count);
        return;
    }

    NODE cur = h->next;
    printf("List: ");
    while (cur != (NODE)h) {
        printf("%d ", cur->info);
        cur = cur->next;
    }
    printf("\n");

    printf("Node count = %d\n", h->count);
}

/* MAIN */
int main() {
    HEADER h = create_header();
    int ch, ele;

    while (1) {
        printf("\n----- MENU -----\n");
        printf("1. Insert at Front\n");
        printf("2. Delete at Rear\n");
        printf("3. Display List & Count\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                insert_front(h, ele);
                break;

            case 2:
                delete_rear(h);
                break;

            case 3:
                display(h);
                break;

            case 4:
                printf("Program terminated\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
