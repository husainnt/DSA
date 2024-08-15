#include <iostream>
using namespace std;
class complex
{
public:
    int real;
    int imag;
    complex(int x, int y)
    {
        real = x;
        imag = y;
    }
    complex operator+(complex &c)
    {
        complex ans(0, 0);
        ans.real = real + c.real;
        ans.imag = imag + c.imag;
        return ans;
    }
};
int main()
{
    complex c1(1, 2);
    complex c2(1, 3);
    complex c3 = c1 + c2;
    cout << c3.real << " i" << c3.imag << endl;
}