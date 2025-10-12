//Write a C program to covert infix to postix using stack as the data structure
#include <stdio.h>
#include<ctype.h>
#define N 20
typedef struct {
    int stk[N];
    int top;
}S;

void push(S *s, int ele){
    if(s->top == N-1){
        printf("Overflow\n");
        return;
    }
    s->stk[++(s->top)]=ele;
}

int pop(S *s){
     if(s->top == -1){
        printf("Underflow\n");
        return -1;
        }
    return s->stk[(s->top)--];
}

int precedence(char op)
{
    switch(op)
    {
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': 
        case '%': return 3;
        case '^':
        case '$': return 4;
    }
}

int main() {
    S s1;
    s1.top=-1;
    char infix[N], postfix[N], ch, c;
    int i = 0, j = 0;
    printf("Enter a valid infix expression: ");
    scanf("%s", infix);
    while(infix[i] != '\0'){
        ch=infix[i++];
        if(ch=='('){
            push(&s1,ch);
        }
        else if(isalnum(ch)){
            postfix[j++]=ch;
        }
        else if (ch==')'){
            while((c=pop(&s1))!='('){
                postfix[j++]=c;
            }
        }
        else{
            while(precedence(ch)<=precedence(s1.stk[s1.top]) && s1.top != -1){
                postfix[j++]=pop(&s1);
            }
            push(&s1,ch);
        }
    }
    while(s1.top != -1)
    {
        postfix[j++] = pop(&s1);
    }
    postfix[j] = '\0';
    printf("Postfix of infix expression is %s = %s\n", infix, postfix);

    return 0;
}
