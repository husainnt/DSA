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
    Node *front;
    Node *rear;
    int size;

    // Helper function to clean up memory (used in destructor and assignment operator)
    void clear()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    // Helper function to copy data from another queue
    void copyFrom(const Queue &other)
    {
        Node *current = other.front;
        while (current != nullptr)
        {
            push(current->data);
            current = current->next;
        }
    }

public:
    // Default constructor
    Queue()
    {
        this->front = nullptr;
        this->rear = nullptr;
        this->size = 0;
    }

    // Copy constructor
    Queue(const Queue &other) : front(nullptr), rear(nullptr), size(0)
    {
        copyFrom(other);
    }

    // Assignment operator overloading
    Queue &operator=(const Queue &other)
    {
        if (this != &other) // Protect against self-assignment
        {
            clear();         // Clear existing data
            copyFrom(other); // Deep copy from the other queue
        }
        return *this;
    }

    // Destructor
    ~Queue()
    {
        clear();
    }

    void push(int data)
    {
        Node *temp = new Node(data);

        if (rear == nullptr)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
        size++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is empty, cannot pop!" << endl;
            return;
        }

        Node *temp = front;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;
        size--;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    int getSize() const
    {
        return size;
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node *current = front;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue elements are: ";
    q.display();

    cout << "Queue size: " << q.getSize() << endl;

    Queue q2 = q; // Copy constructor
    q2.pop();
    cout << "Copied queue after pop: ";
    q2.display();

    Queue q3;
    q3 = q; // Assignment operator
    cout << "Assigned queue elements: ";
    q3.display();

    return 0;
}
