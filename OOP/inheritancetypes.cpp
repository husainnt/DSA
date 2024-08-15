#include <iostream>
using namespace std;
class parent1
{
public:
    parent1() // default constructor
    {
        cout << "parent1 class" << endl;
    }
};
class parent2
{
public:
    parent2() // default constructor
    {
        cout << "parent2 class" << endl;
    }
};
class child : public parent1, public parent2
{
public:
    child()
    {
        cout << "child class" << endl;
    }
};
class grandchild : public child // multi level inheritance
{
public:
    grandchild()
    {
        cout << "grandchild class";
    }
};

int main()
{
    child c;
}
