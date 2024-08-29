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
    LinkedList(const LinkedList &other) : head(nullptr), tail(nullptr), size(0)
    {
        Node *current = other.head;
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
    LinkedList &operator=(const LinkedList &other)
    {
        if (this != &other)
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
            Node *current = other.head;
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
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.display();

    LinkedList copyList = list; // Calls copy constructor
    copyList.display();

    LinkedList assignedList;
    assignedList = list; // Calls assignment operator
    assignedList.display();

    return 0;
}
