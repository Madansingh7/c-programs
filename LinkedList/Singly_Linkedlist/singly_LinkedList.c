//THIS PROGRAM IS ONLY FOR INSERT TYPES IN SINGLY LINKED LIST
// 1 - insert @ front
// 2 - insert @ rear
// 3 - insert @ a position
// 4 - insert before a element
// 5 - insert after a element

// 6 -  delete @ front
// 7 -  delete @ rear
// 8 -  delete @ a position
// 9 -  delete before a element
// 10 - delete after a element

// 11 - display
// 12 - exit

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

// insert from front
NODE insert_front(NODE first, int ele) {
    NODE temp = create_node(ele);
    temp->next = first;
    first = temp;
    printf("Inserted %d in List\n", ele);
    return first;
}

// insert from rear
NODE insert_rear(NODE first, int ele) {
    NODE temp = create_node(ele);

    if (first == NULL) {
        first = temp;
        printf("Inserted %d in List\n", ele);
        return first;
    }

    NODE curr = first;
    while (curr->next != NULL){ 
        curr = curr->next;
    }
    curr->next = temp;
    printf("Inserted %d in list\n", ele);
    return first;
}

// insert at a particular position
NODE insert_at_position(NODE first, int ele, int pos) {
    
    if (pos == 1) {
        first=insert_front(first, ele);
        return first;
    }

    NODE temp = create_node(ele);
    if (first == NULL) {
        printf("List is empty, cannot insert at position %d\n", pos);
        free(temp);
        return first;
    }

    int count = 1;
    NODE curr = first;

    while (count != pos-1 && curr != NULL) {
        curr = curr->next;
        count++;
    }

    if (curr == NULL) {
        printf("Invalid position %d (list too short)\n", pos);
        free(temp);
        return first;
    }

    temp->next = curr->next;
    curr->next = temp;
    printf("Inserted %d at position %d\n", ele, pos);
    return first;
}


// insert before a particular element 
NODE insert_before(NODE first, int ele, int key){
    if(first==NULL){
        printf("List is empty (Insert elements)\n");
        return first;
    }
    if(key == first->info){
        first=insert_front(first,ele);
        return first;
    }
    // This can be added!
    // if(key != first->info && first->next == NULL){
    //     printf("Key element not found\n");
    //     return first;
    // }

    NODE temp = create_node(ele);
    NODE prev=NULL;
    NODE curr = first;

    while( curr != NULL && curr->info != key){
        prev=curr;
        curr=curr->next;
    }
    if (curr == NULL) {
    printf("Key %d not found in list\n", key);
    free(temp);
    return first;
    }
    temp->next = curr;
    prev->next = temp;
    printf("Inserted %d in List\n",ele);
    return first;
}

// insert after a particular element
NODE insert_after(NODE first, int ele, int key){
    if(first==NULL){
        printf("List is empty (Insert elements)\n");
        return first;
    }

    NODE temp = create_node(ele);
    NODE curr = first;
    while(curr != NULL && curr->info != key){
        curr=curr->next;
    }

    if(curr == NULL){
    printf("Key %d not found in list\n", key);
    free(temp);
    return first;  
    }

    temp->next=curr->next;
    curr->next=temp;
    printf("Inserted %d after %d\n", ele, key);
    return first;
}

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
    for (NODE cur = first; cur != NULL; cur = cur->next){
        printf("%5d ", cur->info);
    }
    printf("\n");
}

int main() {
    NODE first = NULL;
    int ele, ch, pos, key;

    for (;;) {
        printf("\n");
        printf("1 - insert @ front\n2 - insert @ rear\n3 - insert @ a position\n4 - insert before a element\n5 - insert after a element\n6 - delete @ front\n7 - delete @ rear\n8 - delete @ a position\n9 - delete before a element\n10 - delete after a element\n11 - display\n12 - exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            // insert @ front
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                first=insert_front(first, ele);
                break;

            // insert @ rear 
            case 2:
                printf("Enter element: ");
                scanf("%d", &ele);
                first=insert_rear(first, ele);
                break;

            // insert at postion
            case 3:
                printf("Enter element: ");
                scanf("%d",&ele);
                printf("Enter positon: ");
                scanf("%d",&pos);
                first=insert_at_position(first, ele, pos);
                break;

            // insert before element
            case 4:
                printf("Enter element: ");
                scanf("%d",&ele);
                printf("Enter key element: ");
                scanf("%d",&key);
                first=insert_before(first, ele, key);
                break;

            case 5:
                printf("Enter element: ");
                scanf("%d",&ele);
                printf("Enter key element: ");
                scanf("%d",&key);
                first=insert_after(first, ele, key);
                break;

             case 6:
                first = delete_front(first);
                break;

            case 7:
                first = delete_rear(first);
                break;

            case 8:
                printf("Enter position: ");
                scanf("%d",&pos);
                first = delete_at_position(first, pos);
                break;

            case 9:
                printf("Enter key element: ");
                scanf("%d",&key);
                first = delete_before(first, key);
                break;

            case 10:
                printf("Enter key element: ");
                scanf("%d",&key);
                first = delete_after(first, key);
                break;
            
            case 11:
                display_list(first);
                break;
            case 12:
                while (first!=NULL) { 
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