#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree
{
public:
    Node *root;

    BinarySearchTree()
    {
        this->root = nullptr;
    }

    Node *insert(Node *root, int data);
    Node *Delete(Node *root, int data);
    Node *search(Node *root, int data);
    Node *findMin(Node *root);
    Node *findMax(Node *root);
};

Node *BinarySearchTree::insert(Node *root, int data)
{
    if (root == nullptr)
    {

        return new Node(data);
    }
    else
    {
        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = insert(root->right, data);
        }
    }
    return root;
}
Node *BinarySearchTree::Delete(Node *root, int data)
{
    if (root == nullptr)
    {
        cout << "Element is not in tree!" << endl;
        return root; // Return early if root is nullptr
    }
    else if (data < root->data)
    {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = Delete(root->right, data);
    }
    else
    {
        // Found the node to be deleted
        if (root->left != nullptr && root->right != nullptr)
        {
            // Node with two children: get the largest in the left subtree (predecessor)
            Node *temp = findMax(root->left);
            root->data = temp->data;                     // Replace root data with max of left subtree
            root->left = Delete(root->left, temp->data); // Delete the predecessor
        }
        else
        {
            // Node with one child or no child
            Node *temp = root;
            if (root->left == nullptr)
            {
                root = root->right; // Assign right child (could be nullptr)
            }
            else if (root->right == nullptr)
            {
                root = root->left; // Assign left child (could be nullptr)
            }
            delete temp; // Delete the node
        }
    }
    return root;
}

Node *BinarySearchTree::search(Node *root, int data)
{
    if (root == nullptr || root->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

Node *BinarySearchTree::findMin(Node *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->left == nullptr)
    {
        return root;
    }
    return findMin(root->left);
}

Node *BinarySearchTree::findMax(Node *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    if (root->right == nullptr)
    {
        return root;
    }
    return findMax(root->right);
}

int main()
{
    BinarySearchTree bst;

    bst.root = bst.insert(bst.root, 50);
    bst.root = bst.insert(bst.root, 30);
    bst.root = bst.insert(bst.root, 70);
    bst.root = bst.insert(bst.root, 20);
    bst.root = bst.insert(bst.root, 40);
    bst.root = bst.insert(bst.root, 60);
    bst.root = bst.insert(bst.root, 80);

    int searchValue = 40;
    Node *foundNode = bst.search(bst.root, searchValue);
    if (foundNode)
    {
        cout << "Value " << searchValue << " found in the tree." << endl;
    }
    else
    {
        cout << "Value " << searchValue << " not found in the tree." << endl;
    }

    Node *minNode = bst.findMin(bst.root);
    Node *maxNode = bst.findMax(bst.root);
    if (minNode)
    {
        cout << "Minimum value: " << minNode->data << endl;
    }
    if (maxNode)
    {
        cout << "Maximum value: " << maxNode->data << endl;
    }

    return 0;
}
