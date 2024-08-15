#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int capacity;
    int *array;

public:
    // Constructor to initialize the stack
    Stack(int size)
    {
        capacity = size;
        array = new int[capacity];
        top = -1;
    }

    // Destructor to clean up allocated memory
    ~Stack()
    {
        delete[] array;
    }

    // Push operation to add an element to the stack
    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack overflow, cannot push " << value << endl;
            return;
        }
        array[++top] = value;
    }

    // Pop operation to remove and return the top element of the stack
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow, cannot pop" << endl;
            return -1; // Return a sentinel value indicating error
        }
        return array[top--];
    }

    // Peek operation to return the top element without removing it
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty, nothing to peek" << endl;
            return -1; // Return a sentinel value indicating error
        }
        return array[top];
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull()
    {
        return top == capacity - 1;
    }

    // Function to print all the elements in the stack
    void print()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack stack(5); // Create a stack with capacity 5

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.print(); // Output: Stack elements: 10 20 30

    cout << "Top element is: " << stack.peek() << endl; // Output: Top element is: 30

    cout << "Popped element is: " << stack.pop() << endl; // Output: Popped element is: 30
    stack.print();                                        // Output: Stack elements: 10 20

    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70); // This should trigger stack overflow
    stack.print();  // Output: Stack elements: 10 20 40 50 60

    return 0;
}
