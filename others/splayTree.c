#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct node
{
    int key;
    struct node *left, *right;
};

// Allocates a new node with the given key and NULL left and right pointers.
struct node *TreeNode(int key)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}

// A utility function for right-rotating a y-rooted subtree.
struct node *rightRotate(struct node *x)
{
    struct node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// A utility function for right-rotating a x-rooted subtree.
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

// If the key is present in the tree, this function moves it to the root.
// If the key is not present, it returns the last item accessed by root.
// This function modifies the tree and returns the modified root.
struct node *splay(struct node *root, int key)
{
    // Root is NULL or key is present at root.
    if (root == NULL || root->key == key)
        return root;

    // Key lies in left subtree!
    if (root->key > key)
    {
        if (root->left == NULL)
            return root;

        // Zig-Zig (Left Left)
        if (root->left->key > key)
        {
            // First, recursively bring the key as the root of left-left.
            root->left->left = splay(root->left->left, key);

            // Do the first rotation for the root, followed by the second rotation.
            root = rightRotate(root);
        }
        else if (root->left->key < key) // Zig-Zag (Left Right)
        {
            //  First, recursively bring the key as the root of left-right.
            root->left->right = splay(root->left->right, key);

            // Do first rotation for root->left
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        // Do second rotation for root
        return (root->left == NULL) ? root : rightRotate(root);
    }
    // Key lies in right subtree
    else
    {
        if (root->right == NULL)
            return root;

        // Zag-Zig (Right Left)
        if (root->right->key > key)
        {
            // Bring the key as root of right-left
            root->right->left = splay(root->right->left, key);

            // Do first rotation for root->right
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        // Zag-Zag (Right Right)
        else if (root->right->key < key)
        {
            // Bring the key as root of right-right and do first rotation
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }

        // Do second rotation for root
        return (root->right == NULL) ? root : leftRotate(root);
    }
}

// The search function for Splay Tree. Note that this function returns the new root of the splay-tree.
// If a key is present in the tree, then it is moved to the root.
struct node *bstSearch(struct node *root, int key)
{
    return splay(root, key);
}

// A utility function to print preorder traversal of the tree.
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// main function
int main()
{
    struct node *root = TreeNode(100);
    root->left = TreeNode(50);
    root->right = TreeNode(200);
    root->left->left = TreeNode(40);
    root->left->left->left = TreeNode(30);
    root->left->left->left->left = TreeNode(20);

    root = bstSearch(root, 20);
    preOrder(root);
    return 0;
}
