#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Pre-order traversal function
void preOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data); // Process the node
    preOrderTraversal(root->left); // Traverse left subtree
    preOrderTraversal(root->right); // Traverse right subtree
}

// In-order traversal function
void inOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    inOrderTraversal(root->left); // Traverse left subtree
    printf("%d ", root->data); // Process the node
    inOrderTraversal(root->right); // Traverse right subtree
}

// Post-order traversal function
void postOrderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    postOrderTraversal(root->left); // Traverse left subtree
    postOrderTraversal(root->right); // Traverse right subtree
    printf("%d ", root->data); // Process the node
}

int main() {
    // Create the binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}
