#include <iostream>
#include <algorithm> // for std::abs and std::max
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template <typename T>
class BST {
public:
    Node<T>* root;

    BST() { root = nullptr; }

    Node<T>* insert(Node<T>* root, T data);
    Node<T>* Search(Node<T>* root, T data);
    Node<T>* Find_Max(Node<T>* root);
    Node<T>* Find_Min(Node<T>* root);
    Node<T>* Delete(Node<T>* root, T data);
    
    int count_leaves(Node<T>* root);
    int count_nodes(Node<T>* root);
    T sum_nodes(Node<T>* root);
    T sum_leaf_nodes(Node<T>* root);
    int height(Node<T>* root);
    int find_depth(Node<T>* root, T data, int depth = 0);
    bool is_balanced(Node<T>* root);
    void display_in_order(Node<T>* root);
};

template <typename T>
Node<T>* BST<T>::insert(Node<T>* root, T data) {
    if (root == nullptr) {
        return new Node<T>(data);
    } else {
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else if (data > root->data) {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

template <typename T>
Node<T>* BST<T>::Search(Node<T>* root, T data) {
    if (root == nullptr || root->data == data) {
        return root;
    } else {
        if (data < root->data) {
            return Search(root->left, data);
        } else {
            return Search(root->right, data);
        }
    }
}

template <typename T>
Node<T>* BST<T>::Find_Max(Node<T>* root) {
    if (root == nullptr) {
        return nullptr;
    } else if (root->right == nullptr) {
        return root;
    } else {
        return Find_Max(root->right);
    }
}

template <typename T>
Node<T>* BST<T>::Find_Min(Node<T>* root) {
    if (root == nullptr) {
        return nullptr;
    } else if (root->left == nullptr) {
        return root;
    } else {
        return Find_Min(root->left);
    }
}

template <typename T>
Node<T>* BST<T>::Delete(Node<T>* root, T data) {
    if (root == nullptr) {
        cout << "Element not in tree!" << endl;
        return root;
    } else if (data < root->data) {
        root->left = Delete(root->left, data);
    } else if (data > root->data) {
        root->right = Delete(root->right, data);
    } else {
        if (root->left && root->right) {
            Node<T>* temp = Find_Max(root->left);
            root->data = temp->data;
            root->left = Delete(root->left, temp->data);
        } else {
            Node<T>* temp = root;
            if (root->left == nullptr) {
                root = root->right;
            } else if (root->right == nullptr) {
                root = root->left;
            }
            delete temp;
        }
    }
    return root;
}

template <typename T>
int BST<T>::count_leaves(Node<T>* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return count_leaves(root->left) + count_leaves(root->right);
}

template <typename T>
int BST<T>::count_nodes(Node<T>* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

template <typename T>
T BST<T>::sum_nodes(Node<T>* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->data + sum_nodes(root->left) + sum_nodes(root->right);
}

template <typename T>
T BST<T>::sum_leaf_nodes(Node<T>* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return root->data;
    }
    return sum_leaf_nodes(root->left) + sum_leaf_nodes(root->right);
}

template <typename T>
int BST<T>::height(Node<T>* root) {
    if (root == nullptr) {
        return -1; 
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    return 1 + max(left_height, right_height);
}

template <typename T>
int BST<T>::find_depth(Node<T>* root, T data, int depth) {
    if (root == nullptr) {
        return -1; 
    }
    if (root->data == data) {
        return depth;
    }
    if (data < root->data) {
        return find_depth(root->left, data, depth + 1);
    } else {
        return find_depth(root->right, data, depth + 1);
    }
}

template <typename T>
bool BST<T>::is_balanced(Node<T>* root) {
    if (root == nullptr) {
        return true;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    
    if (abs(left_height - right_height) <= 1 && is_balanced(root->left) && is_balanced(root->right)) {
        return true;
    }
    return false;
}

template <typename T>
void BST<T>::display_in_order(Node<T>* root) {
    if (root == nullptr) {
        return;
    }
    display_in_order(root->left);
    cout << root->data << " ";
    display_in_order(root->right);
}

int main() {
    BST<int> tree; 
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);
    
    cout << "In-order display: ";
    tree.display_in_order(tree.root);
    cout << endl;
    
    cout << "Total nodes: " << tree.count_nodes(tree.root) << endl;
    cout << "Leaf nodes: " << tree.count_leaves(tree.root) << endl;
    cout << "Sum of nodes: " << tree.sum_nodes(tree.root) << endl;
    cout << "Sum of leaf nodes: " << tree.sum_leaf_nodes(tree.root) << endl;
    cout << "Height of the tree: " << tree.height(tree.root) << endl;
    
    int data = 60;
    int depth = tree.find_depth(tree.root, data);
    if (depth != -1) {
        cout << "Depth of node with value " << data << ": " << depth << endl;
    } else {
        cout << "Node with value " << data << " not found." << endl;
    }
    
    cout << "Is the tree balanced? " << (tree.is_balanced(tree.root) ? "Yes" : "No") << endl;
    
    return 0;
}
