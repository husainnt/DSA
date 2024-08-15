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

    ~stack()
    {
        delete[] arr;
    }

    void push(int value)
    {
        if (top < size - 1)
        {
            arr[++top] = value;
        }
        else
        {
            cout << "Stack overflow!" << endl;
        }
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack underflow!" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty!" << endl;
            return -1; // Return an invalid value indicating an error
        }
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

    void display()
    {
        cout << "Elements in stack are: ";
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int stacksize()
    {
        return top + 1;
    }

    void deletemid()
    {
        if (top < 0)
        {
            cout << "Stack is empty, nothing to delete." << endl;
            return;
        }

        int mid = top / 2;

        for (int i = mid; i < top; i++)
        {
            arr[i] = arr[i + 1];
        }

        top--;
    }
};

int main()
{
    stack s(5);
    s.push(3);
    s.push(4);
    s.push(7);
    s.push(6);
    s.push(8);
    s.display();
    cout << "Size of stack: " << s.stacksize() << endl;

    s.deletemid();
    s.display();

    return 0;
}
