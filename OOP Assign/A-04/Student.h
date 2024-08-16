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
