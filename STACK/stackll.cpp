#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Stack
{
private:
    Node *top;
    int size;

public:
    Stack()
    {
        this->top = top;
        this->size = 0;
    }
    void push(int value)
    {
        Node *temp = new Node();
        temp->data = value;
        temp->next = top;
        top = temp;
        size++;
    }
    int pop()
    {
        Node *temp = top;
        top = top->next;
        delete temp;
        size--;
    }
    int peek()
    {
        cout << top->data;
    }
    int getsize()
    {

        return size;
    }
    void print_stack()
    {
        Node *temp = top;
        cout << "Elements in the stack are: " << endl;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
int main()
{
    Stack s;
    s.push(3);
    s.push(4);
    s.push(8);
    s.pop();
    s.push(99);
    s.peek();
    cout << endl;
    cout << "Size of stack is: " << s.getsize() << endl;
    s.print_stack();
    return 0;
}