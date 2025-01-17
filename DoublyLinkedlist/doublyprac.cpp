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
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class Linkedlist
{
    Node *head;
    Node *tail;
    int size;

public:
    Linkedlist()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }
    ~Linkedlist() // destructor
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }
    Linkedlist(const Linkedlist &obj) // copy constructor
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
    Linkedlist &operator=(const Linkedlist &obj) // Assignment operator overloading
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
    void insertatposition(int data, int position)
    {
        if (position == 0)
        {
            insertathead(data);
            return;
        }
        else if (position == size)
        {
            insertattail(data);
            return;
        }
        Node *current = head;
        Node *temp = new Node(data);
        for (int i = 1; i < position; ++i)
        {
            current = current->next;
        }
        temp->next = current->next;
        temp->prev = current;
        if (current->next != nullptr)
        {
            current->next->prev = temp;
        }

        current->next = temp;
        size++;
    }

    int getsize()
    {
        return size;
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
    l1.insertathead(4);
    l1.insertathead(3);
    l1.insertathead(2);
    l1.insertathead(1);
    l1.insertatposition(5, 4);
    cout << "The values in the linked list are : ";
    l1.display();
    cout << endl;
    cout << "Size of linkedlist is: " << l1.getsize() << endl;
}