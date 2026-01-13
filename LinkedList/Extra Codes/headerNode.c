#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};
typedef struct node* NODE;

/* Header node structure */
struct header {
    int count;
    NODE next;
};
typedef struct header* HEADER;

NODE create_node(int ele) {
    NODE temp = malloc(sizeof(*temp));
    temp->info = ele;
    temp->next = NULL;
    return temp;
}

HEADER create_header() {
    HEADER h = malloc(sizeof(*h));
    h->count = 0;
    h->next = NULL;
    return h;
}

void insert_front(HEADER h, int ele) {
    NODE temp = create_node(ele);
    temp->next = h->next;
    h->next = temp;
    h->count++;
    printf("Inserted %d at front\n", ele);
}

void insert_rear(HEADER h, int ele) {
    NODE temp = create_node(ele);

    if (h->next == NULL) {
        h->next = temp;
    } else {
        NODE curr = h->next;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = temp;
    }
    h->count++;
    printf("Inserted %d at rear\n", ele);
}

void delete_front(HEADER h)
{
    if (h->count == 0) {
        printf("List empty\n");
        return;
    }

    NODE temp = h->next;
    h->next = temp->next;
    printf("Deleted %d from front\n", temp->info);

    free(temp);
    h->count--;
}


void display_list(HEADER h) {
    if (h->count == 0) {
        printf("List empty\n");
        return;
    }

    printf("List (%d nodes): ", h->count);
    NODE cur = h->next;
    while (cur != NULL) {
        printf("%5d ", cur->info);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    HEADER h = create_header();
    int ele, ch;

    for (;;) {
        printf("\n1 Insert Front\n2 Insert Rear\n3 delete front\n4 Display\n5 Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                insert_front(h, ele);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &ele);
                insert_rear(h, ele);
                break;
                
            case 3:
                delete_front(h);
                break;

            case 4:
                display_list(h);
                break;

            case 5:
               exit(0);
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
