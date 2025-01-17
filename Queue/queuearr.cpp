#include <iostream>
using namespace std;
class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    Queue(int capacity)
    {
        arr = new int[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }
    void push(int data)
    {
        if (rear == size)
        {
            cout << "Queue is full!" << endl;
        }
        arr[rear] = data;
        rear++;
    }
    void pop()
    {
        front = -1;
        front++;
        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
    }
    int peek()
    {
        return arr[front];
    }
    bool isempty()
    {
        return (rear == size);
    }
};
int main()
{
    Queue q1(5);
    q1.push(1);
    q1.push(2);
    q1.push(3);

    cout << "Value at queue front is: " << q1.peek();
}