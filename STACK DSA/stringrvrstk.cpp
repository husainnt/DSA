#include <iostream>
#include <string>
#include <stack>
#include <cstring>

using namespace std;

void stringrvr(char *cc, int n)
{
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        st.push(cc[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cc[i] = st.top();
        st.pop();
    }
}

int main()
{
    char c[51];
    cout << "Enter a string: " << endl;
    cin.getline(c, 51);
    stringrvr(c, strlen(c));
    cout << "Reversed string: " << c << endl;

    return 0;
}
