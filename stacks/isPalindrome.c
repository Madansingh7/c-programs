//Write a C program to check if the string is palindrome or not using stacks
#include <stdio.h>
#include <string.h>

#define MAX 20

// Define the stack structure
struct Stack {
    char items[MAX];
    int top;
};

// Function to push an element onto the stack
void push(struct Stack *s, char ch) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = ch;
}

// Function to pop an element from the stack
char pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

// Function to check if a string is palindrome using stack
int isPalindrome(char str[]) {
    struct Stack s;
    s.top = -1;  // Initialize stack
    int i;
    
    // Push all characters of string onto the stack
    for (i = 0; i < strlen(str); i++) {
        push(&s, str[i]);
    }

    // Pop characters from stack and compare
    for (i = 0; i < strlen(str); i++) {
        if (str[i] != pop(&s)) {
            return 0;  // Not palindrome
        }
    }

    return 1;  // Palindrome
}

int main() {
    char str[MAX];
    printf("Enter the string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("String is palindrome\n");
    } else {
        printf("String is not palindrome\n");
    }

    return 0;
}
