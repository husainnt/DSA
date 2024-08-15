#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue
{
private:
    Node *front; // Pointer to the front node
    Node *rear;  // Pointer to the rear node

public:
    // Constructor to initialize the queue
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Destructor to free allocated memory
    ~Queue()
    {
        while (front != nullptr)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Function to add an element to the queue
    void push(int data)
    {
        Node *newNode = new Node(data);
        if (rear == nullptr) // If the queue is empty
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to remove an element from the queue
    int pop()
    {
        if (front == nullptr) // If the queue is empty
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        else
        {
            int value = front->data;
            Node *temp = front;
            front = front->next;
            if (front == nullptr) // If the queue becomes empty after pop
            {
                rear = nullptr;
            }
            delete temp;
            return value;
        }
    }

    // Function to get the front element of the queue
    int peek()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        else
        {
            return front->data;
        }
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return (front == nullptr);
    }

    // Function to check if the queue is full (Not applicable for linked list)
    bool isFull()
    {
        return false; // A linked list queue is never full (unless memory is exhausted)
    }
};

int main()
{
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Front element is: " << q.peek() << endl;

    q.pop();
    cout << "Front element after pop is: " << q.peek() << endl;

    return 0;
}
