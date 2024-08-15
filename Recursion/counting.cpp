#include <iostream>
using namespace std;

void counting(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << endl;
    counting(n - 1);
}

int main()
{
    int n;
    cout << "Enter a number: " << endl;
    cin >> n;
    cout << "Numbers that count down from " << n << " are: " << endl;
    counting(n);
    return 0;
}
