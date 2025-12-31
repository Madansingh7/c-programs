// PROGRAM TO INSERT FRONT, REAR, DISPLAY AND SWAP mth & nth ELEMENTS
#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};
typedef struct node* NODE;

NODE create_node(int ele) {
    NODE temp = malloc(sizeof(*temp));
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
    while (curr->next != NULL) {
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
    for (NODE cur = first; cur != NULL; cur = cur->next) {
        printf("%5d ", cur->info);
    }
    printf("\n");
}

/* ---- NEW FUNCTION FOR Q4 ---- */
void swap_m_n(NODE first, int m, int n) {
    NODE p = first, q = first;
    
    int i=1;
    while(i<n && p!=NULL){
        p = p->next;
        i++;
    }

    i=1;
    while(i<m && q!=NULL){
        q = q->next;
        i++;
    }
    
    if (p == NULL || q == NULL) {
        printf("Invalid positions\n");
        return;
    }

    int temp = p->info;
    p->info = q->info;
    q->info = temp;

    printf("Swapped %dth and %dth elements\n", m, n);
}

int main() {
    NODE first = NULL;
    int ele, ch, m, n;

    for (;;) {
        printf("\n1.Insert Front\n2.Insert Rear\n3.Display\n4.Swap m & n\n5.Exit\n");
        printf("Enter choice: ");
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
                printf("Enter m and n positions: ");
                scanf("%d %d", &m, &n);
                swap_m_n(first, m, n);
                break;

            case 5:
                exit(0);
                printf("List cleared successfully\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
