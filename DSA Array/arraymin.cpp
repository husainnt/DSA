#include <iostream>
using namespace std;

const int max_size = 5;

void input(int arr[]);
int minimum(const int arr[]);

void input(int arr[])
{
    for (int i = 0; i < max_size; i++)
    {
        cin >> arr[i];
    }
}

int minimum(const int arr[])
{
    int min = arr[0];

    for (int i = 1; i < max_size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    int arr[max_size];
    cout << "Enter elements of array:" << endl;
    input(arr);
    cout << "Minimum element of array is: " << minimum(arr) << endl;
    return 0;
}
