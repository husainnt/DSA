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

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    // Constructor
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Copy Constructor
    DoublyLinkedList(const DoublyLinkedList &other)
    {
        head = nullptr;
        tail = nullptr;
        size = 0;

        Node *current = other.head;
        while (current != nullptr)
        {
            insertAtEnd(current->data); // Insert copied data at the end
            current = current->next;
        }
    }

    // Destructor
    ~DoublyLinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Assignment Operator Overload
    DoublyLinkedList &operator=(const DoublyLinkedList &other)
    {
        if (this == &other)
            return *this; // Check for self-assignment

        // Deallocate existing list
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;

        // Copy the list from 'other'
        current = other.head;
        while (current != nullptr)
        {
            insertAtEnd(current->data);
            current = current->next;
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
            head->prev = temp;
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
            temp->prev = tail;
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
            temp->prev = current;
            if (current->next != nullptr)
            {
                current->next->prev = temp;
            }
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
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            delete temp;
        }
        else
        {
            for (int i = 0; i < position; i++)
            {
                temp = temp->next;
            }
            if (temp->prev != nullptr)
            {
                temp->prev->next = temp->next;
            }
            if (temp->next != nullptr)
            {
                temp->next->prev = temp->prev;
            }
            if (position == size - 1)
            {
                tail = temp->prev;
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

        while (last->next != nullptr)
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
        Node *current = head;
        Node *temp = nullptr;
        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr)
        {
            head = temp->prev;
        }
    }
};

int main()
{
    DoublyLinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.display();

    DoublyLinkedList copyList = list; // Copy constructor
    copyList.display();

    DoublyLinkedList assignedList;
    assignedList = list; // Assignment operator
    assignedList.display();

    return 0;
}
