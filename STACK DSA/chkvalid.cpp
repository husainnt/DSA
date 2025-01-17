#include <iostream>
#include <stack>
using namespace std;

bool isValidParenthesis(const string &str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i]; // Access each character in the string

        // If it's an opening bracket, push it to the stack
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        // If it's a closing bracket, check for matching opening bracket
        else if (c == ')' || c == '}' || c == ']')
        {
            if (st.empty())
            {
                return false; // No matching opening bracket
            }
            char top = st.top();
            st.pop();

            // Check if the popped bracket matches the closing one
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
            {
                return false; // Mismatched bracket
            }
        }
    }

    // If stack is empty, all opening brackets were matched
    return st.empty();
}

int main()
{
    string str;
    cout << "Enter a string of parentheses: ";
    cin >> str;

    if (isValidParenthesis(str))
    {
        cout << "The parentheses are valid." << endl;
    }
    else
    {
        cout << "The parentheses are not valid." << endl;
    }

    return 0;
}
