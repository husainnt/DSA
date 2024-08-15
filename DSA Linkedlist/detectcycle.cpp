#include <iostream>
#include <map>
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

    // Function to detect a loop in the linked list
    bool detectLoop()
    {
        if (head == nullptr)
        {
            return false; // Return false if the list is empty
        }
        map<Node *, bool> visited;
        Node *temp = head;
        while (temp != nullptr)
        {
            // If we have already visited this node, there is a loop
            if (visited[temp])
            {
                return true;
            }
            // Mark this node as visited
            visited[temp] = true;
            temp = temp->next;
        }
        return false;
    }

    // Function to add a node to the linked list
    void append(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // Making head public for test purposes
    Node *getHead()
    {
        return head;
    }
};

int main()
{
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);

    // Creating a loop for testing
    list.getHead()->next->next->next = list.getHead();

    if (list.detectLoop())
    {
        cout << "Loop detected in the linked list." << endl;
    }
    else
    {
        cout << "No loop detected in the linked list." << endl;
    }

    return 0;
}
