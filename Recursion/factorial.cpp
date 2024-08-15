#include <iostream>
using namespace std;
int factorial(int n)
{
    // base case
    if (n == 0)
    {
        return 1;
    }
    // recursive realtion
    else
    {
        return n * factorial(n - 1);
    }
}
int main()
{
    int n;
    cout << "Enter a number to find the factorial of: " << endl;
    cin >> n;
    cout << "Factorial of " << n << " is: " << factorial(n);
    return 0;
}