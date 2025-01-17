#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Node {
public:
    char value;  
    Node* left;
    Node* right;

    Node(char val) : value(val), left(nullptr), right(nullptr) {}
};

class ExpressionTree {
private:
    Node* root;

public:
    ExpressionTree() : root(nullptr) {}


    void buildFromPostfix(const string& postfix);
    int evaluate() const {
        return evaluate(root);
    }
    void displayInfix() const;

private:
    void inorderTraversal(Node* node) const {
        if (node) {
            inorderTraversal(node->left);
            cout << node->value << " ";
            inorderTraversal(node->right);
        }
    }

    int evaluate(Node* root) const {
        if (root == nullptr) 
            return 0;  

        if (root->value >= '0' && root->value <= '9') {
            return root->value - '0'; 
        }

        
        int leftValue = evaluate(root->left);
        int rightValue = evaluate(root->right);

        switch (root->value) {
            case '+': 
                return leftValue + rightValue;
            case '-': 
                return leftValue - rightValue;
            case '*': 
                return leftValue * rightValue;
            case '/':
              leftValue / rightValue ; 
            default:
                return 0; 
        }
    }
};


void ExpressionTree::buildFromPostfix(const string& postfix) {
   stack<Node*> stk;
   for(int i=0;i<postfix.length();i++)
   {
    char ch=postfix[i];
   
   if(ch >='0'&&ch<='9')
   {
    stk.push(new Node(ch));
   }
   else
   {
    Node*right=stk.top();
    stk.pop();
    Node*left=stk.top();
    stk.pop();
    Node*newNode=new Node(ch);
    newNode->left=left;
    newNode->right=right;
    stk.push(newNode);
   }
   }
   root=stk.top();
}

void ExpressionTree::displayInfix() const {
    inorderTraversal(root);
    cout << endl;
}

int main() {
    string postfix = "23*54*+9-"; 

    ExpressionTree expTree;

    expTree.buildFromPostfix(postfix);
    cout << "Infix notation of the expression tree: ";
    expTree.displayInfix();

    int result = expTree.evaluate();
    cout << "Evaluation result: " << result << endl;

    return 0;
}
