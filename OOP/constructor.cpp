#include <iostream>
using namespace std;
class rectangle
{
public:
    int l;
    int b;
    rectangle() // default constructor. no argu passed
    {
        l = 0;
        b = 0;
    }
    rectangle(int x, int y) // parameterised constructor. argu passed
    {
        l = x;
        b = y;
    }
    rectangle(rectangle &r) // copy constructor-initialise an object by another object
    {
        l = r.l;
        b = r.b;
    }
};
int main()
{
    rectangle r1;
    cout << r1.l << " " << r1.b << endl;
    rectangle r2(3, 4);
    cout << r2.l << " " << r2.b << endl;
    rectangle r3 = r2;
    cout << r3.l << " " << r3.b << endl;
}