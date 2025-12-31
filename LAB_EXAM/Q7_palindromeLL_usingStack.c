#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char info;
    struct node *next;
};
typedef struct node* NODE;

/* Create node */
NODE create_node(char ch) {
    NODE temp = malloc(sizeof(*temp));
    temp->info = ch;
    temp->next = NULL;
    return temp;
}

/* PUSH (insert at front) */
NODE insert_front(NODE first, char ch) {
    NODE temp = create_node(ch);
    temp->next = first;
    return temp;
}

/* POP (delete from front) */
NODE delete_front(NODE first, char *ch) {
    if (first == NULL)
        return NULL;

    NODE temp = first;
    *ch = temp->info;
    first = first->next;
    free(temp);
    return first;
}

int main() {
    NODE first = NULL;
    char str[50], ch;
    int i, flag = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    /* Push all characters onto stack */
    for (i = 0; str[i] != '\0'; i++) {
        first = insert_front(first, str[i]);
    }

    /* Pop and compare */
    for (i = 0; str[i] != '\0'; i++) {
        first = delete_front(first, &ch);
        if (ch != str[i]) {
            flag = 0;
            break;
        }
    }

    if (flag)
        printf("String is Palindrome\n");
    else
        printf("String is NOT Palindrome\n");

    return 0;
}
