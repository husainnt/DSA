// Hussain Tahir, 22i - 1838, Sec : B, OOP A - 04
#include <iostream>
#include <string>
#include "LinkedList.h"

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
