#include <iostream>
using namespace std;

int powerof2(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return 2 * powerof2(n - 1);
    }
}

int main()
{
    int n;
    cout << "Enter a number : " << endl;
    cin >> n;
    cout << "2 to the power of " << n << " is: " << powerof2(n) << endl;
    return 0;
}
