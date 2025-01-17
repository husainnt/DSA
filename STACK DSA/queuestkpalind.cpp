#include <iostream>
#include <stack>
#include <queue>
using namespace std;

bool is_palindrome(string str)
{
    stack<char> st;
    queue<char> q;

    for (int i = 0; i < str.length(); i++)
    {
        st.push(str[i]);
        q.push(str[i]);
    }

    while (!st.empty() && !q.empty())
    {
        char stop = st.top();
        char qfront = q.front();

        st.pop();
        q.pop();

        if (stop != qfront)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string str = "abba";
    if (is_palindrome(str))
        cout << str << " is a palindrome." << endl;
    else
        cout << str << " is not a palindrome." << endl;

    return 0;
}
