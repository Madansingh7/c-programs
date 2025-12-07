//Write a C program to check whether a given expression is balanced expression or not
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 30

typedef struct {
    char stk[N];
    int top;
}stack;

void push(stack *s, char ele)
{
    if(s->top == (N - 1))
    {
        printf("Stack overflow\n");
        return;
    }
    s->stk[++(s->top)] = ele;
}

char pop(stack * s)
{
    if(s->top == -1)
    {
        printf("Stack underflow\n");
        exit(0);
    }
    return (s->stk[(s->top)--]);
}

int match(char a, char b)
{
    if(a == '[' && b == ']')
        return 1;
    if(a == '{' && b == '}')
        return 1;
    if(a == '(' && b == ')')
        return 1;
    return 0;
}

int check(stack *s, char exp[])
{
    char ele;
    for(int i = 0; i < strlen(exp); i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(s,exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(s->top == -1)
            {
                printf("Right parenthesis are more than left parenthesis\n");
                return 0;
            }
            else
            {
                ele = pop(s);
                if(!match(ele, exp[i]))
                {
                    printf("Mismatched parenthesized expression\n");
                    printf("%c and %c\n", ele, exp[i]);
                    return 0;
                }
            }
        }
    }
    if(s->top == -1)
    {
        printf("Balanced parenthesis\n");
        return 1;
    }
    else
    {
        printf("Left parenthesis are more than right parenthesis\n");
        return 0;
    }
}

int main()
{
    stack s1;
    s1.top = -1;
    char exp[N];
    int valid;
    printf("Enter an expression: ");
    scanf("%s", exp);
    valid = check(&s1,exp);
    if(valid == 1)
    {
        printf("Valid/balanced expression\n");
    }
    else
    {
        printf("Invalid/unbalanced expression\n");
    }
    return 0;
}
