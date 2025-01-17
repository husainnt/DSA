#include <iostream>
#include <stack>
using namespace std;

bool ispalindrome(const string &str)
{
    stack<char> st;

    // Push all characters onto the stack
    for (int i = 0; i < str.length(); i++)
    {
        st.push(str[i]);
    }

    // Compare characters with the top of the stack
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != st.top())
        {
            return false; // Not a palindrome
        }
        st.pop();
    }

    return true; // It's a palindrome
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (ispalindrome(str))
    {
        cout << str << " is a palindrome." << endl;
    }
    else
    {
        cout << str << " is not a palindrome." << endl;
    }

    return 0;
}
