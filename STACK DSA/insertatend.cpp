#include <iostream>
#include <stack>
using namespace std;

// Function to insert an element at the bottom of a stack without recursion
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

// Function to display the elements of the stack
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

    cout << "Original stack: ";
    displayStack(st); // Display the original stack

    insertAtBottom(st, 5);

    cout << "Stack after inserting 5 at the bottom: ";
    displayStack(st); // Display the modified stack

    return 0;
}
