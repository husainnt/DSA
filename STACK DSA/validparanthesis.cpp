#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isvalid(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];
        // If opening bracket
        if (ch == '[' || ch == '{' || ch == '(')
        {
            s.push(ch);
        }
        // If closing bracket
        else if (ch == ']' || ch == '}' || ch == ')')
        {

            if ((ch == ']' && s.top() != '[') ||
                (ch == '}' && s.top() != '{') ||
                (ch == ')' && s.top() != '('))
            {
                return false;
            }
            s.pop();
        }
    }
    // If stack is empty, all opening brackets had matching closing brackets
    return s.empty();
}

int main()
{
    string exp = "[{()}]";
    if (isvalid(exp))
    {
        cout << "The expression is valid." << endl;
    }
    else
    {
        cout << "The expression is not valid." << endl;
    }
    return 0;
}
