#include <iostream>
#include <string.h>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *link;
    Node(T data)
    {
        this->data = data;
        this->link = nullptr;
    }
};

template <class T>
class Linkedlist
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Linkedlist()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    void insert_Athead(T data)
    {
        Node<T> *temp = new Node<T>(data);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->link = head;
            head = temp;
        }
        size++;
    }

    void insert_Attail(T data)
    {
        Node<T> *temp = new Node<T>(data);
        if (tail == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->link = temp;
            tail = temp;
        }
        size++;
    }

    void print()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
        cout << endl;
    }
};

int main()
{
    Linkedlist<int> l1;
    l1.insert_Attail(10);
    l1.insert_Attail(20);
    l1.insert_Attail(30);
    l1.insert_Attail(40);
    l1.insert_Attail(50);
    cout << "Displaying values for linkedlist of type integer: " << endl;
    l1.print();
    Linkedlist<string> l2;
    l2.insert_Attail("This");
    l2.insert_Attail("is");
    l2.insert_Attail("a");
    l2.insert_Attail("Linked");
    l2.insert_Attail("List");
    cout << "Displaying values for linkedlist of type string: " << endl;
    l2.print();
    return 0;
}
