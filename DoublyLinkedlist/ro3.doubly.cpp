#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};
class Linkedlist
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    Linkedlist()
    {
        head = tail = nullptr;
        size = 0;
    }
    Linkedlist(const Linkedlist &obj)
    {
        head = tail = nullptr;
        size = 0;
        Node *current = obj.head;
        while (current != nullptr)
        {
            insertattail(current->data);
            current = current->next;
        }
    }
    Linkedlist &operator=(const Linkedlist &obj)
    {
        if (this == &obj)
        {
            return *this;
        }
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
        size = 0;
        current = obj.head;
        while (current != nullptr)
        {
            insertattail(current->data);
            current = current->next;
        }
        return *this;
    }
    void insertathead(int data)
    {
        Node *temp = new Node(data);
        if (head == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }
    void insertattail(int data)
    {
        Node *temp = new Node(data);
        if (head == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }
    void display()
    {
        Node *current = head;
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
    Linkedlist l1;
    l1.insertattail(1);
    l1.insertattail(2);
    l1.insertattail(3);
    l1.insertattail(4);
    Linkedlist l2(l1);
    cout << "Doubky Linkedlist l2 after calling copy constructor: ";
    l2.display();
    cout << endl;
    Linkedlist l3;
    l3 = l2;
    cout << "Doubly Linkedlist l3 after overlaoding assignment operator: ";
    l3.display();
}