#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_KEYS (10)
#define MIN_KEYS ((MAX_KEYS + 1) / 2 - 1)

// Structure for a B-tree node
struct BTreeNode {
    int numKeys;
    int keys[MAX_KEYS];
    struct BTreeNode* child[MAX_KEYS + 1];
    bool isLeaf;
};

// Function to create a new B-tree node
struct BTreeNode* createNode(bool isLeaf) {
    struct BTreeNode* newNode = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    newNode->numKeys = 0;
    newNode->isLeaf = isLeaf;
    int i;
    for (i = 0; i <= MAX_KEYS; i++)
        newNode->child[i] = NULL;
    return newNode;
}

// Function to search a key in the B-tree
struct BTreeNode* search(struct BTreeNode* root, int key) {
    int i = 0;
    while (i < root->numKeys && key > root->keys[i])
        i++;
    if (i < root->numKeys && key == root->keys[i])
        return root;
    if (root->isLeaf)
        return NULL;
    return search(root->child[i], key);
}

// Function to split a child node of the B-tree
void splitChild(struct BTreeNode* parentNode, int childIndex, struct BTreeNode* childNode) {
    struct BTreeNode* newNode = createNode(childNode->isLeaf);
    newNode->numKeys = MIN_KEYS;
    int i;
    for (i = 0; i < MIN_KEYS; i++) {
        newNode->keys[i] = childNode->keys[i + MIN_KEYS + 1];
        childNode->keys[i + MIN_KEYS + 1] = 0;
    }
    if (!childNode->isLeaf) {
        for (i = 0; i <= MIN_KEYS; i++) {
            newNode->child[i] = childNode->child[i + MIN_KEYS + 1];
            childNode->child[i + MIN_KEYS + 1] = NULL;
        }
    }
    childNode->numKeys = MIN_KEYS;
    for (i = parentNode->numKeys; i > childIndex; i--)
        parentNode->child[i + 1] = parentNode->child[i];
    parentNode->child[childIndex + 1] = newNode;
    for (i = parentNode->numKeys - 1; i >= childIndex; i--)
        parentNode->keys[i + 1] = parentNode->keys[i];
    parentNode->keys[childIndex] = childNode->keys[MIN_KEYS];
    childNode->keys[MIN_KEYS] = 0;
    parentNode->numKeys++;
}

// Function to insert a key into the B-tree
void insert(struct BTreeNode** root, int key) {
    if (*root == NULL) {
        *root = createNode(true);
        (*root)->keys[0] = key;
        (*root)->numKeys++;
    } else {
        if ((*root)->numKeys == MAX_KEYS) {
            struct BTreeNode* newNode = createNode(false);
            newNode->child[0] = *root;
            *root = newNode;
            splitChild(newNode, 0, newNode->child[0]);
            int i = 0;
            if (newNode->keys[0] < key)
                i++;
            insert(&(newNode->child[i]), key);
        } else {
            int i = (*root)->numKeys - 1;
            while (i >= 0 && key < (*root)->keys[i]) {
                (*root)->keys[i + 1] = (*root)->keys[i];
                i--;
            }
            (*root)->keys[i + 1] = key;
            (*root)->numKeys++;
        }
    }
}

// Function to print the keys in the B-tree in ascending order
void printBTree(struct BTreeNode* root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->numKeys; i++) {
            printBTree(root->child[i]);
            printf("%d ", root->keys[i]);
        }
        printBTree(root->child[i]);
    }
}

// Main function to test the B-tree implementation
int main() {
    struct BTreeNode* root = NULL;

    // Inserting elements into the B-tree
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 70);
    insert(&root, 10);
    insert(&root, 40);
    insert(&root, 60);
    insert(&root, 80);
    insert(&root, 20);
    insert(&root, 25);
    insert(&root, 35);
    insert(&root, 45);
    insert(&root, 55);
    insert(&root, 65);
    insert(&root, 75);
    insert(&root, 85);

    // Printing the keys in the B-tree
    printf("Keys in the B-tree: ");
    printBTree(root);
    printf("\n");

    // Searching for a key in the B-tree
    int key = 40;
    struct BTreeNode* result = search(root, key);
    if (result != NULL)
        printf("Key %d found in the B-tree.\n", key);
    else
        printf("Key %d not found in the B-tree.\n", key);

    return 0;
}
