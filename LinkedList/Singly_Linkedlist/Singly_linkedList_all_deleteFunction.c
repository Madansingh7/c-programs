#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};
typedef struct node* NODE;

// delete from front
NODE delete_front(NODE first) {
    if(first == NULL) {
        printf("List empty, cannot delete\n");
        return first;
    }
    NODE temp = first;
    printf("Deleted %d from front\n", temp->info);
    first = first->next;
    free(temp);
    return first;
}

// delete from rear
NODE delete_rear(NODE first) {
    if(first == NULL) {
        printf("List empty, cannot delete\n");
        return first;
    }
    if(first->next == NULL) {
        printf("Deleted %d from rear\n", first->info);
        free(first);
        return NULL;
    }

    NODE prev = NULL, curr = first;
    while(curr->next != NULL) {
        prev = curr;
        curr = curr->next;
    }
    printf("Deleted %d from rear\n", curr->info);
    free(curr);
    prev->next = NULL;
    return first;
}

// delete at a position
NODE delete_at_position(NODE first, int pos) {
    if(first == NULL) {
        printf("List empty, cannot delete\n");
        return first;
    }

    if(pos == 1) {
        return delete_front(first);
    }

    NODE prev = NULL, curr = first;
    int count = 1;
    while(count != pos && curr != NULL) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if(curr == NULL) {
        printf("Invalid position %d\n", pos);
        return first;
    }

    prev->next = curr->next;
    printf("Deleted %d from position %d\n", curr->info, pos);
    free(curr);
    return first;
}

// delete before a particular element
NODE delete_before(NODE first, int key) {
    if(first == NULL || first->next == NULL) {
        printf("Not enough elements\n");
        return first;
    }

    if(first->next->info == key) {
        return delete_front(first);
    }

    NODE prev = NULL, curr = first, next = first->next;

    while(next != NULL && next->info != key) {
        prev = curr;
        curr = next;
        next = next->next;
    }

    if(next == NULL) {
        printf("Key %d not found\n", key);
        return first;
    }

    prev->next = curr->next;
    printf("Deleted %d (before %d)\n", curr->info, key);
    free(curr);
    return first;
}

// delete after a particular element
NODE delete_after(NODE first, int key) {
    if(first == NULL) {
        printf("List empty\n");
        return first;
    }

    NODE curr = first;
    while(curr != NULL && curr->info != key) {
        curr = curr->next;
    }

    if(curr == NULL) {
        printf("Key %d not found\n", key);
        return first;
    }

    if(curr->next == NULL) {
        printf("No element exists after %d\n", key);
        return first;
    }

    NODE temp = curr->next;
    curr->next = temp->next;
    printf("Deleted %d (after %d)\n", temp->info, key);
    free(temp);
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

int main() {
    NODE first = NULL;
    int ch, pos, key;

    for (;;) {
        printf("\n");
        printf("1 - delete @ front\n2 - delete @ rear\n3 - delete @ a position\n4 - delete before a element\n5 - delete after a element\n6 - display\n7 - exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                first = delete_front(first);
                break;

            case 2:
                first = delete_rear(first);
                break;

            case 3:
                printf("Enter position: ");
                scanf("%d",&pos);
                first = delete_at_position(first, pos);
                break;

            case 4:
                printf("Enter key element: ");
                scanf("%d",&key);
                first = delete_before(first, key);
                break;

            case 5:
                printf("Enter key element: ");
                scanf("%d",&key);
                first = delete_after(first, key);
                break;

            case 6:
                display_list(first);
                break;

            case 7:
                while(first != NULL) {
                    NODE t = first;
                    first = first->next;
                    free(t);
                }
                printf("List cleared successfully\nProgram closed\n");
                return 0;

            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
