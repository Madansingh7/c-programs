#include <stdio.h>
#include <stdlib.h>

struct bst {
    struct bst *left;
    int info;
    struct bst *right;
};
typedef struct bst* BST;

BST create_node(int ele) {
    BST temp = (BST)malloc(sizeof(*temp));
    temp->info = ele;
    temp->left = temp->right = NULL;
    return temp;
}

BST insert_bst(BST root, int ele) {
    if (root == NULL)
        return create_node(ele);

    if (ele < root->info)
        root->left = insert_bst(root->left, ele);
    else if (ele > root->info)
        root->right = insert_bst(root->right, ele);

    return root;
}

void inorder(BST root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

void preorder(BST root) {
    if (root) {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(BST root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}

BST search_bst(BST root, int ele) {
    while (root != NULL) {
        if (ele == root->info)
            return root;
        else if (ele < root->info)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

int max_ele(BST root) {
    while (root->right != NULL)
        root = root->right;
    return root->info;
}

int min_ele(BST root) {
    while (root->left != NULL)
        root = root->left;
    return root->info;
}

/* ---------- HEIGHT HELPER ---------- */
int get_height(BST root) {
    if (root == NULL)
        return -1;   // leaf = 0
    int lh = get_height(root->left);
    int rh = get_height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

/* ---------- COMBINED HEIGHT + LEVEL FUNCTION ---------- */
void height_and_levels(BST root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return;
    }

    int height = get_height(root);
    int levels = height + 1;

    printf("Height of tree = %d\n", height);
    printf("Levels in tree = %d\n", levels);
}

/* ----------- MAIN MENU ----------- */
int main() {
    BST root = NULL;
    int ch, ele;

    for (;;) {
        printf("\n----- MENU -----\n");
        printf("1. Insert\n");
        printf("2. Inorder\n");
        printf("3. Preorder\n");
        printf("4. Postorder\n");
        printf("5. Search\n");
        printf("6. Max\n");
        printf("7. Min\n");
        printf("8. Height + Levels\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                root = insert_bst(root, ele);
                break;

            case 2:
                inorder(root);
                printf("\n");
                break;

            case 3:
                preorder(root);
                printf("\n");
                break;

            case 4:
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Enter element to search: ");
                scanf("%d", &ele);
                if (search_bst(root, ele))
                    printf("Found\n");
                else
                    printf("Not Found\n");
                break;

            case 6:
                if (root)
                    printf("Max = %d\n", max_ele(root));
                else
                    printf("Tree empty\n");
                break;

            case 7:
                if (root)
                    printf("Min = %d\n", min_ele(root));
                else
                    printf("Tree empty\n");
                break;

            case 8:
                height_and_levels(root);
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
