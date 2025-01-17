#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int priority;
    Node *next;
    Node(int data, int priority)
    {
        this->data = data;
        this->priority = priority;
        this->next = nullptr;
    }
};

class PriorityQueue
{
private:
    Node *front; // This will be the head of the priority queue
    int size;

public:
    PriorityQueue()
    {
        this->front = nullptr;
        this->size = 0;
    }

    // Push according to priority
    void push(int data, int priority)
    {
        Node *temp = new Node(data, priority);

        if (front == nullptr || front->priority > priority)
        {
            // Insert at the front if the list is empty or the priority is higher
            temp->next = front;
            front = temp;
        }
        else
        {
            // Traverse and insert at the correct position
            Node *current = front;
            while (current->next != nullptr && current->next->priority <= priority)
            {
                current = current->next;
            }
            temp->next = current->next;
            current->next = temp;
        }
        size++;
    }

    // Pop the highest priority element
    void pop()
    {
        if (isEmpty())
        {
            cout << "Priority Queue is empty, cannot pop!" << endl;
            return;
        }

        Node *temp = front;
        front = front->next;
        delete temp;
        size--;
    }

    // Check if the priority queue is empty
    bool isEmpty() const
    {
        return size == 0;
    }

    // Return the size of the priority queue
    int getSize() const
    {
        return size;
    }

    // Display the priority queue
    void display()
    {
        if (isEmpty())
        {
            cout << "Priority Queue is empty!" << endl;
            return;
        }

        Node *current = front;
        while (current != nullptr)
        {
            cout << "[Data: " << current->data << ", Priority: " << current->priority << "] ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    PriorityQueue pq;

    pq.push(10, 3); // Lower priority number means higher priority
    pq.push(20, 1);
    pq.push(30, 2);

    cout << "Priority Queue elements are: ";
    pq.display();

    cout << "Priority Queue size: " << pq.getSize() << endl;

    pq.pop(); // Removes the element with highest priority (20)
    cout << "Priority Queue elements after pop: ";
    pq.display();

    cout << "Priority Queue size after pop: " << pq.getSize() << endl;

    return 0;
}
