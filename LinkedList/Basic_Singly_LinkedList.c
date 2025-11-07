//THIS PROGRAM IS ONLY FOR INSERT FROM FRONT AND REAR / DISPLAY
#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};
typedef struct node* NODE;

NODE create_node(int ele) {
    NODE temp = malloc(sizeof (*temp));
    temp->info = ele;
    temp->next = NULL;
    return temp;
}

NODE insert_front(NODE first, int ele) {
    NODE temp = create_node(ele);
    temp->next = first;
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
    while (curr->next != NULL){ 
        curr = curr->next;
    }
    curr->next = temp;
    printf("Inserted %d at rear\n", ele);
    return first;
}

void display_list(NODE first) {
    if (first == NULL) {
        printf("List empty\n");
        return;
    }
    printf("List: ");
    for (NODE cur = first; cur != NULL; cur = cur->next){
        printf("%5d ", cur->info);
    }
    printf("\n");
}

int main() {
    NODE first = NULL;
    int ele, ch;

    for (;;) {
        printf("1 for insert @ front\n2 for insert @ rear\n3 for display\n4 for exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                first=insert_front(first, ele);
                break;

            case 2:
                printf("Enter ele: ");
                scanf("%d", &ele);
                first=insert_rear(first, ele);
                break;

            case 3:
                display_list(first);
                break;

            case 4:
                while (first!=NULL) { 
                    NODE t = first; 
                    first = first->next; 
                    free(t); 
                    printf("List cleared successfully\n");
                }
                return 0;

            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
