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
class Linkedlist
{
private:
    Node *head;
    int size;

public:
    Linkedlist()
    {
        this->head = nullptr;
        this->size = 0;
    }
    void insert_atstart(int data)
    {
        Node *temp = new Node(data);
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void insert_atend(int data)
    {
        Node *temp = new Node(data);
        if (head == nullptr)
        {
            head = temp;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = temp;
        }
        size++;
    }
    void insert_Atpos(int data, int pos)
    {
        Node *temp = new Node(data);

        // If inserting at the head (position 0)
        if (pos == 0)
        {
            insert_atstart(data);
            return;
        }

        Node *current = head;

        for (int i = 0; i < pos - 1; ++i)
        {
            if (current == nullptr)
                break;
            current = current->next;
        }

        // Insert the new node at the correct position
        temp->next = current->next;
        current->next = temp;
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
    l1.insert_atstart(4);
    l1.insert_atstart(2);
    l1.insert_atstart(1);
    l1.insert_Atpos(3, 2);
    l1.display();
    return 0;
}