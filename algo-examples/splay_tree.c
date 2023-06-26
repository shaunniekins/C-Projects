#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the Splay tree
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to right rotate subtree rooted with y
struct Node* rightRotate(struct Node* x) {
    struct Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Function to left rotate subtree rooted with x
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// Function to perform a splay operation on a given key
struct Node* splay(struct Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    // Key is in the left subtree
    if (root->key > key) {
        // Key is not in the tree, return the original tree
        if (root->left == NULL)
            return root;

        // Zig-Zig (Left Left)
        if (root->left->key > key) {
            // Recursively bring the key as root of left-left
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        // Zig-Zag (Left Right)
        else if (root->left->key < key) {
            // Recursively bring the key as root of left-right
            root->left->right = splay(root->left->right, key);
            // Perform first rotation for root->left
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        // Perform second rotation for root
        return (root->left == NULL) ? root : rightRotate(root);
    }
    // Key is in the right subtree
    else {
        // Key is not in the tree, return the original tree
        if (root->right == NULL)
            return root;

        // Zag-Zig (Right Left)
        if (root->right->key > key) {
            // Recursively bring the key as root of right-left
            root->right->left = splay(root->right->left, key);
            // Perform first rotation for root->right
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        // Zag-Zag (Right Right)
        else if (root->right->key < key) {
            // Recursively bring the key as root of right-right
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        // Perform second rotation for root
        return (root->right == NULL) ? root : leftRotate(root);
    }
}

// Function to insert a node into the Splay tree
struct Node* insert(struct Node* root, int key) {
    // If the tree is empty, create a new node and return it
    if (root == NULL)
        return createNode(key);

    // Perform the splay operation on the key to bring it to the root
    root = splay(root, key);

    // If the key is already present, return the root
    if (root->key == key)
        return root;

    // Create a new node for the key
    struct Node* newNode = createNode(key);

    // If the key is smaller than the root, make the root the right child of the new node
    if (root->key > key) {
        newNode->right = root;
        newNode->left = root->left;
        root->left = NULL;
    }
    // If the key is larger than the root, make the root the left child of the new node
    else {
        newNode->left = root;
        newNode->right = root->right;
        root->right = NULL;
    }

    return newNode;
}

// Function to print the Splay tree in inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Main function to test the Splay tree implementation
int main() {
    struct Node* root = NULL;

    // Inserting elements into the Splay tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    // Printing the inorder traversal of the Splay tree
    printf("Inorder traversal of the Splay tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
