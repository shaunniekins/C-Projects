#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct bstNode {
    int id;
    char name[MAX];
    int quantity;
    struct bstNode* left;
    struct bstNode* right;
    struct bstNode* parent;
} BSTNode;

void insertNode(BSTNode** root, int id, const char* name, int quantity);
BSTNode* search(BSTNode* root, int target);
void deleteNode(BSTNode** root, int target);
BSTNode* findSuccessor(BSTNode* node);
void update(BSTNode** root);
void displayTree(BSTNode* root);
void menu(BSTNode** root);

void insertNode(BSTNode** root, int id, const char* name, int quantity) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    newNode->id = id;
    strncpy(newNode->name, name, MAX);
    newNode->quantity = quantity;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    if (*root == NULL) {
        *root = newNode;
    } else {
        BSTNode* currentNode = *root;
        BSTNode* parent = NULL;

        while (currentNode != NULL) {
            parent = currentNode;
            if (id < currentNode->id) {
                currentNode = currentNode->left;
            } else {
                currentNode = currentNode->right;
            }
        }

        newNode->parent = parent;
        if (id < parent->id) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }
}

BSTNode* search(BSTNode* root, int target) {
    BSTNode* currentNode = root;

    while (currentNode != NULL && currentNode->id != target) {
        if (target < currentNode->id) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }

    return currentNode;
}

void deleteNode(BSTNode** root, int target) {
    BSTNode* nodeToDelete = search(*root, target);

    if (nodeToDelete == NULL) {
        printf("Product with ID %d not found.\n", target);
        return;
    }

    if (nodeToDelete->left == NULL && nodeToDelete->right == NULL) {
        // Node to delete has no children (leaf node)
        if (nodeToDelete == *root) {
            *root = NULL;
        } else if (nodeToDelete == nodeToDelete->parent->left) {
            nodeToDelete->parent->left = NULL;
        } else {
            nodeToDelete->parent->right = NULL;
        }

        free(nodeToDelete);
    } else if (nodeToDelete->left != NULL && nodeToDelete->right != NULL) {
        // Node to delete has two children
        BSTNode* successor = findSuccessor(nodeToDelete);
        nodeToDelete->id = successor->id;
        strncpy(nodeToDelete->name, successor->name, MAX);
        nodeToDelete->quantity = successor->quantity;
        deleteNode(&nodeToDelete->right, successor->id);
    } else {
        // Node to delete has one child
        BSTNode* childNode = (nodeToDelete->left != NULL) ? nodeToDelete->left : nodeToDelete->right;

        if (nodeToDelete == *root) {
            *root = childNode;
        } else if (nodeToDelete == nodeToDelete->parent->left) {
            nodeToDelete->parent->left = childNode;
        } else {
            nodeToDelete->parent->right = childNode;
        }

        childNode->parent = nodeToDelete->parent;
        free(nodeToDelete);
    }

    printf("Product with ID %d deleted successfully.\n", target);
}

BSTNode* findSuccessor(BSTNode* node) {
    BSTNode* current = node->right;

    while (current != NULL && current->left != NULL) {
        current = current->left;
    }

    return current;
}

void update(BSTNode** root) {
    int id_upd;
    printf("Product ID to update: ");
    scanf("%d", &id_upd);

    BSTNode* foundNode = search(*root, id_upd);

    if (foundNode == NULL) {
        printf("Product with ID %d not found.\n", id_upd);
    } else {
        printf("PRODUCT FOUND:\n");
        printf("Product Name: %s\n", foundNode->name);
        printf("Product Quantity: %d\n\n", foundNode->quantity);

        printf("Enter new product id: ");
        scanf("%d", &foundNode->id);

        printf("Enter new product name: ");
        scanf(" %s", foundNode->name);

        printf("Enter new product quantity: ");
        scanf("%d", &foundNode->quantity);

        printf("Product information updated successfully.\n");

        // Update the values directly in the existing node
        // No need to remove and reinsert the node

        // Note: If the node is a leaf node, its children will be NULL and won't be affected

        // Reconnect the children with the updated node
        if (foundNode->left != NULL) {
            foundNode->left->parent = foundNode;
        }
        if (foundNode->right != NULL) {
            foundNode->right->parent = foundNode;
        }
    }
}

void displayNodeInfo(BSTNode* node) {
    if (node == NULL) {
        printf("Product not found.\n");
    } else {
        printf("PRODUCT FOUND:\n");
        printf("Product ID: %d\n", node->id);

        if (node->parent == NULL) {
            printf("Parent Node ID: N/A\n");
        } else {
            printf("Parent Node ID: %d\n", node->parent->id);
        }

        if (node->parent == NULL) {
            printf("Root Node: Root\n");
        } else if (node->parent->left == node) {
            printf("Root Node: Left Child\n");
        } else {
            printf("Root Node: Right Child\n");
        }

        int height = -1;
        BSTNode* currentNode = node;
        while (currentNode != NULL) {
            height++;
            currentNode = currentNode->parent;
        }

        printf("Height: %d\n", height);
        printf("Product Name: %s\n", node->name);
        printf("Product Quantity: %d\n", node->quantity);
    }
}

void searchById(BSTNode* root) {
    int id_search;
    printf("Product ID to search: ");
    scanf("%d", &id_search);

    BSTNode* foundNode = search(root, id_search);
    displayNodeInfo(foundNode);
}


void displayTree(BSTNode* root) {
    if (root == NULL) {
        return;
    }

    displayTree(root->left);

    printf("%20d", root->id);

    if (root->parent == NULL) {
        printf("%20s", "N/A");
    } else {
        printf("%20d", root->parent->id);
    }

    if (root->parent == NULL) {
        printf("%20s", "Root");
    } else if (root->parent->left == root) {
        printf("%20s", "L");
    } else {
        printf("%20s", "R");
    }

    int height = -1;
    BSTNode* currentNode = root;
    while (currentNode != NULL) {
        height++;
        currentNode = currentNode->parent;
    }

    // Additional columns for product name and product quantity
    printf("%20d %20s %20d\n", height, root->name, root->quantity);
    // printf("%20d\n", height);
    
    displayTree(root->right);
}

void menu(BSTNode** root) {
    int choice;
    printf("\n\n--------------\n");
    printf("1. Add a product\n2. Display products\n3. Delete a product info\n4. Update a product info\n5. Search by ID\nChoice (1, 2, 3, 4, or 5) => ");
    scanf("%d", &choice);
    printf("--------------\n\n");

    switch (choice) {
        case 1: {
            int tempVal;
            printf("Product ID: ");
            scanf("%d", &tempVal);
            BSTNode* existingNode = search(*root, tempVal);
            if (existingNode != NULL) {
                printf("ID already exists.\n");
                menu(root);
                return;
            }

            char tempName[MAX];
            printf("Product Name: ");
            scanf(" %s", tempName);

            int tempQuantity;
            printf("Product Quantity: ");
            scanf("%d", &tempQuantity);

            insertNode(root, tempVal, tempName, tempQuantity);
            break;
        }
        case 2:
            printf("%20s %20s %20s  %20s %20s  %20s\n", "Node ID", "Parent Node ID", "Root Node", "Height", "Product Name", "Product Quantity");
            displayTree(*root);
            break;
        case 3: {
            int id_del;
            printf("Product ID to delete: ");
            scanf("%d", &id_del);
            deleteNode(root, id_del);
            break;
        }
        case 4:
            update(root);
            break;
        case 5:
            searchById(*root);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    menu(root);
}

int main() {
    BSTNode* root = NULL;
    menu(&root);
    return 0;
}
