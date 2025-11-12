#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};
typedef struct node* NODE;

// Function to create a new node
NODE create_node(int ele) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory not allocated\n");
        exit(0);
    }
    temp->info = ele;
    temp->next = NULL;
    return temp;
}

// Insert at front
NODE insert_front(NODE last, int ele) {
    NODE newnode = create_node(ele);
    if (last == NULL) {
        last = newnode;
        last->next = last; // circular link
        return last;
    }
    newnode->next = last->next;
    last->next = newnode;
    return last;
}

// Insert at rear
NODE insert_rear(NODE last, int ele) {
    NODE newnode = create_node(ele);
    if (last == NULL) {
        last = newnode;
        last->next = last;
        return last;
    }
    newnode->next = last->next;
    last->next = newnode;
    last = newnode;
    return last;
}

// Delete from front
NODE delete_front(NODE last) {
    if (last == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    NODE first = last->next;
    if (first == last) { // only one node
        printf("Deleted element: %d\n", first->info);
        free(first);
        return NULL;
    }
    last->next = first->next;
    printf("Deleted element: %d\n", first->info);
    free(first);
    return last;
}

// Delete from rear
NODE delete_rear(NODE last) {
    if (last == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    NODE curr = last->next;
    if (curr == last) { // only one node
        printf("Deleted element: %d\n", curr->info);
        free(curr);
        return NULL;
    }
    while (curr->next != last)
        curr = curr->next;
    curr->next = last->next;
    printf("Deleted element: %d\n", last->info);
    free(last);
    last = curr;
    return last;
}

// Display list
void display(NODE last) {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE temp = last->next;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->info);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

// Main function
int main() {
    NODE last = NULL;
    int choice, ele;

    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                last = insert_front(last, ele);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &ele);
                last = insert_rear(last, ele);
                break;
            case 3:
                last = delete_front(last);
                break;
            case 4:
                last = delete_rear(last);
                break;
            case 5:
                display(last);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
