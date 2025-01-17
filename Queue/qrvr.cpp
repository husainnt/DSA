#include <iostream>
#include <queue>
using namespace std;

void rqueue(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int front = q.front();
    q.pop();
    rqueue(q);
    q.push(front);
}

void displayQueue(queue<int> q2)
{
    // Make a copy of the queue to avoid modifying the original
    while (!q2.empty())
    {
        cout << q2.front() << " ";
        q2.pop(); // Remove the element from the queue
    }
    cout << endl;
}

int main()
{
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);

    cout << "Elements in queue before reversing: ";
    displayQueue(q1);

    rqueue(q1);

    cout << "Elements in queue after reversing: ";
    displayQueue(q1);

    return 0;
}
