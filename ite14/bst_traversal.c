/**
 * A simple program allows the user to insert keys or values that will be used to display three traversal methods: inorder, preorder, and postorder.
**/

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
typedef struct node {
    int key;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node with the given key
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node with the given key into the binary search tree
Node* insertNode(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }

    return root;
}

// Function to perform an inorder traversal of the binary search tree
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Function to perform a preorder traversal of the binary search tree
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform a postorder traversal of the binary search tree
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}

// Function to display the menu and handle user input
void menu() {
    Node* root = NULL;
    int choice, value;

    do {
        printf("-- MENU --\n");
        printf("1. Insert value\n");
        printf("2. Display inorder\n");
        printf("3. Display preorder\n");
        printf("4. Display postorder\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("clear");
                int insertNum;
                printf("\nNumber of values to insert: ");
                scanf("%d", &insertNum);

                for (int i = 0; i < insertNum; i++) {
                    int value;  // Declare value inside the loop
                    printf("Enter the value to insert: ");
                    scanf("%d", &value);
                    root = insertNode(root, value);
                }
                break;
            case 2:
                system("clear");
                printf("Inorder traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 3:
                system("clear");
                printf("Preorder traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 4:
                system("clear");
                printf("Postorder traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 5:
                system("clear");
                printf("Exiting the program.\n");
                break;
            default:
                system("clear");
                printf("Invalid choice. Please try again.\n");
                break;
        }

        printf("\n");
    } while (choice != 5);
}

int main() {
    system("clear");
    menu();
    return 0;
}
