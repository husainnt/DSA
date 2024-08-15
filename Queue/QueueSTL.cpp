#include <iostream>
#include <queue> // Include the queue header
using namespace std;

int main()
{
    queue<int> q; // Create a queue of integers

    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    // Display the front element
    cout << "Front element is: " << q.front() << endl;

    // Dequeue an element
    q.pop();
    cout << "Front element after pop is: " << q.front() << endl;

    // Check if the queue is empty
    if (q.empty())
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "Queue is not empty!" << endl;
    }

    return 0;
}
