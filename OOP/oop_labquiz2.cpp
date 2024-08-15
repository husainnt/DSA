#include <iostream>
#include <string>
using namespace std;

class patient
{
private:
    string name;
    int age;
    string gender;

public:
    void set(string name, int age, string gender);
    void input();
    void display();
};

void patient::set(string name, int age, string gender)
{
    this->name = name;
    this->age = age;
    this->gender = gender;
}

void patient::input()
{
    cout << "Enter name of the patient: ";
    cin >> name;
    cout << "Enter age of the patient: ";
    cin >> age;
    cout << "Enter gender of the patient: ";
    cin >> gender;
}

void patient::display()
{
    cout << "Patient info: " << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Gender: " << gender << endl;
}

class records : public patient
{
private:
    string health_cond;

public:
    void set_health_condition(string health_condition);
    void info();
    void display_res();
};

void records::set_health_condition(string health_condition)
{
    this->health_cond = health_condition;
}

void records::info()
{
    cout << "Enter health problem of patient: ";
    cin >> health_cond;
    input();
}

void records::display_res()
{
    cout << "Patient problem and info: " << endl;
    cout << "Health Condition: " << health_cond << endl;
    display();
}

int main()
{
    records r;
    r.info();
    cout << endl;
    r.display_res();
    return 0;
}
