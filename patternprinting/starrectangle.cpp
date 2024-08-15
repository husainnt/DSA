#include <iostream>
using namespace std;
int main()
{
    int m;
    cout << "enter number of rows:";
    cin >> m;
    int n;
    cout << "enter number of cols:";
    cin >> n;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}