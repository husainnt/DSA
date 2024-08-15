#include <iostream>
using namespace std;
class sum
{
public:
    void add(int a, int b)
    {
        int sum = a + b;
        cout << sum << endl;
    }
    void add(int a, int b, int c)
    {
        int sum = a + b + c;
        cout << sum << endl;
    }
    void add(float a, float b)
    {
        float sum = a + b;
        cout << sum << endl;
    }
};
int main()
{
    sum s;
    s.add(2, 8);
    s.add(2, 2, 2);
    s.add(float(2.2), float(2.2));
}