#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Student
{
public:
    string first_name; // Changed to first_name to reflect the new input
    string cnic;       // Added CNIC
    int roll_no;
    float cgpa;
    string degree_program; // Changed to degree_program to reflect the new input
    string phone;          // Added phone

    // Updated constructor to accept the new parameters
    Student(string first_name, string cnic, int roll_no, float cgpa, string degree_program, string phone)
        : first_name(first_name), cnic(cnic), roll_no(roll_no), cgpa(cgpa), degree_program(degree_program), phone(phone) {}

    bool operator==(const Student &other) const
    {
        return this->roll_no == other.roll_no;
    }
};

class MyHashSet
{
public:
    vector<list<Student>> hashtable;
    int table_size;

    MyHashSet(int size = 1000)
    {
        this->table_size = size;
        hashtable.resize(size);
    }

    int hashFunction(int roll_no)
    {
        return roll_no % table_size;
    }

    void add(Student student)
    {
        int hashvalue = hashFunction(student.roll_no);
        int idx = hashvalue;

        if (!contains(student.roll_no))
        {
            hashtable[idx].push_back(student);
        }
        else
        {
            cout << "[INFO] Student with Roll No " << student.roll_no << " already exists!" << endl;
        }
    }

    void remove(int roll_no)
    {
        int hashvalue = hashFunction(roll_no);
        int idx = hashvalue;

        auto it = hashtable[idx].begin();
        while (it != hashtable[idx].end())
        {
            if (it->roll_no == roll_no)
            {
                hashtable[idx].erase(it);
                return;
            }
            ++it;
        }

        cout << "[WARNING] Student with Roll No " << roll_no << " not found!" << endl;
    }

    bool contains(int roll_no)
    {
        int hashvalue = hashFunction(roll_no);
        int idx = hashvalue;

        for (auto it = hashtable[idx].begin(); it != hashtable[idx].end(); ++it)
        {
            if (it->roll_no == roll_no)
            {
                return true;
            }
        }
        return false;
    }

    void displayAll()
    {
        for (int i = 0; i < table_size; ++i)
        {
            if (!hashtable[i].empty())
            {
                for (const auto &student : hashtable[i])
                {
                    cout << "First Name: " << student.first_name
                         << ", CNIC: " << student.cnic
                         << ", Roll No: " << student.roll_no
                         << ", CGPA: " << student.cgpa
                         << ", Degree Program: " << student.degree_program
                         << ", Phone: " << student.phone << endl;
                }
            }
        }
    }
};

// Updated readDataFromFile to parse the new text file format
void readDataFromFile(const string &filename, MyHashSet &myHashSet)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error: Cannot open file " << filename << endl;
        return;
    }

    string line;
    getline(file, line); // Skip the header line

    while (getline(file, line))
    {
        stringstream ss(line);
        string first_name, cnic, degree_program, phone;
        int roll_no;
        float cgpa;

        // Read each field from the line, assuming tab-separated values
        getline(ss, first_name, '\t');
        getline(ss, cnic, '\t');
        ss >> roll_no;
        ss.ignore(); // Ignore the tab character before CGPA
        ss >> cgpa;
        ss.ignore(); // Ignore the tab character before program
        getline(ss, degree_program, '\t');
        getline(ss, phone, '\t');

        Student student(first_name, cnic, roll_no, cgpa, degree_program, phone);
        myHashSet.add(student);
    }

    file.close();
}

int main()
{
    MyHashSet myHashSet;

    string filename = "Student.txt";
    readDataFromFile(filename, myHashSet);

    cout << "Displaying all students in the hash set:" << endl;
    myHashSet.displayAll();

    int roll_no_to_find = 3052;
    if (myHashSet.contains(roll_no_to_find))
    {
        cout << "Student with Roll No " << roll_no_to_find << " exists in the hash set." << endl;
    }
    else
    {
        cout << "Student with Roll No " << roll_no_to_find << " does not exist." << endl;
    }

    return 0;
}
