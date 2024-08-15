#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

template <typename T>
class Node
{
public:
    string firstName;
    string CNIC;
    T rollNo;
    double cgpa;
    string program;
    string phone;
    Node<T> *next;

    Node(string fName, string cnic, T rNo, double gpa, string prog, string ph)
    {
        firstName = fName;
        CNIC = cnic;
        rollNo = rNo;
        cgpa = gpa;
        program = prog;
        phone = ph;
        next = nullptr;
    }
};

template <typename T>
class LinkedList
{
public:
    Node<T> *head;
    Node<T> *tail;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert(string fName, string cnic, T rNo, double gpa, string prog, string ph)
    {
        Node<T> *new_node = new Node<T>(fName, cnic, rNo, gpa, prog, ph);
        if (head == nullptr)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void printList()
    {
        Node<T> *current_node = head;
        while (current_node != nullptr)
        {
            cout << "Name: " << current_node->firstName << endl;
            cout << "CNIC: " << current_node->CNIC << endl;
            cout << "Roll No: " << current_node->rollNo << endl;
            cout << "CGPA: " << current_node->cgpa << endl;
            cout << "Program: " << current_node->program << endl;
            cout << "Phone: " << current_node->phone << endl
                 << endl;
            current_node = current_node->next;
        }
    }

    void findStudent(T rollNo)
    {
        Node<T> *current_node = head;
        while (current_node != nullptr)
        {
            if (current_node->rollNo == rollNo)
            {
                cout << "Name: " << current_node->firstName << endl;
                cout << "CNIC: " << current_node->CNIC << endl;
                cout << "Roll No: " << current_node->rollNo << endl;
                cout << "CGPA: " << current_node->cgpa << endl;
                cout << "Program: " << current_node->program << endl;
                cout << "Phone: " << current_node->phone << endl
                     << endl;
                return;
            }
            current_node = current_node->next;
        }
        cout << "Student with Roll No " << rollNo << " not found." << endl;
    }

    void addStudent()
    {
        string fName, cnic, prog, ph;
        T rNo;
        double gpa;
        cout << "Enter First Name: ";
        cin >> fName;
        cout << "Enter CNIC: ";
        cin >> cnic;
        cout << "Enter Roll No: ";
        cin >> rNo;
        cout << "Enter CGPA: ";
        cin >> gpa;
        cout << "Enter Program: ";
        cin >> prog;
        cout << "Enter Phone: ";
        cin >> ph;
        insert(fName, cnic, rNo, gpa, prog, ph);
    }

    void deleteStudent(T rollNo)
    {
        Node<T> *current_node = head;
        Node<T> *prev_node = nullptr;
        while (current_node != nullptr && current_node->rollNo != rollNo)
        {
            prev_node = current_node;
            current_node = current_node->next;
        }
        if (current_node == nullptr)
        {
            cout << "Student with Roll No " << rollNo << " not found." << endl;
            return;
        }
        if (prev_node == nullptr)
        {
            head = current_node->next;
            if (head == nullptr)
                tail = nullptr;
        }
        else
        {
            prev_node->next = current_node->next;
            if (prev_node->next == nullptr)
                tail = prev_node;
        }
        delete current_node;
        cout << "Student with Roll No " << rollNo << " deleted successfully." << endl;
    }

    void changeRollNoByName(const string &name, T newRollNo)
    {
        Node<T> *current_node = head;
        while (current_node != nullptr)
        {
            if (current_node->firstName == name)
            {
                current_node->rollNo = newRollNo;
                cout << "Roll No for " << name << " changed to " << newRollNo << endl;
            }
            current_node = current_node->next;
        }
    }

    void updateFile()
    {
        ofstream file("Student.txt", ios_base::out | ios_base::trunc);
        if (!file.is_open())
        {
            cerr << "Error: Could not open file for writing." << endl;
            return;
        }

        Node<T> *current_node = head;
        while (current_node != nullptr)
        {
            file << current_node->firstName << "\t" << current_node->CNIC << "\t"
                 << current_node->rollNo << "\t" << current_node->cgpa << "\t"
                 << current_node->program << "\t" << current_node->phone << endl;
            current_node = current_node->next;
        }
    }
};

int main()
{
    LinkedList<int> studentList;

    ifstream file("Student.txt");
    if (!file.is_open())
    {
        cerr << "Error opening file." << endl;
        return 1;
    }
    string line;

    while (getline(file, line))
    {
        istringstream iss(line);
        string fName, cnic, prog, ph;
        int rNo;
        double gpa;

        if (iss >> fName >> cnic >> rNo >> gpa >> prog >> ph)
        {
            studentList.insert(fName, cnic, rNo, gpa, prog, ph);
        }
    }

    int choice;
    int rollNo;
    cout << "1. Find Student by Roll No\n"
         << "2. Add Student\n"
         << "3. Delete Student by Roll No\n"
         << "4. Show All Students\n"
         << "5. Exit\n";

    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Roll No: ";
            cin >> rollNo;
            studentList.findStudent(rollNo);
            break;
        case 2:
            studentList.addStudent();
            break;
        case 3:
            cout << "Enter Roll No to delete: ";
            cin >> rollNo;
            studentList.deleteStudent(rollNo);
            break;
        case 4:
            studentList.printList();
            break;
        case 5:
            // Update file with current data
            studentList.updateFile();
            return 0;
        default:
            cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    }

    return 0;
}
