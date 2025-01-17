#include <iostream>
#include <queue>

using namespace std;

// Function to reverse the queue using recursion
void reverseQueue(queue<int> &q)
{
    // Base case: if the queue is empty, return
    if (q.empty())
    {
        return;
    }

    // Get the front element of the queue
    int front = q.front();
    q.pop();

    // Recursively reverse the remaining queue
    reverseQueue(q);

    // Push the front element at the end of the reversed queue
    q.push(front);
}

int main()
{
    // Create a queue and push some elements
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // Print the original queue
    cout << "Original Queue: ";
    queue<int> temp = q; // Copy the queue to print without modifying it
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // Reverse the queue using recursion
    reverseQueue(q);

    // Print the reversed queue
    cout << "Reversed Queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
