#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int height;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        height = 0;
        left = right = nullptr;
    }
};

class AVLtree
{
public:
    Node *root;

    AVLtree()
    {
        root = nullptr;
    }

    int tree_height(Node *root)
    {
        if (root == nullptr)
            return -1;
        else
            return root->height;
    }

    Node *SingleRotateLeft(Node *X)
    {
        Node *W = X->left;
        X->left = W->right;
        W->right = X;

        X->height = max(tree_height(X->left), tree_height(X->right)) + 1;
        W->height = max(tree_height(W->left), tree_height(X)) + 1;

        return W;
    }

    Node *SingleRotateRight(Node *W)
    {
        Node *X = W->right;
        W->right = X->left;
        X->left = W;

        W->height = max(tree_height(W->left), tree_height(W->right)) + 1;
        X->height = max(tree_height(X->left), tree_height(W)) + 1;

        return X;
    }

    Node *DoubleRotateWithLeft(Node *Z)
    {
        Z->left = SingleRotateRight(Z->left);
        return SingleRotateLeft(Z);
    }

    Node *DoubleRotateWithRight(Node *Z)
    {
        Z->right = SingleRotateLeft(Z->right);
        return SingleRotateRight(Z);
    }

    Node *Insert(Node *root, int data)
    {
        if (root == nullptr)
        {
            return new Node(data);
        }

        if (data < root->data)
        {
            root->left = Insert(root->left, data);

            if (tree_height(root->left) - tree_height(root->right) == 2)
            {
                if (data < root->left->data)
                {
                    root = SingleRotateLeft(root);
                }
                else
                {
                    root = DoubleRotateWithLeft(root);
                }
            }
        }
        else if (data > root->data)
        {
            root->right = Insert(root->right, data);

            if (tree_height(root->right) - tree_height(root->left) == 2)
            {
                if (data > root->right->data)
                {
                    root = SingleRotateRight(root);
                }
                else
                {
                    root = DoubleRotateWithRight(root);
                }
            }
        }

        root->height = max(tree_height(root->left), tree_height(root->right)) + 1;

        return root;
    }
};

int main()
{
    AVLtree tree;
    tree.root = tree.Insert(tree.root, 10);
    tree.root = tree.Insert(tree.root, 20);
    tree.root = tree.Insert(tree.root, 5);
    tree.root = tree.Insert(tree.root, 4);
    tree.root = tree.Insert(tree.root, 6);
    tree.root = tree.Insert(tree.root, 15);

    return 0;
}
