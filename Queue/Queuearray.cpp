#include <iostream>
using namespace std;

class Queue
{
private:
    int *arr;  // Pointer to the array for storing queue elements
    int front; // Index of the front element
    int rear;  // Index of the rear element
    int size;  // Maximum size of the queue

public:
    // Constructor to initialize the queue
    Queue(int capacity)
    {
        arr = new int[capacity];
        front = 0;
        rear = 0;
        size = capacity;
    }

    // Destructor to free allocated memory
    ~Queue()
    {
        delete[] arr;
    }

    // Function to add an element to the queue
    void push(int data)
    {
        if (rear == size)
        {
            cout << "Queue is full!" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    // Function to remove an element from the queue
    int pop()
    {
        if (front == rear)
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        else
        {
            int value = arr[front];
            for (int i = 0; i < rear - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            rear--;
            return value;
        }
    }

    // Function to get the front element of the queue
    int peek()
    {
        if (front == rear)
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return (front == rear);
    }

    // Function to check if the queue is full
    bool isFull()
    {
        return (rear == size);
    }
};

int main()
{
    Queue q(5); // Initialize queue with capacity of 5

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60); // This will show overflow message

    cout << "Front element is: " << q.peek() << endl;

    q.pop();
    cout << "Front element after pop is: " << q.peek() << endl;

    return 0;
}
