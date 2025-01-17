#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(T data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template <typename T>
class BinarySearchTree
{
public:
    Node<T> *root;

    BinarySearchTree()
    {
        this->root = nullptr;
    }

    Node<T> *insert(Node<T> *root, T data);
    Node<T> *Delete(Node<T> *root, T data);
    Node<T> *search(Node<T> *root, T data);
    Node<T> *findMin(Node<T> *root);
    Node<T> *findMax(Node<T> *root);
};

template <typename T>
Node<T> *BinarySearchTree<T>::insert(Node<T> *root, T data)
{
    if (root == nullptr)
    {
        return new Node<T>(data);
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

template <typename T>
Node<T> *BinarySearchTree<T>::Delete(Node<T> *root, T data)
{
    if (root == nullptr)
    {
        cout << "Element is not in tree!" << endl;
        return root;
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

        if (root->left != nullptr && root->right != nullptr)
        {

            Node<T> *temp = findMax(root->left);
            root->data = temp->data;
            root->left = Delete(root->left, temp->data);
        }
        else
        {

            Node<T> *temp = root;
            if (root->left == nullptr)
            {
                root = root->right;
            }
            else if (root->right == nullptr)
            {
                root = root->left;
            }
            delete temp;
        }
    }
    return root;
}

template <typename T>
Node<T> *BinarySearchTree<T>::search(Node<T> *root, T data)
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

template <typename T>
Node<T> *BinarySearchTree<T>::findMin(Node<T> *root)
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

template <typename T>
Node<T> *BinarySearchTree<T>::findMax(Node<T> *root)
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
    BinarySearchTree<int> bst;

    bst.root = bst.insert(bst.root, 50);
    bst.root = bst.insert(bst.root, 30);
    bst.root = bst.insert(bst.root, 70);
    bst.root = bst.insert(bst.root, 20);
    bst.root = bst.insert(bst.root, 40);
    bst.root = bst.insert(bst.root, 60);
    bst.root = bst.insert(bst.root, 80);

    int searchValue = 40;
    Node<int> *foundNode = bst.search(bst.root, searchValue);
    if (foundNode)
    {
        cout << "Value " << searchValue << " found in the tree." << endl;
    }
    else
    {
        cout << "Value " << searchValue << " not found in the tree." << endl;
    }

    Node<int> *minNode = bst.findMin(bst.root);
    Node<int> *maxNode = bst.findMax(bst.root);
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
