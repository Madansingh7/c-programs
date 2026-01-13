// Program to perform push, pop, display operations on TWO stacks using single array
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct {
    int stk[SIZE];
    int top1;
    int top2;
} stack;

/* Push into Stack 1 */
void push1(stack *s, int item) {
    if (s->top1 == s->top2 - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->stk[++(s->top1)] = item;
}

/* Push into Stack 2 */
void push2(stack *s, int item) {
    if (s->top1 == s->top2 - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->stk[--(s->top2)] = item;
}

/* Pop from Stack 1 */
int pop1(stack *s) {
    if (s->top1 == -1) {
        return 0;
    }
    return s->stk[(s->top1)--];
}

/* Pop from Stack 2 */
int pop2(stack *s) {
    if (s->top2 == SIZE) {
        return 0;
    }
    return s->stk[(s->top2)++];
}

/* Display Stack 1 */
void display1(stack *s) {
    if (s->top1 == -1) {
        printf("Stack 1 Empty\n");
        return;
    }
    printf("Contents of Stack 1:\n");
    for (int i = 0; i <= s->top1; i++) {
        printf("%d\n", s->stk[i]);
    }
}

/* Display Stack 2 */
void display2(stack *s) {
    if (s->top2 == SIZE) {
        printf("Stack 2 Empty\n");
        return;
    }
    printf("Contents of Stack 2:\n");
    for (int i = SIZE - 1; i >= s->top2; i--) {
        printf("%d\n", s->stk[i]);
    }
}

void main() {
    stack s1;
    int choice, item, popItem;

    s1.top1 = -1;
    s1.top2 = SIZE;

    for (;;) {
        printf("\n1:Push Stack1  2:Pop Stack1  3:Display Stack1");
        printf("\n4:Push Stack2  5:Pop Stack2  6:Display Stack2");
        printf("\n7:Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &item);
                push1(&s1, item);
                break;

            case 2:
                popItem = pop1(&s1);
                if (popItem == 0)
                    printf("Stack 1 Empty\n");
                else
                    printf("Popped from Stack 1: %d\n", popItem);
                break;

            case 3:
                display1(&s1);
                break;

            case 4:
                printf("Enter element: ");
                scanf("%d", &item);
                push2(&s1, item);
                break;

            case 5:
                popItem = pop2(&s1);
                if (popItem == 0)
                    printf("Stack 2 Empty\n");
                else
                    printf("Popped from Stack 2: %d\n", popItem);
                break;

            case 6:
                display2(&s1);
                break;

            default:
                exit(0);
        }
    }
}
