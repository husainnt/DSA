#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(4);
    s.push(3);
    cout << "Top element in stack is: " << s.top() << endl;
    if (s.empty())
    {
        cout << "Stack is empty: " << endl;
    }
    else
    {
        cout << "Stack is not empty " << endl;
    }
    return 0;
}