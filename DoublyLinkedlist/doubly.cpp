#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Linkedlist
{
public:
    node *head;
    int size;

    Linkedlist()
    {
        head = nullptr;
        size = 0;
    }

    void insert_athead(int data)
    {
        node *new_node = new node(data);
        if (head == nullptr)
        {
            head = new_node;
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
        size++;
    }

    void insert_atend(int data)
    {
        node *new_node = new node(data);
        if (head == nullptr)
        {
            head = new_node;
        }
        else
        {
            node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }
        size++;
    }

    void insert_atposition(int data, int position)
    {
        if (position < 0 || position > size)
        {
            cout << "Invalid position\n";
            return;
        }

        if (position == 0)
        {
            insert_athead(data);
        }
        else if (position == size)
        {
            insert_atend(data);
        }
        else
        {
            node *new_node = new node(data);
            node *current = head;
            for (int i = 1; i < position; i++)
            {
                current = current->next;
            }
            new_node->next = current->next;
            new_node->prev = current;
            if (current->next != nullptr)
            {
                current->next->prev = new_node;
            }
            current->next = new_node;
            size++;
        }
    }

    void delete_atposition(int position)
    {
        if (position < 0 || position >= size)
        {
            cout << "Invalid position\n";
            return;
        }

        node *temp = head;
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
            temp->prev->next = temp->next;
            if (temp->next != nullptr)
            {
                temp->next->prev = temp->prev;
            }
            delete temp;
        }
        size--;
    }

    int search(int data)
    {
        node *temp = head;
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

    int getsize()
    {
        return size;
    }

    void display()
    {
        node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayfirstmiddlelast()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        node *first = head;
        node *middle = head;
        node *last = head;
        int count = 0;

        while (last->next != nullptr && last->next->next != nullptr)
        {
            last = last->next->next;
            middle = middle->next;
            count++;
        }

        cout << "First Node: " << first->data << endl;
        if (count > 0)
        {
            cout << "Middle Node: " << middle->data << endl;
            cout << "Last Node: " << last->data << endl;
        }
        else
        {
            cout << "Middle and Last Node cannot be determined as list has less than two nodes.\n";
        }
    }

    void update_atposition(int data, int position)
    {
        if (position < 0 || position >= size)
        {
            cout << "Invalid position\n";
            return;
        }

        node *temp = head;
        for (int i = 0; i < position; i++)
        {
            temp = temp->next;
        }
        temp->data = data;
    }

    void reverse()
    {
        node *current = head;
        node *temp = nullptr;

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
    Linkedlist list;

    list.insert_atend(1);
    list.insert_atend(2);
    list.insert_atend(3);
    list.insert_atend(4);
    list.display();

    list.insert_athead(0);
    list.display();

    list.insert_atposition(5, 5);
    list.insert_atposition(10, 0);
    list.insert_atposition(7, 3);
    list.display();

    list.delete_atposition(6);
    list.delete_atposition(0);
    list.delete_atposition(5);
    list.delete_atposition(2);
    list.display();

    cout << "Size of list: " << list.getsize() << endl;

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

    list.displayfirstmiddlelast();

    list.update_atposition(15, 2);
    list.display();

    list.reverse();
    list.display();

    return 0;
}
