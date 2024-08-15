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
    Student *next;

    Student(string fName, string cnic, int rNo, double gpa, string prog, string ph)
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
    struct Node
    {
        T data;
        Node *next;
        Node(T d) : data(d), next(nullptr) {}
    };

    Node *head;
    Node *tail; // Pointer to the last node

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert(T data)
    {
        Node *new_node = new Node(data);
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

    void insert2(T data)
    {
        Node *new_node = new Node(data);
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
        updateFile(new_node);
    }

    void printList()
    {
        Node *current_node = head;
        while (current_node != nullptr)
        {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }
    void findStudent(int rollNo)
    {
        Student *current_student = head;
        while (current_student != nullptr)
        {
            if (current_student->rollNo == rollNo)
            {
                cout << "Name: " << current_student->firstName << endl;
                cout << "CNIC: " << current_student->CNIC << endl;
                cout << "Roll No: " << current_student->rollNo << endl;
                cout << "CGPA: " << current_student->cgpa << endl;
                cout << "Program: " << current_student->program << endl;
                cout << "Phone: " << current_student->phone << endl
                     << endl;
                return;
            }
            current_student = current_student->next;
        }
        cout << "Student with Roll No " << rollNo << " not found." << endl;
    }

    void addStudent()
    {
        string fName, cnic, prog, ph;
        int rNo;
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
        insert2(fName, cnic, rNo, gpa, prog, ph);
    }
    // deletefromfile(rollnumver):
    //{
    //.. code to delete from text file also
    //}

    void deleteStudent(int rollNo)
    {
        Student *current_student = head;
        Student *prev_student = nullptr;
        while (current_student != nullptr && current_student->rollNo != rollNo)
        {
            prev_student = current_student;
            current_student = current_student->next;
        }
        if (current_student == nullptr)
        {
            cout << "Student with Roll No " << rollNo << " not found." << endl;
            return;
        }
        if (prev_student == nullptr)
        {
            head = current_student->next;
            if (head == nullptr) // If the only node is deleted, update tail pointer
                tail = nullptr;
        }
        else
        {
            prev_student->next = current_student->next;
            if (prev_student->next == nullptr) // If last node is deleted, update tail pointer
                tail = prev_student;
        }
        delete current_student;
        cout << "Student with Roll No " << rollNo << " deleted successfully." << endl;

        // deletefromfile(rollnumver):
    }

    void changeRollNoByName(const string &name, int newRollNo)
    {
        Student *current_student = head;
        while (current_student != nullptr)
        {
            if (current_student->firstName == name)
            {
                current_student->rollNo = newRollNo;
                cout << "Roll No for " << name << " changed to " << newRollNo << endl;
            }
            current_student = current_student->next;
        }
    }

    void updateFile()
    {
        ofstream file("Student.txt", ios_base::out | ios_base::trunc); // Overwrite existing content
        if (!file.is_open())
        {
            cerr << "Error: Could not open file for writing." << endl;
            return;
        }

        Student *current_student = head;
        while (current_student != nullptr)
        {
            file << current_student->firstName << "\t" << current_student->CNIC << "\t"
                 << current_student->rollNo << "\t" << current_student->cgpa << "\t"
                 << current_student->program << "\t" << current_student->phone << endl;
            current_student = current_student->next;
        }
    }
};

int main()
{
    LinkedList<Student> studentList; // Use LinkedList<Student> instead of LinkedList<int>

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
            studentList.insert(Student(fName, cnic, rNo, gpa, prog, ph));
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
