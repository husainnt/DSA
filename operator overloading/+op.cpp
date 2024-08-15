#include <iostream>
using namespace std;

class Add
{
private:
    int a, b;

public:
    Add()
    {
        a = b = 0;
    }
    void input();
    Add operator+(Add p);
    void display();
};

void Add::input()
{
    cout << "Enter first number: " << endl;
    cin >> a;
    cout << "Enter second number: " << endl;
    cin >> b;
}

Add Add::operator+(Add p)
{
    Add temp;
    temp.a = p.a + a;
    temp.b = p.b + b;
    return temp;
}

void Add::display()
{
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

int main()
{
    Add x, y, z;
    cout << "Enter Values for data member X:" << endl;
    x.input();
    cout << "Enter Values for data member Y:" << endl;
    y.input();
    z = x + y;
    cout << "Data member values for X: " << endl;
    x.display();
    cout << "Data member values for Y: " << endl;
    y.display();
    cout << "Data member values for Z (X+Y): " << endl;
    z.display();

    return 0;
}
