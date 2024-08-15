#include <iostream>
using namespace std;

const int max_size = 5;

void input(int arr[]);
int sum(const int arr[]);

void input(int arr[])
{
    for (int i = 0; i < max_size; i++)
    {
        cin >> arr[i];
    }
}

int sum(const int arr[])
{
    int s = 0;

    for (int i = 0; i < max_size; i++)
    {
        s += arr[i];
    }
    return s;
}

int main()
{
    int arr[max_size];
    cout << "Enter elements of array:" << endl;
    input(arr);
    cout << "Sum of elements of array is: " << sum(arr) << endl;
    return 0;
}
