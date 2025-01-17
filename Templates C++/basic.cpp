#include <iostream>
using namespace std;
template <typename T>
T add(T x, T y)
{
    return (x + y);
}
int main()
{
    int x = add(44, 2);
    cout << x;
    return 0;
}