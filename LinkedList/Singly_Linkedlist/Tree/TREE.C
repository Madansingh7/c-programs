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

BST delete_bst(BST root, int ele){
    BST curr = root, prev = NULL, inOs, q;

    if(root == NULL){
        printf("Tree is Empty\n");
        return NULL;
    }

    // Search with parent tracking
    while(curr != NULL){
        if(ele == curr->info)
            break;

        prev = curr;   // IMPORTANT FIX

        if(ele < curr->info)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if(curr == NULL){
        printf("Element not found\n");
        return root;
    }

    // Case 1: curr has NO right child
    if(curr->right == NULL){
        q = curr->left;
    }
    // Case 2: curr has NO left child but right exists
    else if(curr->left == NULL){
        q = curr->right;
    }
    // Case 3: Two children → inorder successor
    else {
        inOs = curr->right;
        prev = curr;

        while(inOs->left != NULL){
            prev = inOs;
            inOs = inOs->left;
        }

        // Copy inorder successor value
        curr->info = inOs->info;

        // Remove successor node from its parent
        if(prev->left == inOs)
            prev->left = inOs->right;
        else
            prev->right = inOs->right;

        free(inOs);
        return root;
    }

    // Reconnect q with parent prev
    if(prev == NULL){      // deleting root
        free(curr);
        return q;
    }

    if(curr == prev->left)
        prev->left = q;
    else
        prev->right = q;

    free(curr);
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
        printf("1 for insert\n2 for delete\n3 for display\n4 for exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                root = insert_bst(root, ele);
                break;

            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &ele);
                root = delete_bst(root, ele);
                break;

            case 3:
                display(root,0);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
