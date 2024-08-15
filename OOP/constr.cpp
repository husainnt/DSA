#include <iostream>
using namespace std;
class number
{
private:
    int x, y;

public:
    int a;
    number()//default constructor
    {
        x = 50;
        y = 70;
    }
    int avg();
};
int number::avg()
{
    cout << "Value of x is: " << x << endl;
    cout << " Value of y is: " << y << endl;
    int a = (x + y) / 2;
    cout << "average of x and y is : " << a << endl;
}
int main()
{
    number n1;
    n1.avg();
}