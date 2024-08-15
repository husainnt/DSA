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
    void insertAtStart(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        size++;
    }

    void insertAtEnd(int data)
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
    void reverse(Node *current, Node *prev)
    {
        // Base case: if current is nullptr, the end of the list is reached
        if (current == nullptr)
        {
            head = prev;
            return;
        }

        // Store the next node
        Node *next = current->next;

        // Reverse the current node's pointer
        current->next = prev;

        // Recur for the next node with the current node as the previous
        reverse(next, current);
    }
};