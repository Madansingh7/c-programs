#include <stdio.h>
#include <stdlib.h>

struct bst {
    struct bst *left;
    int info;
    struct bst *right;
};
typedef struct bst* BST;

BST create_node(int ele) {
    BST temp = (BST)malloc(sizeof (*temp));
    temp->info = ele;
    temp->left = temp->right = NULL;
    return temp;
}

BST insert_bst(BST root, int ele) {
    if(root == NULL){
        return create_node(ele);
    }
    if(ele <= root->info){
        root->left = insert_bst(root->left,ele);
    }
    else{
        root->right = insert_bst(root->right,ele);
    }
    return root;
}

void display(BST root, int lvl) {
    if(root == NULL) return;
        
    display(root->right,lvl+1);
    for(int i=0; i<lvl; i++){
        printf("    ");
    }
    printf("%d\n",root->info);
    display(root->left,lvl+1);
}

int main() {
    BST root = NULL;
    int ele, ch;

    for (;;) {
        printf("1 for insert\n2 for display\n3 for exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                root=insert_bst(root, ele);
                break;

            case 2:
                display(root,0);
                break;

            case 3:
                exit(0);
                break;
                
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
