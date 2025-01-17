/*
 * Assignment #: 1
 * Name: Hussain Tahir
 * Roll #: 22i-1838
 * Section: A
 * Program Description:
 * My code has both of its functions working as described in the Assignment instructions.
 * My code is performing the following tasks:
 * 1. Displaying all the data from the text file in alphabetical order (sorted).
 * 2. Taking a word as an input and returning the text where the word is present.
 * Additionally, I have also used a copy constructor, destructor and overloaded the assignment operator as discussed in class for good programming practices.
 * I have used templates to keep my code generic, along with recursion in the functions.
 * Note: As I use VSCode, the compiler gives no error but I am not aware of any errors if compiled on DevC++ or any other code editor/IDE.
 */
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *prev;
    Node<T> *next;

    Node(T data);
};

template <typename T>
Node<T>::Node(T data) : data(data), prev(nullptr), next(nullptr) {}

template <typename T>
class Linkedlist
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Linkedlist();
    ~Linkedlist();
    Linkedlist(const Linkedlist &obj);
    Linkedlist &operator=(const Linkedlist &obj);

    void insertathead(T data);
    void insertattail(T data);
    void insert_at_correct_pos(T data);
    bool searchbyword(const T &text, const T &word, int idx = 0);
    void displaystr(const T &word);
    void display();

private:
    Node<T> *customInsert(Node<T> *curr, T data);
};

template <typename T>
Linkedlist<T>::Linkedlist() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
Linkedlist<T>::~Linkedlist()
{
    Node<T> *curr = head;
    while (curr != nullptr)
    {
        Node<T> *temp = curr;
        curr = curr->next;
        delete temp;
    }
}

template <typename T>
Linkedlist<T>::Linkedlist(const Linkedlist &obj) : head(nullptr), tail(nullptr), size(0)
{
    Node<T> *curr = obj.head;
    while (curr != nullptr)
    {
        insertattail(curr->data);
        curr = curr->next;
    }
}

template <typename T>
Linkedlist<T> &Linkedlist<T>::operator=(const Linkedlist &obj)
{
    if (this == &obj)
    {
        return *this;
    }

    Node<T> *curr = head;
    while (curr != nullptr)
    {
        Node<T> *temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = tail = nullptr;
    size = 0;

    Node<T> *currObj = obj.head;
    while (currObj != nullptr)
    {
        insertattail(currObj->data);
        currObj = currObj->next;
    }
    return *this;
}

template <typename T>
void Linkedlist<T>::insertathead(T data)
{
    Node<T> *temp = new Node<T>(data);
    if (head == nullptr)
    {
        head = tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    size++;
}

template <typename T>
void Linkedlist<T>::insertattail(T data)
{
    Node<T> *temp = new Node<T>(data);
    if (head == nullptr)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    size++;
}

template <typename T>
Node<T> *Linkedlist<T>::customInsert(Node<T> *curr, T data)
{
    Node<T> *temp = new Node<T>(data);

    if (curr == nullptr)
    {
        return temp;
    }
    else if (data <= curr->data)
    {
        temp->next = curr;
        if (curr->prev != nullptr)
        {
            curr->prev->next = temp;
        }
        temp->prev = curr->prev;
        curr->prev = temp;
        return temp;
    }
    else
    {
        Node<T> *nextNode = customInsert(curr->next, data);
        curr->next = nextNode;
        nextNode->prev = curr;
        return curr;
    }
}

template <typename T>
void Linkedlist<T>::insert_at_correct_pos(T data)
{
    if (head == nullptr)
    {
        head = customInsert(head, data);
    }
    else if (data < head->data)
    {
        head = customInsert(head, data);
    }
    else
    {
        head = customInsert(head, data);

        if (tail == nullptr || tail->next != nullptr)
        {
            tail = head;
            while (tail->next != nullptr)
            {
                tail = tail->next;
            }
        }
    }
    size++;
}

template <typename T>
bool Linkedlist<T>::searchbyword(const T &text, const T &word, int idx)
{
    int text_length = text.length();
    int word_length = word.length();

    if (word_length > text_length - idx)
    {
        return false;
    }

    if (word_length == 0)
    {
        return true;
    }

    bool found = true;
    for (int i = 0; i < word_length; ++i)
    {
        if (text[idx + i] != word[i])
        {
            found = false;
            break;
        }
    }

    if (found)
    {
        return true;
    }

    return searchbyword(text, word, idx + 1);
}

template <typename T>
void Linkedlist<T>::displaystr(const T &word)
{
    Node<T> *curr = head;
    bool found = false;

    while (curr != nullptr)
    {
        if (searchbyword(curr->data, word))
        {
            cout << curr->data << endl;
            found = true;
        }
        curr = curr->next;
    }

    if (!found)
    {
        cout << "No such word exists in the text file." << endl;
    }
}

template <typename T>
void Linkedlist<T>::display()
{
    Node<T> *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    Linkedlist<string> l1;
    int ch;
    string input;

    ifstream file("Quran-verses.txt");

    string verse;
    while (getline(file, verse))
    {
        l1.insert_at_correct_pos(verse);
    }
    file.close();

    while (true)
    {
        cout << "Menu:" << endl;
        cout << "1. Display verses in alphabetical order" << endl;
        cout << "2. Search for a word in the file" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        cin.ignore();

        switch (ch)
        {
        case 1:
            cout << "Verses sorted alphabetically are: " << endl;
            l1.display();
            break;

        case 2:
            cout << "Enter a word (case-sensitive): ";
            getline(cin, input);

            if (input.length() == 1)
            {
                cout << "Please enter a word, not a alphabet." << endl;
            }
            else
            {
                cout << "Verses that contain '" << input << "':" << endl;
                l1.displaystr(input);
            }
            break;

        case 3:
            cout << "Exiting program." << endl;
            return -1;
        }
    }

    return 0;
}
