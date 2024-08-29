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
    Node *tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    // Copy Constructor
    LinkedList(const LinkedList &obj) : head(nullptr), tail(nullptr), size(0)
    {
        Node *current = obj.head;
        while (current != nullptr)
        {
            insertAtEnd(current->data);
            current = current->next;
        }
    }

    // Destructor
    ~LinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Assignment Operator Overload
    LinkedList &operator=(const LinkedList &obj)
    {
        if (this != &obj)
        {
            // Delete existing nodes
            while (head != nullptr)
            {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;
            size = 0;

            // Copy nodes from the other list
            Node *current = obj.head;
            while (current != nullptr)
            {
                insertAtEnd(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void insertAtStart(int data)
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
            head = temp;
        }
        size++;
    }

    void insertAtEnd(int data)
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
            tail = temp;
        }
        size++;
    }

    void insertAtPosition(int data, int position)
    {
        if (position < 0 || position > size)
        {
            cout << "Invalid position\n";
            return;
        }

        if (position == 0)
        {
            insertAtStart(data);
        }
        else if (position == size)
        {
            insertAtEnd(data);
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
            current->next = temp;
            size++;
        }
    }

    void deleteAtPosition(int position)
    {
        if (position < 0 || position >= size)
        {
            cout << "Invalid position\n";
            return;
        }

        Node *temp = head;
        if (position == 0)
        {
            head = head->next;
            delete temp;
        }
        else
        {
            Node *prev = nullptr;
            for (int i = 0; i < position; i++)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            if (position == size - 1)
            {
                tail = prev;
            }
            delete temp;
        }
        size--;
    }

    int search(int data)
    {
        Node *temp = head;
        int position = 0;
        while (temp != nullptr)
        {
            if (temp->data == data)
            {
                return position;
            }
            temp = temp->next;
            position++;
        }
        return -1;
    }

    int getSize()
    {
        return size;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayFirstMiddleLast()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Node *first = head;
        Node *middle = head;
        Node *last = head;
        int count = 0;

        while (last != nullptr && last->next != nullptr)
        {
            last = last->next;
            if (count % 2 == 0)
            {
                middle = middle->next;
            }
            count++;
        }

        cout << "First Node: " << first->data << endl;
        cout << "Middle Node: " << middle->data << endl;
        cout << "Last Node: " << last->data << endl;
    }

    void updateAtPosition(int data, int position)
    {
        if (position < 0 || position >= size)
        {
            cout << "Invalid position\n";
            return;
        }

        Node *temp = head;
        for (int i = 0; i < position; i++)
        {
            temp = temp->next;
        }
        temp->data = data;
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;
        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
};

int main()
{
    LinkedList l1;
    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.insertAtEnd(3);
    l1.insertAtEnd(4);
    l1.display();

    LinkedList l2(l1); // Calls copy constructor
    l2.display();

    LinkedList l3;
    l3 = l1; // Calls assignment operator
    l3.display();

    return 0;
}
