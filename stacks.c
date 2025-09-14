#include<stdio.h>
#define SIZE 10

typedef struct{
    int top, stk[SIZE];
} stack;

int isFull(stack *s){
    return s->top == SIZE - 1;
}

int isEmpty(stack *s){
    return s->top == -1;
}

void push(stack *s){
    int val;
    if(isFull(s)){
        printf("Stack Overflow!\n");
        return;
    }
    printf("Enter value to push: ");
    scanf("%d", &val);
    s->stk[++s->top] = val;
    printf("%d pushed to stack.\n", val);
}

int pop(stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow!\n");
        return -1;
    }
    int val = s->stk[s->top--];
    printf("%d popped from stack.\n", val);
    return val;
}

void display(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for(int i = 0; i <= s->top; i++){
        printf("%d ", s->stk[i]);
    }
    printf("\n");
}

int main(){
    stack s1;
    s1.top = -1;
    int choice;
    while(1){
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: push(&s1); break;
            case 2: pop(&s1); break;
            case 3: display(&s1); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}