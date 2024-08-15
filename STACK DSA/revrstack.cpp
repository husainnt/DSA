#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<int> &s, int value)
{
    // Create a temporary stack
    stack<int> tempStack;

    // Transfer elements from the original stack to the temporary stack
    while (!s.empty())
    {
        tempStack.push(s.top());
        s.pop();
    }

    // Push the new value onto the original stack (which is now empty)
    s.push(value);

    // Transfer elements back from the temporary stack to the original stack
    while (!tempStack.empty())
    {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

void reverse_stack(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }
    int n = s.top();
    s.pop();
    // recursive call
    reverse_stack(s);
    insertAtBottom(s, n);
}
void displayStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Stack elements in reversed: ";
    displayStack(st);
}