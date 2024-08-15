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

class LinkedList
{
private:
    Node *head;
    int size;

public:
    LinkedList()
    {
        head = nullptr;
        size = 0;
    }

    void add(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    void unique_sorted()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *current = head;
        while (current->next != nullptr)
        {
            if (current->data == current->next->data)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
                size--;
            }
            else
            {
                current = current->next;
            }
        }
    }

    void print()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    int getSize() const
    {
        return size;
    }
};

int main()
{
    LinkedList list;
    list.add(1);
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(3);
    list.add(4);

    cout << "Original list: ";
    list.print();

    list.unique_sorted();

    cout << "List after removing duplicates: ";
    list.print();

    return 0;
}
