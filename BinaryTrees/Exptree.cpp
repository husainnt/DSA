#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Define a TreeNode structure for the expression tree
struct TreeNode {
    char value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : value(val), left(nullptr), right(nullptr) {}
};

// Helper function to check if a character is a digit
bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

class ExpressionTree {
private:
    TreeNode* root;

    // Helper function to delete the tree and free memory
    void deleteTree(TreeNode* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    // Helper function to construct tree from postfix expression
    TreeNode* constructFromPostfix(const string& postfix) {
        stack<TreeNode*> stk;

        for (char ch : postfix) {
            if (isDigit(ch)) {
                stk.push(new TreeNode(ch));
            } else {
                if (stk.size() < 2) return nullptr;  // Error check for insufficient operands

                TreeNode* right = stk.top(); stk.pop();
                TreeNode* left = stk.top(); stk.pop();
                TreeNode* newNode = new TreeNode(ch);
                newNode->left = left;
                newNode->right = right;
                stk.push(newNode);
            }
        }
        return stk.size() == 1 ? stk.top() : nullptr;  // Error if there's more than one node left
    }

    // Helper function to construct tree from prefix expression
    TreeNode* constructFromPrefix(const string& prefix) {
        stack<TreeNode*> stk;

        for (auto it = prefix.rbegin(); it != prefix.rend(); ++it) {
            char ch = *it;
            if (isDigit(ch)) {
                stk.push(new TreeNode(ch));
            } else {
                if (stk.size() < 2) return nullptr;  // Error check for insufficient operands

                TreeNode* left = stk.top(); stk.pop();
                TreeNode* right = stk.top(); stk.pop();
                TreeNode* newNode = new TreeNode(ch);
                newNode->left = left;
                newNode->right = right;
                stk.push(newNode);
            }
        }
        return stk.size() == 1 ? stk.top() : nullptr;  // Error if there's more than one node left
    }

    // Recursive function to evaluate the expression tree
    int evaluate(TreeNode* node, bool& errorFlag) const {
        if (node == nullptr) {
            errorFlag = true;
            return 0;
        }

        // If it's a leaf node (operand)
        if (isDigit(node->value)) return node->value - '0';

        // Recursively evaluate left and right subtrees
        int leftVal = evaluate(node->left, errorFlag);
        int rightVal = evaluate(node->right, errorFlag);

        // Apply the operator
        switch (node->value) {
            case '+': return leftVal + rightVal;
            case '-': return leftVal - rightVal;
            case '*': return leftVal * rightVal;
            case '/': 
                if (rightVal == 0) {
                    errorFlag = true;  // Division by zero error
                    return 0;
                }
                return leftVal / rightVal;
            default: errorFlag = true; return 0;  // Unknown operator
        }
    }

public:
    // Constructor
    ExpressionTree() : root(nullptr) {}

    // Destructor
    ~ExpressionTree() {
        deleteTree(root);
    }

    // Build tree from postfix expression
    bool buildFromPostfix(const string& postfix) {
        root = constructFromPostfix(postfix);
        return root != nullptr;  // Return false if construction failed
    }

    // Build tree from prefix expression
    bool buildFromPrefix(const string& prefix) {
        root = constructFromPrefix(prefix);
        return root != nullptr;  // Return false if construction failed
    }

    // Evaluate the expression tree
    int evaluate() const {
        bool errorFlag = false;
        int result = evaluate(root, errorFlag);
        if (errorFlag) {
            cout << "Error evaluating expression.\n";
            return 0;
        }
        return result;
    }

    // Display inorder traversal of the expression tree (for infix format)
    void inorderTraversal(TreeNode* node) const {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->value << " ";
            inorderTraversal(node->right);
        }
    }

    // Display the expression tree in infix form
    void displayInfix() const {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    ExpressionTree expTree;

    string postfix = "23*54*+9-";  // Example postfix expression
    if (expTree.buildFromPostfix(postfix)) {
        cout << "Postfix Evaluation: " << expTree.evaluate() << endl;
        cout << "Infix Representation: ";
        expTree.displayInfix();
    } else {
        cout << "Invalid postfix expression\n";
    }

    string prefix = "-+*23*549";  // Example prefix expression
    if (expTree.buildFromPrefix(prefix)) {
        cout << "Prefix Evaluation: " << expTree.evaluate() << endl;
        cout << "Infix Representation: ";
        expTree.displayInfix();
    } else {
        cout << "Invalid prefix expression\n";
    }

    return 0;
}
