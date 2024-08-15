#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Student
{
public:
    std::string firstName;
    std::string CNIC;
    int rollNo;
    double cgpa;
    std::string program;
    std::string phone;
    Student *next;

    Student(std::string fName, std::string cnic, int rNo, double gpa, std::string prog, std::string ph)
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
    Student *head;
    Student *tail; // Pointer to the last node

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert(std::string fName, std::string cnic, int rNo, double gpa, std::string prog, std::string ph)
    {
        Student *new_student = new Student(fName, cnic, rNo, gpa, prog, ph);
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
        //  updateFile(new_student);
    }

    void insert2(std::string fName, std::string cnic, int rNo, double gpa, std::string prog, std::string ph)
    {
        Student *new_student = new Student(fName, cnic, rNo, gpa, prog, ph);
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
        updateFile(new_student);
    }

    void printList()
    {
        Student *current_student = head;
        while (current_student != nullptr)
        {
            std::cout << "Name: " << current_student->firstName << std::endl;
            std::cout << "CNIC: " << current_student->CNIC << std::endl;
            std::cout << "Roll No: " << current_student->rollNo << std::endl;
            std::cout << "CGPA: " << current_student->cgpa << std::endl;
            std::cout << "Program: " << current_student->program << std::endl;
            std::cout << "Phone: " << current_student->phone << std::endl
                      << std::endl;
            current_student = current_student->next;
        }
    }

    void findStudent(int rollNo)
    {
        Student *current_student = head;
        while (current_student != nullptr)
        {
            if (current_student->rollNo == rollNo)
            {
                std::cout << "Name: " << current_student->firstName << std::endl;
                std::cout << "CNIC: " << current_student->CNIC << std::endl;
                std::cout << "Roll No: " << current_student->rollNo << std::endl;
                std::cout << "CGPA: " << current_student->cgpa << std::endl;
                std::cout << "Program: " << current_student->program << std::endl;
                std::cout << "Phone: " << current_student->phone << std::endl
                          << std::endl;
                return;
            }
            current_student = current_student->next;
        }
        std::cout << "Student with Roll No " << rollNo << " not found." << std::endl;
    }

    void addStudent()
    {
        std::string fName, cnic, prog, ph;
        int rNo;
        double gpa;
        std::cout << "Enter First Name: ";
        std::cin >> fName;
        std::cout << "Enter CNIC: ";
        std::cin >> cnic;
        std::cout << "Enter Roll No: ";
        std::cin >> rNo;
        std::cout << "Enter CGPA: ";
        std::cin >> gpa;
        std::cout << "Enter Program: ";
        std::cin >> prog;
        std::cout << "Enter Phone: ";
        std::cin >> ph;
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
            std::cout << "Student with Roll No " << rollNo << " not found." << std::endl;
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
        std::cout << "Student with Roll No " << rollNo << " deleted successfully." << std::endl;

        // deletefromfile(rollnumver):
    }

    void changeRollNoByName(const std::string &name, int newRollNo)
    {
        Student *current_student = head;
        while (current_student != nullptr)
        {
            if (current_student->firstName == name)
            {
                current_student->rollNo = newRollNo;
                std::cout << "Roll No for " << name << " changed to " << newRollNo << std::endl;
            }
            current_student = current_student->next;
        }
    }

    void updateFile(Student *new_student)
    {
        std::ofstream file("Student.txt", std::ios_base::out | std::ios_base::app); // Truncate existing content
        if (!file.is_open())
        {
            std::cerr << "Error: Could not open file for writing." << std::endl;
            return;
        }
        file << new_student->firstName << "\t" << new_student->CNIC << "\t" << new_student->rollNo << "\t"
             << new_student->cgpa << "\t" << new_student->program << "\t" << new_student->phone << std::endl;
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
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string fName, cnic, prog, ph;
        int rNo;
        double gpa;

        if (iss >> fName >> cnic >> rNo >> gpa >> prog >> ph)
        {
            studentList.insert(fName, cnic, rNo, gpa, prog, ph);
        }
    }

    int choice;
    int rollNo;
    std::cout << "1. Find Student by Roll No\n"
              << "2. Add Student\n"
              << "3. Delete Student by Roll No\n"
              << "4. Show All Students\n"
              << "5. Exit\n";

    while (true)
    {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter Roll No: ";
            std::cin >> rollNo;
            studentList.findStudent(rollNo);
            break;
        case 2:
            studentList.addStudent();
            break;
        case 3:
            std::cout << "Enter Roll No to delete: ";
            std::cin >> rollNo;
            break;
        case 4:
            studentList.printList();
            break;
        case 5:
            return 0;
        default:
            std::cout << "Invalid choice. Please enter a number from 1 to 5." << std::endl;
        }
    }

    return 0;
}
