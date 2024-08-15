#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Student
{
public:
    string firstName;
    string CNIC;
    int rollNo;
    double cgpa;
    string program;
    string phone;

    Student(string fName, string cnic, int rNo, double gpa, string prog, string ph)
        : firstName(fName), CNIC(cnic), rollNo(rNo), cgpa(gpa), program(prog), phone(ph) {}
};

template <typename T>
class LinkedList
{
private:
    class Node
    {
    public:
        Student student;
        Node *next;

        Node(string fName, string cnic, T rNo, double gpa, string prog, string ph)
            : student(fName, cnic, rNo, gpa, prog, ph), next(nullptr) {}
    };

    Node *head;
    Node *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

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

    void insert(string fName, string cnic, T rNo, double gpa, string prog, string ph)
    {
        Node *new_student = new Node(fName, cnic, rNo, gpa, prog, ph);
        if (head == nullptr)
        {
            head = new_student;
            tail = new_student;
        }
        else
        {
            tail->next = new_student;
            tail = new_student;
        }
    }

    void printList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << "Name: " << current->student.firstName << endl;
            cout << "CNIC: " << current->student.CNIC << endl;
            cout << "Roll No: " << current->student.rollNo << endl;
            cout << "CGPA: " << current->student.cgpa << endl;
            cout << "Program: " << current->student.program << endl;
            cout << "Phone: " << current->student.phone << endl
                 << endl;
            current = current->next;
        }
    }

    void findStudent(T rollNo)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->student.rollNo == rollNo)
            {
                cout << "Name: " << current->student.firstName << endl;
                cout << "CNIC: " << current->student.CNIC << endl;
                cout << "Roll No: " << current->student.rollNo << endl;
                cout << "CGPA: " << current->student.cgpa << endl;
                cout << "Program: " << current->student.program << endl;
                cout << "Phone: " << current->student.phone << endl
                     << endl;
                return;
            }
            current = current->next;
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
        Node *current = head;
        Node *prev = nullptr;
        while (current != nullptr && current->student.rollNo != rollNo)
        {
            prev = current;
            current = current->next;
        }
        if (current == nullptr)
        {
            cout << "Student with Roll No " << rollNo << " not found." << endl;
            return;
        }
        if (prev == nullptr)
        {
            head = current->next;
            if (head == nullptr) // If the only node is deleted, update tail pointer
                tail = nullptr;
        }
        else
        {
            prev->next = current->next;
            if (prev->next == nullptr) // If last node is deleted, update tail pointer
                tail = prev;
        }
        delete current;
        cout << "Student with Roll No " << rollNo << " deleted successfully." << endl;
    }

    void changeRollNoByName(const string &name, T newRollNo)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->student.firstName == name)
            {
                current->student.rollNo = newRollNo;
                cout << "Roll No for " << name << " changed to " << newRollNo << endl;
            }
            current = current->next;
        }
    }

    void updateFile()
    {
        ofstream file("Student.txt", ios_base::trunc);
        if (!file.is_open())
        {
            cerr << "Error: Could not open file for writing." << endl;
            return;
        }

        Node *current = head;
        while (current != nullptr)
        {
            file << current->student.firstName << "\t" << current->student.CNIC << "\t"
                 << current->student.rollNo << "\t" << current->student.cgpa << "\t"
                 << current->student.program << "\t" << current->student.phone << endl;
            current = current->next;
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
         << "5. Change Roll No by Name\n"
         << "6. Exit\n";

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
        {
            string name;
            int newRollNo;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter New Roll No: ";
            cin >> newRollNo;
            studentList.changeRollNoByName(name, newRollNo);
            break;
        }
        case 6:
            studentList.updateFile();
            return 0;

        default:
            cout << "Invalid choice. Please enter a number from 1 to 6." << endl;
        }
    }

    return 0;
}
