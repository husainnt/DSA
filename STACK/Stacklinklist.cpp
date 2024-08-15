#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node *next;
};

// Stack class
class Stack
{
private:
    Node *top;
    int size;

public:
    // Constructor to initialize the stack
    Stack()
    {
        this->top = nullptr;
        this->size = 0;
    }

    // Destructor to clean up allocated memory
    ~Stack()
    {
        while (top != nullptr)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Push operation to add an element to the stack
    void push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Pop operation to remove and return the top element of the stack
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow, cannot pop" << endl;
            return -1; // Return a sentinel value indicating error
        }
        Node *temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        size--;
        return poppedValue;
    }

    // Peek operation to return the top element without removing it
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty, nothing to peek" << endl;
            return -1; // Return a sentinel value indicating error
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return top == nullptr;
    }

    // Get the current size of the stack
    int getSize()
    {
        return size;
    }

    // Function to print all the elements in the stack
    void print()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *current = top;
        cout << "Stack elements: ";
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
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.print(); // Output: Stack elements: 30 20 10

    cout << "Top element is: " << stack.peek() << endl; // Output: Top element is: 30

    cout << "Popped element is: " << stack.pop() << endl; // Output: Popped element is: 30
    stack.print();                                        // Output: Stack elements: 20 10

    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.print(); // Output: Stack elements: 60 50 40 20 10

    cout << "Stack size is: " << stack.getSize() << endl; // Output: Stack size is: 5

    return 0;
}
