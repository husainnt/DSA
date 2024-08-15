#include <iostream>
using namespace std;
class stack
{
public:
    int *arr;
    int top;
    int size;
    stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int value)
    {
        arr[++top] = value;
    }
    void pop()
    {
        arr[--top];
    }
    int peek()
    {
        return arr[top];
    }
    void empty()
    {
        if (top >= 0)
        {
            cout << "Stack is not empty" << endl;
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
    }
};
int main()
{
    stack s(5);
    s.push(3);
    s.push(4);
    s.push(7);
    s.pop();
    cout << s.peek();
    return 0;
}