#include <stdio.h>
#include <stdlib.h>

/* Stack node */
struct node {
    int data;
    struct node *next;
};
typedef struct node* NODE;

/* PUSH operation */
NODE push(NODE top, int ele) {
    NODE temp = (NODE)malloc(sizeof(*temp));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return top;
    }

    temp->data = ele;
    temp->next = top;
    top = temp;

    printf("Pushed %d onto stack\n", ele);
    return top;
}

/* POP operation */
NODE pop(NODE top) {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return top;
    }

    NODE temp = top;
    printf("Popped %d from stack\n", temp->data);
    top = top->next;
    free(temp);

    return top;
}

/* DISPLAY stack */
void display(NODE top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack (Top to Bottom): ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

/* MAIN */
int main() {
    NODE top = NULL;
    int ch, ele;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                top = push(top, ele);
                break;

            case 2:
                top = pop(top);
                break;

            case 3:
                display(top);
                break;

            case 4:
                printf("Program terminated\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
