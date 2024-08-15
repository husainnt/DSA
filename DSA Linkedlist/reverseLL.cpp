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
    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current != nullptr)
        {
            // Store the next node
            next = current->next;

            // Reverse the current node's pointer
            current->next = prev;

            // Move pointers one position ahead
            prev = current;
            current = next;
        }

        // Finally, update the head to point to the new first node
        head = prev;
    }
};