/* EX.NO: 6  IMPLEMENTATION OF AVL TREE
   AIM: To write a C program to implement AVL Tree insertion with balancing rotations. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data, height;
    struct Node *left, *right;
};

int max(int a, int b) { return (a > b) ? a : b; }

int height(struct Node *n) {
    return n == NULL ? 0 : n->height;
}

int getBalance(struct Node *n) {
    return n == NULL ? 0 : height(n->left) - height(n->right);
}

struct Node *newNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

struct Node *insert(struct Node *node, int data) {
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node; /* duplicates not allowed */

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    /* Left Left */
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    /* Right Right */
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    /* Left Right */
    if (balance > 1 && data > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    /* Right Left */
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int choice, value;

    while (1) {
        printf("\nAVL Tree Menu:\n");
        printf("1. Insert\n2. Display (Inorder)\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value inserted and tree balanced.\n");
                break;
            case 2:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
