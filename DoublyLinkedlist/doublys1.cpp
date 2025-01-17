#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class Doublylinkedlist
{
    Node *head;
    Node *tail;
    int size;

public:
    Doublylinkedlist()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }
    void insert_Athead(int data)
    {
        Node *temp = new Node(data);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }
    void insert_Attail(int data)
    {
        Node *temp = new Node(data);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }
    void insert_Atpos(int data, int position)
    {
        if (position == 0)
        {
            insert_Athead(data);
        }
        else if (position == size)
        {
            insert_Attail(data);
        }
        else
        {
            Node *temp = new Node(data);
            Node *current = head;
            for (int i = 1; i < position; i++)
            {
                current = current->next;
            }
            temp->next = current->next;
            temp->prev = current;
            current->next = temp;

            size++;
        }
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
    Doublylinkedlist l1;
    l1.insert_Attail(1);
    l1.insert_Attail(2);
    l1.insert_Attail(3);
    l1.insert_Attail(6);
    l1.insert_Atpos(4, 3);
    l1.insert_Atpos(5, 4);
    cout << "Elements in Linkedlist are: ";
    l1.display();
    return 0;
}