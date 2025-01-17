#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Function to reverse a stack using a queue
void reverseStack(stack<int> &stk)
{
    queue<int> q;

    // Step 1: Pop all elements from stack and enqueue them
    while (!stk.empty())
    {
        q.push(stk.top());
        stk.pop();
    }

    // Step 2: Dequeue all elements from queue and push them back to stack
    while (!q.empty())
    {
        stk.push(q.front());
        q.pop();
    }
}

// Function to print the stack
void printStack(stack<int> stk)
{
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    cout << "Original stack: ";
    printStack(stk);

    // Reinitialize stack to preserve the original for printing
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);

    reverseStack(stk);

    cout << "Reversed stack: ";
    printStack(stk);

    return 0;
}
