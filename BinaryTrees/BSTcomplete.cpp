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

class BST
{
public:
    Node *root;

    BST();
    ~BST();
    Node *insert(Node *root, int data);
    Node *Search(Node *root, int data);
    Node *Find_Max(Node *root);
    Node *Find_Min(Node *root);
    Node *Delete(Node *root, int data);

    int count_leaves(Node *root);
    int count_nodes(Node *root);
    int sum_nodes(Node *root);
    int sum_leaf_nodes(Node *root);
    int height(Node *root);
    double average(Node *root);
    void display_in_order(Node *root);
    int singleParent(Node *root);
    int twoChildrenNodes(Node *root);
    int count_non_leaf_nodes(Node *root);

private:
    void delete_tree(Node *root);
};

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    delete_tree(root);
}

void BST::delete_tree(Node *root)
{
    if (root != nullptr)
    {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
}

Node *BST::insert(Node *root, int data)
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

Node *BST::Search(Node *root, int data)
{
    if (root == nullptr || root->data == data)
    {
        return root;
    }
    else
    {
        if (data < root->data)
        {
            return Search(root->left, data);
        }
        else
        {
            return Search(root->right, data);
        }
    }
    return root;
}

Node *BST::Find_Max(Node *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else if (root->right == nullptr)
    {
        return root;
    }
    else
    {
        return Find_Max(root->right);
    }
}

Node *BST::Find_Min(Node *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else if (root->left == nullptr)
    {
        return root;
    }
    else
    {
        return Find_Min(root->left);
    }
}

Node *BST::Delete(Node *root, int data)
{
    if (root == nullptr)
    {

        cout << "Element not in tree!" << endl;
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

        if (root->left && root->right)
        {

            Node *temp = Find_Max(root->left);
            root->data = temp->data;
            root->left = Delete(root->left, temp->data);
        }
        else
        {

            Node *temp = root;
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

int BST::count_leaves(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return 1;
    }
    return count_leaves(root->left) + count_leaves(root->right);
}

int BST::count_nodes(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int BST::sum_nodes(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return root->data + sum_nodes(root->left) + sum_nodes(root->right);
}

int BST::sum_leaf_nodes(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        return root->data;
    }
    return sum_leaf_nodes(root->left) + sum_leaf_nodes(root->right);
}

int BST::height(Node *root)
{
    if (root == nullptr)
    {
        return -1;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    return 1 + max(left_height, right_height);
}

double BST::average(Node *root)
{
    int total_sum = sum_nodes(root);
    int total_nodes = count_nodes(root);
    if (total_nodes == 0)
        return 0;
    return static_cast<double>(total_sum) / total_nodes;
}

void BST::display_in_order(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    display_in_order(root->left);
    cout << root->data << " ";
    display_in_order(root->right);
}

int BST::singleParent(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int count = 0;
    if ((root->left == nullptr && root->right != nullptr) || (root->left != nullptr && root->right == nullptr))
    {
        count = 1;
    }
    return count + singleParent(root->left) + singleParent(root->right);
}

int BST::twoChildrenNodes(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int count = 0;
    if (root->left != nullptr && root->right != nullptr)
    {
        count = 1;
    }

    return count + twoChildrenNodes(root->left) + twoChildrenNodes(root->right);
}
int BST::count_non_leaf_nodes(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int count = 0;

    if (root->left != nullptr || root->right != nullptr)
    {
        count = 1;
    }

    return count + count_non_leaf_nodes(root->left) + count_non_leaf_nodes(root->right);
}

int main()
{
    BST tree;
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);
    Node *result = tree.Search(tree.root, 90);
    if (result != nullptr)
    {
        cout << "Found node with value: " << result->data << endl;
    }
    else
    {
        cout << "Node not found" << endl;
    }

    cout << "In-order display: ";
    tree.display_in_order(tree.root);
    cout << endl;

    cout << "Total nodes: " << tree.count_nodes(tree.root) << endl;
    cout << "Leaf nodes: " << tree.count_leaves(tree.root) << endl;
    cout << "Sum of nodes: " << tree.sum_nodes(tree.root) << endl;
    cout << "Sum of leaf nodes: " << tree.sum_leaf_nodes(tree.root) << endl;
    cout << "Height of the tree: " << tree.height(tree.root) << endl;
    cout << "Average of nodes: " << tree.average(tree.root) << endl;

    cout << "Nodes with exactly one children: " << tree.singleParent(tree.root) << endl;
    cout << "Nodes with exactly two children: " << tree.twoChildrenNodes(tree.root) << endl;
    cout << "Nodes with one or two children: " << tree.count_non_leaf_nodes(tree.root) << endl;

    return 0;
}
