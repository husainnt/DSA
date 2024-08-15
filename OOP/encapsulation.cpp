#include <iostream>
using namespace std;
class ABC
{
    int x; // private by default
public:
    // to get value of x we create a set function and assign a var to x to store its value
    void set(int n)
    {
        x = n;
    }
    int get()
    {
        return x;
    }
};
int main()
{
    ABC obj1;
    obj1.set(3);
    cout << obj1.get() << endl;
}