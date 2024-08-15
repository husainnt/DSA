// HUSSAIN TAHIR, 22i-1838, BS-EE, A1,SEC:B
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Student
{
    string first_name;
    string CNIC;
    int roll_no;
    float cgpa;
    string program;
    string phone;
};

const int MAX_STUDENTS = 100;

void customSwap(Student &a, Student &b)
{
    Student temp = a;
    a = b;
    b = temp;
}

void showAllStudents(const Student student_data[], int count)
{
    cout << "All Students:" << endl;
    for (int i = 0; i < count; ++i)
    {
        cout << "First Name: " << student_data[i].first_name << ", CNIC: " << student_data[i].CNIC << ", Roll No: " << student_data[i].roll_no
             << ", CGPA: " << student_data[i].cgpa << ", Program: " << student_data[i].program << ", Phone: " << student_data[i].phone << endl;
    }
}

void searchStudentByRollNo(const Student student_data[], int count, int roll_no)
{
    bool found = false;
    for (int i = 0; i < count; ++i)
    {
        if (student_data[i].roll_no == roll_no)
        {
            cout << "Student Found:" << endl;
            cout << "First Name: " << student_data[i].first_name << ", CNIC: " << student_data[i].CNIC << ", Roll No: " << student_data[i].roll_no
                 << ", CGPA: " << student_data[i].cgpa << ", Program: " << student_data[i].program << ", Phone: " << student_data[i].phone << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Student not found." << endl;
    }
}

void findStudentWithMaxCGPA(const Student student_data[], int count)
{
    float max_cgpa = student_data[0].cgpa;
    cout << "Student(s) with maximum CGPA:" << endl;
    for (int i = 0; i < count; ++i)
    {
        if (student_data[i].cgpa == max_cgpa)
        {
            cout << "First Name: " << student_data[i].first_name << ", CNIC: " << student_data[i].CNIC << ", Roll No: " << student_data[i].roll_no
                 << ", CGPA: " << student_data[i].cgpa << ", Program: " << student_data[i].program << ", Phone: " << student_data[i].phone << endl;
        }
    }
}

void sortStudentsByName(Student student_data[], int count)
{
    for (int i = 0; i < count - 1; ++i)
    {
        for (int j = 0; j < count - i - 1; ++j)
        {
            if (student_data[j].first_name > student_data[j + 1].first_name)
            {
                customSwap(student_data[j], student_data[j + 1]);
            }
        }
    }
    cout << "Students sorted by name:" << endl;
    showAllStudents(student_data, count);
}

void sortStudentsByCGPA(Student student_data[], int count)
{
    for (int i = 0; i < count - 1; ++i)
    {
        for (int j = 0; j < count - i - 1; ++j)
        {
            if (student_data[j].cgpa < student_data[j + 1].cgpa)
            {
                customSwap(student_data[j], student_data[j + 1]);
            }
        }
    }
    cout << "Students sorted by CGPA:" << endl;
    showAllStudents(student_data, count);
}

void addNewStudent(Student student_data[], int &count)
{
    if (count < MAX_STUDENTS)
    {
        cout << "Enter details for the new student:" << endl;
        cout << "First Name: ";
        cin >> student_data[count].first_name;
        cout << "CNIC: ";
        cin >> student_data[count].CNIC;
        cout << "Roll No: ";
        cin >> student_data[count].roll_no;
        cout << "CGPA: ";
        cin >> student_data[count].cgpa;
        cout << "Program: ";
        cin >> student_data[count].program;
        cout << "Phone: ";
        cin >> student_data[count].phone;

        ofstream file("Students.txt", ios::app);
        if (file.is_open())
        {
            file << student_data[count].first_name << "\t" << student_data[count].CNIC << "\t"
                 << student_data[count].roll_no << "\t" << student_data[count].cgpa << "\t"
                 << student_data[count].program << "\t" << student_data[count].phone << "\n";
            file.close();
            cout << "New student added successfully." << endl;
            count++;
        }
        else
        {
            cerr << "Error opening file for appending." << endl;
        }
    }
    else
    {
        cout << "Cannot add more students. Maximum limit reached." << endl;
    }
}

int main()
{
    Student student_data[MAX_STUDENTS];
    ifstream file("Student.txt");
    if (!file.is_open())
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int count = 0;
    string line;
    getline(file, line);

    while (count < MAX_STUDENTS && getline(file, line))
    {
        istringstream iss(line);
        if (!(iss >> student_data[count].first_name >> student_data[count].CNIC >> student_data[count].roll_no >> student_data[count].cgpa >> student_data[count].program))
        {
            cerr << "Error reading data from line " << count + 2 << endl;
            break;
        }
        getline(iss, student_data[count].phone);

        count++;
    }
    file.close();

    int choice;
    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Show all students" << endl;
        cout << "2. Search a student by Roll no" << endl;
        cout << "3. Find a student with maximum CGPA" << endl;
        cout << "4. Sort the student's data w.r.t name" << endl;
        cout << "5. Sort the student's data w.r.t cgpa" << endl;
        cout << "6. Add new student" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            showAllStudents(student_data, count);
            break;
        case 2:
        {
            int roll_no;
            cout << "Enter Roll no to search: ";
            cin >> roll_no;
            searchStudentByRollNo(student_data, count, roll_no);
        }
        break;
        case 3:
            findStudentWithMaxCGPA(student_data, count);
            break;
        case 4:
            sortStudentsByName(student_data, count);
            break;
        case 5:
            sortStudentsByCGPA(student_data, count);
            break;
        case 6:
            addNewStudent(student_data, count);
            break;
        case 7:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
