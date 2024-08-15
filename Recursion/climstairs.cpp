#include <iostream>
using namespace std;
int distway(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return distway(n - 1) + distway(n - 2);
    }
}
int main()
{
    int n;
    cout << "Enter the steps of stairs: " << endl;
    cin >> n;
    cout << "Distinct ways of climbing the stairs with steps " << n << " are: " << distway(n);
    return 0;
}