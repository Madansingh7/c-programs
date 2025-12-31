// PROGRAM TO MERGE TWO SINGLY LL AND REVERSE THE MERGED LIST
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

NODE insert_rear(NODE first, int ele) {
    NODE temp = create_node(ele);

    if (first == NULL)
        return temp;

    NODE cur = first;
    while (cur->next != NULL)
        cur = cur->next;

    cur->next = temp;
    return first;
}

void display_list(NODE first) {
    if (first == NULL) {
        printf("List empty\n");
        return;
    }
    printf("List: ");
    while (first != NULL) {
        printf("%5d ", first->info);
        first = first->next;
    }
    printf("\n");
}

/* ---- MERGE FUNCTION ---- */
NODE merge_lists(NODE first1, NODE first2) {
    if (first1 == NULL){
        return first2;
    }
    if(first2 == NULL){
        return first1;
    }

    NODE cur = first1;
    while (cur->next != NULL){
        cur = cur->next;
    }
    cur->next = first2;
    return first1;
}

/* ---- REVERSE FUNCTION ---- */
NODE reverse_list(NODE first) {
    NODE prev = NULL, curr = first, next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    NODE first1 = NULL, first2 = NULL, merged = NULL;
    int n1, n2, ele;

    printf("Enter number of nodes in List 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &ele);
        first1 = insert_rear(first1, ele);
    }

    printf("Enter number of nodes in List 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &ele);
        first2 = insert_rear(first2, ele);
    }

    first1 = merge_lists(first1, first2);
    printf("Merged List\n");
    display_list(first1);
    first1 = reverse_list(first1);
    printf("Reversed List:\n");
    display_list(first1);

    return 0;
}
