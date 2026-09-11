#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node *N) {
    if (N == NULL)
        return 0;

    return N->height;
}

struct Node *newNode(int key) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

// Right rotation
struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotation
struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get balance factor
int getBalance(struct Node *N) {
    if (N == NULL)
        return 0;

    return height(N->left) - height(N->right);
}

// Insert a node
struct Node *insertNode(struct Node *node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key) {
        node->left = insertNode(node->left, key);
    }
    else if (key > node->key) {
        node->right = insertNode(node->right, key);
    }
    else {
        return node;   // Duplicate keys are not allowed
    }

    // Update height
    node->height = 1 + max(height(node->left), height(node->right));

    // Get balance factor
    int balance = getBalance(node);

    // LL Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // RR Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // LR Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Find node with minimum value
struct Node *minValueNode(struct Node *node) {
    struct Node *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// Delete a node
struct Node *deleteNode(struct Node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Node with one child or no child
        if (root->left == NULL || root->right == NULL) {
            struct Node *temp;

            if (root->left != NULL)
                temp = root->left;
            else
                temp = root->right;

            // No child
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else {
                // One child
                *root = *temp;
            }

            free(temp);
        }
        else {
            // Node with two children
            struct Node *temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If tree has become empty
    if (root == NULL)
        return root;

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Get balance factor
    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // LR Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // RL Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Preorder traversal
void printPreOrder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->key);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

int main() {
    struct Node *root = NULL;

    root = insertNode(root, 9);
    root = insertNode(root, 5);
    root = insertNode(root, 10);
    root = insertNode(root, 0);
    root = insertNode(root, 6);
    root = insertNode(root, 11);
    root = insertNode(root, -1);
    root = insertNode(root, 1);
    root = insertNode(root, 2);

    printf("Preorder traversal of the constructed AVL tree is:\n");
    printPreOrder(root);

    root = deleteNode(root, 10);

    printf("\n\nPreorder traversal after deletion of 10:\n");
    printPreOrder(root);

    return 0;
}

