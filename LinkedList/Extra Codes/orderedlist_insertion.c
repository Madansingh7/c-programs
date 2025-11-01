// inserting elements in accesnding order in list
#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};
typedef struct node* NODE;

// creating node 
NODE create_node(int ele) {
    NODE temp = malloc(sizeof (*temp));
    temp->info = ele;
    temp->next = NULL;
    return temp;
}

// insert in accesending order
NODE insert(NODE first, int ele) { 
    NODE temp = create_node(ele);
    if(first==NULL || ele <=first->info){
        temp->next = first;
        first = temp;
        printf("Inserted %d at List\n", ele);
        return first;
    }
   
    NODE curr=first;
    NODE prev=NULL;
    while(curr!=NULL && curr->info < ele){
        prev=curr;
        curr=curr->next;
    }
    prev->next = temp;
    temp->next = curr;
    printf("Inserted %d in List\n", ele);
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
        printf("\n");
        printf("1 - insert\n2 - display\n3 - exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                first=insert(first, ele);
                break;

            case 2:
                display_list(first);
                break;

            case 3:
                while (first!=NULL) { 
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
    return 0;

}
