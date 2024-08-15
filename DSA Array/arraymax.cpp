#include <iostream>
using namespace std;

const int max_size = 5;

void input(int arr[]);
int maximum(const int arr[]);

void input(int arr[])
{
    for (int i = 0; i < max_size; i++)
    {
        cin >> arr[i];
    }
}

int maximum(const int arr[])
{
    int max = arr[0];

    for (int i = 1; i < max_size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main()
{
    int arr[max_size];
    cout << "Enter elements of array:" << endl;
    input(arr);
    cout << "Maximum element of array is: " << maximum(arr) << endl;
    return 0;
}
