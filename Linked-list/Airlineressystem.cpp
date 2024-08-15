#include <iostream>
#include <string>
using namespace std;

class Passenger
{
public:
    string name;
    string address;
    int flightno;
};

struct Node
{
    Passenger passenger;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    // add a new passenger
    void addPassenger(const Passenger &p)
    {
        Node *newNode = new Node();
        newNode->passenger = p;
        newNode->next = head;
        head = newNode;
    }

    //  delete a passenger
    void deletePassenger(const string &name)
    {
        Node *current = head;
        Node *previous = nullptr;
        while (current != nullptr && current->passenger.name != name)
        {
            previous = current;
            current = current->next;
        }
        if (current != nullptr)
        {
            if (previous != nullptr)
            {
                previous->next = current->next;
            }
            else
            {
                head = current->next;
            }
            delete current;
        }
    }

    // display all
    void displayPassengers() const
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << "Name: " << current->passenger.name << ", Address: " << current->passenger.address << ", Flight No: " << current->passenger.flightno << endl;
            current = current->next;
        }
    }

    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
};

class Airline
{
private:
    string aircompany;
    LinkedList passengerList;

public:
    Airline(const string &company) : aircompany(company) {}

    void addPassenger(const Passenger &p)
    {
        passengerList.addPassenger(p);
    }

    void deletePassenger(const string &name)
    {
        passengerList.deletePassenger(name);
    }

    void displayPassengers() const
    {
        passengerList.displayPassengers();
    }
};

int main()
{
    Airline airline("ExampleAir");

    Passenger p1 = {"John Doe", "123 Main St", 1001};
    Passenger p2 = {"Jane Smith", "456 Oak St", 1002};

    airline.addPassenger(p1);
    airline.addPassenger(p2);

    cout << "Passenger List:" << endl;
    airline.displayPassengers();

    airline.deletePassenger("John Doe");

    cout << "Passenger List after deletion:" << endl;
    airline.displayPassengers();

    return 0;
}
