#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
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

// Function to insert a node into the binary search tree
struct Node* insert(struct Node* root, int key) {
    // If the tree is empty, create a new node and return it
    if (root == NULL)
        return createNode(key);

    // If the key is smaller than the root, recursively insert into the left subtree
    if (key < root->key)
        root->left = insert(root->left, key);
    // If the key is larger than the root, recursively insert into the right subtree
    else if (key > root->key)
        root->right = insert(root->right, key);

    // Return the root node after insertion
    return root;
}

// Function to search for a key in the binary search tree
struct Node* search(struct Node* root, int key) {
    // If the tree is empty or the key is found at the root, return the root
    if (root == NULL || root->key == key)
        return root;

    // If the key is smaller than the root, recursively search in the left subtree
    if (key < root->key)
        return search(root->left, key);
    // If the key is larger than the root, recursively search in the right subtree
    else if (key > root->key)
        return search(root->right, key);
}

// Function to perform an inorder traversal of the binary search tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Main function to test the binary search tree implementation
int main() {
    struct Node* root = NULL;

    // Inserting elements into the binary search tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Printing the inorder traversal of the binary search tree
    printf("Inorder traversal of the binary search tree: ");
    inorderTraversal(root);
    printf("\n");

    // Searching for a key in the binary search tree
    int key = 40;
    struct Node* result = search(root, key);
    if (result != NULL)
        printf("Key %d found in the binary search tree.\n", key);
    else
        printf("Key %d not found in the binary search tree.\n", key);

    return 0;
}
