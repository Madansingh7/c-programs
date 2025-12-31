#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct et {
    char info;
    struct et *left, *right;
};
typedef struct et* ET;

/* stack */
ET stack[50];
int top = -1;

/* push */
void push(ET x) {
    stack[++top] = x;
}

/* pop */
ET pop() {
    return stack[top--];
}

/* create node */
ET create_node(char ch) {
    ET temp = (ET)malloc(sizeof(*temp));
    temp->info = ch;
    temp->left = temp->right = NULL;
    return temp;
}

/* build expression tree */
ET build_tree(char postfix[]) {
    int i;
    ET op1, op2, temp;

    for (i = 0; postfix[i] != '\0'; i++) {

        /* operand */
        if (isalnum(postfix[i])) {
            temp = create_node(postfix[i]);
            push(temp);
        }
        /* operator */
        else {
            temp = create_node(postfix[i]);
            op2 = pop();
            op1 = pop();

            temp->left = op1;
            temp->right = op2;

            push(temp);
        }
    }
    return pop();   // root
}

/* inorder traversal */
void inorder(ET root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->info);
        inorder(root->right);
    }
}

int main() {
    char postfix[50];
    ET root;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    root = build_tree(postfix);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    return 0;
}