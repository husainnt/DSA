#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int n;
    cout << "Enter a number to find the Fibonacci term: " << endl;
    cin >> n;

    if (n < 0)
    {
        cout << "Please enter a non-negative integer." << endl;
    }
    else
    {
        cout << n << "th term of the Fibonacci series is: " << fibonacci(n) << endl;
    }

    return 0;
}
