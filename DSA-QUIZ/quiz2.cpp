#include <iostream>
#include <queue>
using namespace std;

void queue_rvr(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }
    int front = q.front();
    q.pop();
    queue_rvr(q);
    q.push(front);
}

void display(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
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
    q1.push(6);

    cout << "Original queue is: " << endl;
    display(q1);

    queue_rvr(q1);

    cout << "Reversed queue is: " << endl;
    display(q1);

    return 0;
}
