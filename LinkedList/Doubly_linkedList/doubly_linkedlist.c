// PROGRAM FOR INSERTION & DELETION OPERATIONS IN DOUBLY LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
    struct node *prev;
};
typedef struct node* NODE;

// Create node
NODE create_node(int ele) {
    NODE temp = (NODE)malloc(sizeof(*temp));
    temp->info = ele;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

// Insert @ front
NODE insert_front(NODE first, int ele) {
    NODE temp = create_node(ele);
    if (first == NULL)
        first = temp;
    else {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
    printf("Inserted %d at front\n", ele);
    return first;
}

// Insert @ rear
NODE insert_rear(NODE first, int ele) {
    NODE temp = create_node(ele);
    if (first == NULL) {
        first = temp;
        printf("Inserted %d at rear\n", ele);
        return first;
    }
    NODE curr = first;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
    temp->prev = curr;
    printf("Inserted %d at rear\n", ele);
    return first;
}

// Insert @ position
NODE insert_at_position(NODE first, int ele, int pos) {
    if (pos == 1)
        return insert_front(first, ele);

    if (first == NULL) {
        printf("List empty, cannot insert at position %d\n", pos);
        return first;
    }

    NODE curr = first;
    int count = 1;
    while (curr != NULL && count < pos - 1) {
        curr = curr->next;
        count++;
    }

    if (curr == NULL) {
        printf("Invalid position %d\n", pos);
        return first;
    }

    NODE temp = create_node(ele);
    temp->next = curr->next;
    temp->prev = curr;

    if (curr->next != NULL)
        curr->next->prev = temp;
    curr->next = temp;

    printf("Inserted %d at position %d\n", ele, pos);
    return first;
}

// Insert before element
NODE insert_before(NODE first, int ele, int key) {
    if (first == NULL) {
        printf("List empty\n");
        return first;
    }

    NODE curr = first;
    while (curr != NULL && curr->info != key)
        curr = curr->next;

    if (curr == NULL) {
        printf("Key %d not found\n", key);
        return first;
    }

    NODE temp = create_node(ele);
    temp->next = curr;
    temp->prev = curr->prev;

    if (curr->prev != NULL)
        curr->prev->next = temp;
    else
        first = temp;

    curr->prev = temp;
    printf("Inserted %d before %d\n", ele, key);
    return first;
}

// Insert after element
NODE insert_after(NODE first, int ele, int key) {
    if (first == NULL) {
        printf("List empty\n");
        return first;
    }

    NODE curr = first;
    while (curr != NULL && curr->info != key)
        curr = curr->next;

    if (curr == NULL) {
        printf("Key %d not found\n", key);
        return first;
    }

    NODE temp = create_node(ele);
    temp->next = curr->next;
    temp->prev = curr;

    if (curr->next != NULL)
        curr->next->prev = temp;
    curr->next = temp;

    printf("Inserted %d after %d\n", ele, key);
    return first;
}

// Delete @ front
NODE delete_front(NODE first) {
    if (first == NULL) {
        printf("List empty\n");
        return first;
    }
    NODE temp = first;
    printf("Deleted %d from front\n", temp->info);
    first = first->next;
    if (first != NULL)
        first->prev = NULL;
    free(temp);
    return first;
}

// Delete @ rear
NODE delete_rear(NODE first) {
    if (first == NULL) {
        printf("List empty\n");
        return first;
    }
    if (first->next == NULL) {
        printf("Deleted %d from rear\n", first->info);
        free(first);
        return NULL;
    }
    NODE curr = first;
    while (curr->next != NULL)
        curr = curr->next;
    printf("Deleted %d from rear\n", curr->info);
    curr->prev->next = NULL;
    free(curr);
    return first;
}

// Delete @ position
NODE delete_at_position(NODE first, int pos) {
    if (first == NULL) {
        printf("List empty\n");
        return first;
    }
    if (pos == 1)
        return delete_front(first);

    NODE curr = first;
    int count = 1;
    while (curr != NULL && count < pos) {
        curr = curr->next;
        count++;
    }

    if (curr == NULL) {
        printf("Invalid position %d\n", pos);
        return first;
    }

    printf("Deleted %d from position %d\n", curr->info, pos);
    if (curr->next != NULL)
        curr->next->prev = curr->prev;
    if (curr->prev != NULL)
        curr->prev->next = curr->next;
    free(curr);
    return first;
}

// Delete before element
NODE delete_before(NODE first, int key) {
    if (first == NULL || first->next == NULL) {
        printf("Not enough elements\n");
        return first;
    }

    NODE curr = first;
    while (curr != NULL && curr->info != key)
        curr = curr->next;

    if (curr == NULL || curr->prev == NULL) {
        printf("No element before %d\n", key);
        return first;
    }

    NODE temp = curr->prev;
    if (temp->prev != NULL)
        temp->prev->next = curr;
    else
        first = curr;
    curr->prev = temp->prev;

    printf("Deleted %d (before %d)\n", temp->info, key);
    free(temp);
    return first;
}

// Delete after element
NODE delete_after(NODE first, int key) {
    if (first == NULL) {
        printf("List empty\n");
        return first;
    }

    NODE curr = first;
    while (curr != NULL && curr->info != key)
        curr = curr->next;

    if (curr == NULL || curr->next == NULL) {
        printf("No element after %d\n", key);
        return first;
    }

    NODE temp = curr->next;
    curr->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = curr;
    printf("Deleted %d (after %d)\n", temp->info, key);
    free(temp);
    return first;
}

// Display
void display_list(NODE first) {
    if (first == NULL) {
        printf("List empty\n");
        return;
    }
    printf("List (Forward): ");
    NODE curr = first;
    while (curr != NULL) {
        printf("%5d ", curr->info);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    NODE first = NULL;
    int ele, ch, pos, key;

    for (;;) {
        printf("\n1 - insert @ front\n2 - insert @ rear\n3 - insert @ position\n4 - insert before element\n5 - insert after element\n6 - delete @ front\n7 - delete @ rear\n8 - delete @ position\n9 - delete before element\n10 - delete after element\n11 - display\n12 - exit\n");
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
                printf("Enter element: ");
                scanf("%d", &ele);
                printf("Enter position: ");
                scanf("%d", &pos);
                first = insert_at_position(first, ele, pos);
                break;
            case 4:
                printf("Enter element: ");
                scanf("%d", &ele);
                printf("Enter key: ");
                scanf("%d", &key);
                first = insert_before(first, ele, key);
                break;
            case 5:
                printf("Enter element: ");
                scanf("%d", &ele);
                printf("Enter key: ");
                scanf("%d", &key);
                first = insert_after(first, ele, key);
                break;
            case 6:
                first = delete_front(first);
                break;
            case 7:
                first = delete_rear(first);
                break;
            case 8:
                printf("Enter position: ");
                scanf("%d", &pos);
                first = delete_at_position(first, pos);
                break;
            case 9:
                printf("Enter key: ");
                scanf("%d", &key);
                first = delete_before(first, key);
                break;
            case 10:
                printf("Enter key: ");
                scanf("%d", &key);
                first = delete_after(first, key);
                break;
            case 11:
                display_list(first);
                break;
            case 12:
                while (first != NULL) {
                    NODE t = first;
                    first = first->next;
                    free(t);
                }
                printf("List cleared\nProgram terminated\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
