//THIS PROGRAM IS ONLY FOR INSERT FROM FRONT AND REAR / DISPLAY / SEARCH (Doubly LL)
#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
    struct node *prev;
};
typedef struct node* NODE;

NODE create_node(int ele) {
    NODE temp = malloc(sizeof (*temp));
    temp->info = ele;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

NODE insert_front(NODE first, int ele) {
    NODE temp = create_node(ele);

    if (first != NULL) {
        temp->next = first;
        first->prev = temp;
    }
    first = temp;
    printf("Inserted %d at front\n", ele);
    return first;
}

NODE insert_rear(NODE first, int ele) {
    NODE temp = create_node(ele);

    if (first == NULL) {
        first = temp;
        printf("Inserted %d as first node\n", ele);
        return first;
    }

    NODE curr = first;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = temp;
    temp->prev = curr;
    printf("Inserted %d at rear\n", ele);
    return first;
}

void display_list(NODE first) {
    if (first == NULL) {
        printf("List empty\n");
        return;
    }
    printf("List: ");
    for (NODE cur = first; cur != NULL; cur = cur->next) {
        printf("%5d ", cur->info);
    }
    printf("\n");
}

void search_list(NODE first, int key) {
    if (first == NULL) {
        printf("List empty\n");
        return;
    }

    NODE cur = first;
    int pos = 1;

    while (cur != NULL) {
        if (cur->info == key) {
            printf("%d found at position %d\n", key, pos);
            return;
        }
        cur = cur->next;
        pos++;
    }

    printf("%d not found in the list\n", key);
}

int main() {
    NODE first = NULL;
    int ele, ch;

    for (;;) {
        printf("\n1 for insert @ front\n2 for insert @ rear\n3 for display\n4 for search\n5 for exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                first = insert_front(first, ele);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &ele);
                first = insert_rear(first, ele);
                break;

            case 3:
                display_list(first);
                break;

            case 4:
                printf("Enter element to search: ");
                scanf("%d", &ele);
                search_list(first, ele);
                break;

            case 5:
                while (first != NULL) {
                    NODE t = first;
                    first = first->next;
                    free(t);
                }
                printf("List cleared successfully\n");
                return 0;

            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
