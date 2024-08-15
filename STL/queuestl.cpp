#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> q;
    q.push(15);
    q.push(20);
    q.push(25);
    q.push(30);
    cout << "Size of queue is: " << q.size() << endl;
    cout << "Element at front in Queue is: " << q.front();
}