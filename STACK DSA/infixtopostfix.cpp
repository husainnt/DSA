#include <iostream>
#include <stack>
#include <string> // Include for string operations

using namespace std;

// Function to check if a given character is an operator
bool isOperator(char c)
{
    // Return true if the character is an operator (+, -, *, /, ^)
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to define the precedence of operators
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return -1;
}

// Function to convert infix expression to postfix using a stack
string infixToPostfix(stack<char> &s, const string &infix)
{
    string postfix = ""; // Initialize an empty string to store the postfix expression

    for (char c : infix) // Loop through each character in the infix expression
    {
        // If the character is an operand (a-z, A-Z), add it to the postfix string
        if (isalpha(c))
        {
            postfix += c;
        }
        // If the character is '(', push it onto the stack
        else if (c == '(')
        {
            s.push(c);
        }
        // If the character is ')', pop from stack until '(' is found
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top(); // Add operator to postfix string
                s.pop();            // Remove operator from stack
            }
            if (!s.empty())
                s.pop(); // Pop '(' from the stack
        }
        // If the character is an operator
        else if (isOperator(c))
        {
            // Pop from the stack to postfix until the current operator has higher precedence
            while (!s.empty() && precedence(c) <= precedence(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c); // Push the current operator onto the stack
        }
    }

    // Pop all remaining operators from the stack
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix; // Return the converted postfix expression
}

int main()
{
    string infix_exp, postfix_exp;

    // Prompt user to enter an infix expression
    cout << "Enter an infix expression: ";
    cin >> infix_exp;

    // Declare an empty stack to be used in conversion
    stack<char> s;

    // Display the entered infix expression
    cout << "Infix expression: " << infix_exp << endl;

    // Convert the infix expression to postfix and store the result
    postfix_exp = infixToPostfix(s, infix_exp);

    // Display the resulting postfix expression
    cout << "Postfix expression is: " << postfix_exp << endl;

    return 0; // End of the program
}
