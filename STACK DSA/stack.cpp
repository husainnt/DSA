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
        Node*temp=new Node();
        temp->data=value;
        

    }
};