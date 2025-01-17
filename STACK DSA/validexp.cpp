#include <iostream>
#include <stack>
using namespace std;
bool match(char opening, char closing)
{

    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}
bool chk(const string &str)
{
    stack<char> st;
    for (char ch : str)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
            if (st.empty() || !match(st.top(), ch))
            {
                return false;
            }
        st.pop();
    }
    return st.empty();
}
