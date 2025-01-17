#include<iostream>
using namespace std;

// Node class to represent each node of the AVL tree
class Node
{
    public:
    int data;          // Data stored in the node
    int height;        // Height of the node
    Node* left;        // Pointer to the left child
    Node* right;       // Pointer to the right child

    // Constructor to initialize a node with a given value
    Node(int val)
    {
        data = val;
        height = 0;    // New nodes are initialized with a height of 0
        left = right = nullptr;  // No children initially
    }
};

// AVL Tree class
class AVLtree
{
    public:
    Node* root;  // Pointer to the root of the AVL tree

    // Constructor to initialize an empty AVL tree
    AVLtree() 
    {
        root = nullptr;  // Start with an empty tree
    }

    // Function to calculate the height of a node
    int tree_height(Node* root)
    {
        if (root == nullptr)   // If the node is null, return -1 (to denote an empty tree)
            return -1;
        else
            return root->height;  // Return the height of the node
    }

    // Single rotation left function to fix a Left-Left imbalance
    Node* SingleRotateLeft(Node* X)
    {
        // Perform left rotation
        Node* W = X->left;     // W is X's left child
        X->left = W->right;    // X's new left child is W's right child
        W->right = X;          // W's right child becomes X, completing the rotation

        // Update heights after rotation
        X->height = max(tree_height(X->left), tree_height(X->right)) + 1;  // Recalculate height of X
        W->height = max(tree_height(W->left), tree_height(X)) + 1;         // Recalculate height of W

        return W;  // W is the new root after the left rotation
    }

    // Single rotation right function to fix a Right-Right imbalance
    Node* SingleRotateRight(Node* W)
    {
        // Perform right rotation
        Node* X = W->right;    // X is W's right child
        W->right = X->left;    // W's new right child is X's left child
        X->left = W;           // X's left child becomes W, completing the rotation

        // Update heights after rotation
        W->height = max(tree_height(W->left), tree_height(W->right)) + 1;  // Recalculate height of W
        X->height = max(tree_height(X->left), tree_height(W)) + 1;         // Recalculate height of X

        return X;  // X is the new root after the right rotation
    }

    // Double rotation left function to fix a Left-Right imbalance
    Node* DoubleRotateWithLeft(Node* Z)
    {
        // Perform a right rotation on Z's left child, then a left rotation on Z
        Z->left = SingleRotateRight(Z->left);  // Right rotate on Z's left subtree
        return SingleRotateLeft(Z);            // Left rotate on Z
    }

    // Double rotation right function to fix a Right-Left imbalance
    Node* DoubleRotateWithRight(Node* Z)
    {
        // Perform a left rotation on Z's right child, then a right rotation on Z
        Z->right = SingleRotateLeft(Z->right);  // Left rotate on Z's right subtree
        return SingleRotateRight(Z);            // Right rotate on Z
    }

    // Insert function to insert data into the AVL tree and maintain balance
    Node* Insert(Node* root, int data)
    {
        // If the root is null, create a new node with the given data
        if (root == nullptr)
        {
            return new Node(data);  // Return the new node (which becomes the root of this subtree)
        }

        // Insert the data into the left subtree if the data is less than root's data
        if (data < root->data)
        {
            root->left = Insert(root->left, data);  // Recursively insert in the left subtree

            // Check for Left imbalance (if left subtree is higher than the right by more than 1)
            if (tree_height(root->left) - tree_height(root->right) == 2)
            {
                if (data < root->left->data)  // Left-Left case (left subtree of left child is imbalanced)
                {
                    root = SingleRotateLeft(root);  // Perform single left rotation
                }
                else  // Left-Right case (right subtree of left child is imbalanced)
                {
                    root = DoubleRotateWithLeft(root);  // Perform double left rotation
                }
            }
        }
        // Insert the data into the right subtree if the data is greater than root's data
        else if (data > root->data)
        {
            root->right = Insert(root->right, data);  // Recursively insert in the right subtree

            // Check for Right imbalance (if right subtree is higher than the left by more than 1)
            if (tree_height(root->right) - tree_height(root->left) == 2)
            {
                if (data > root->right->data)  // Right-Right case (right subtree of right child is imbalanced)
                {
                    root = SingleRotateRight(root);  // Perform single right rotation
                }
                else  // Right-Left case (left subtree of right child is imbalanced)
                {
                    root = DoubleRotateWithRight(root);  // Perform double right rotation
                }
            }
        }

        // Update height of the current node after insertion
        root->height = max(tree_height(root->left), tree_height(root->right)) + 1;

        return root;  // Return the (possibly new) root of this subtree
    }
};

int main()
{
    AVLtree tree;  // Create an AVL tree object

    // Insert nodes into the AVL tree
    tree.root = tree.Insert(tree.root, 10);
    tree.root = tree.Insert(tree.root, 20);
    tree.root = tree.Insert(tree.root, 5);
    tree.root = tree.Insert(tree.root, 4);
    tree.root = tree.Insert(tree.root, 6);
    tree.root = tree.Insert(tree.root, 15);

    // Additional testing can be done here

    return 0;  // End of program
}
