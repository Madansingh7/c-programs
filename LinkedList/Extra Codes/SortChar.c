//There is a linked list having character info. Arrange them in ascending order. That is, sort them.
#include <stdio.h>
#include <stdlib.h>

struct node {
    char info;
    struct node *next;
};
typedef struct node* NODE;

NODE create_node(char ele) {
    NODE temp = malloc(sizeof(*temp));
    temp->info = ele;
    temp->next = NULL;
    return temp;
}

NODE insert_front(NODE first, char ele) {
    NODE temp = create_node(ele);
    temp->next = first;
    first = temp;
    printf("Inserted %c at front\n", ele);
    return first;
}

NODE insert_rear(NODE first, char ele) {
    NODE temp = create_node(ele);

    if (first == NULL) {
        first = temp;
        printf("Inserted %c as first node\n", ele);
        return first;
    }

    NODE curr = first;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    printf("Inserted %c at rear\n", ele);
    return first;
}

void display_list(NODE first) {
    if (first == NULL) {
        printf("List empty\n");
        return;
    }
    printf("List: ");
    for (NODE cur = first; cur != NULL; cur = cur->next)
        printf("%c ", cur->info);
    printf("\n");
}

void sortList(NODE first) {
    if (first == NULL) {
        printf("List is empty\n");
        return;
    }
    NODE i, j;
    char temp;
    for (i = first; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->info > j->info) {
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }
    printf("List sorted successfully.\n");
}

int main() {
    NODE first = NULL;
    char ele;
    int ch;

    for (;;) {
        printf("\n1. Insert @ front\n2. Insert @ rear\n3. Display\n4. Sort list\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf(" %c", &ele);  // space before %c to skip newline
                first = insert_front(first, ele);
                break;

            case 2:
                printf("Enter element: ");
                scanf(" %c", &ele);  // space before %c to skip newline
                first = insert_rear(first, ele);
                break;

            case 3:
                display_list(first);
                break;

            case 4:
                sortList(first);
                break;

            case 5:
                while (first != NULL) {
                    NODE t = first;
                    first = first->next;
                    free(t);
                }
                printf("List cleared successfully. Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
