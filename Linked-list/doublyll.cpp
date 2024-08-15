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
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
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

    // Function to update the data at a specific position in the doubly linked list
    void updateAtPosition(int data, int position)
    {
        if (position < 0 || position >= size) // Check if the position is valid
        {
            cout << "Invalid position\n";
            return;
        }

        Node *temp = head;                 // Start from the head of the list
        for (int i = 0; i < position; i++) // Traverse to the node at the given position
        {
            temp = temp->next;
        }
        temp->data = data; // Update the data of the node
    }

    // Function to reverse the doubly linked list
    void reverse()
    {
        Node *current = head;
        Node *temp = nullptr;
        while (current != nullptr)
        {
            temp = current->prev; // Swap prev and next pointers
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr)
        {
            head = temp->prev; // Update head to the new first node
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

    list.insertAtStart(0);
    list.display();

    list.insertAtPosition(5, 5);
    list.insertAtPosition(10, 0);
    list.insertAtPosition(7, 3);
    list.display();

    list.deleteAtPosition(6);
    list.deleteAtPosition(0);
    list.deleteAtPosition(5);
    list.deleteAtPosition(2);
    list.display();

    cout << "Size of list: " << list.getSize() << endl;

    int searchData = 2;
    int position = list.search(searchData);
    if (position != -1)
    {
        cout << "Found " << searchData << " at position " << position << endl;
    }
    else
    {
        cout << searchData << " not found\n";
    }

    list.displayFirstMiddleLast();

    list.updateAtPosition(15, 2); // Update data at position 2
    list.display();

    list.reverse(); // Reverse the doubly linked list
    list.display();

    return 0;
}
