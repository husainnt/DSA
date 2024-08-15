#include <iostream>
#include <climits> // Include for INT_MIN
using namespace std;

const int size = 6;

void input(int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void largest_three(int arr[])
{
    int max1 = arr[0], max2 = INT_MIN, max3 = INT_MIN;

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = arr[i];
        }
        else if (arr[i] > max2)
        {
            max3 = max2;
            max2 = arr[i];
        }
        else if (arr[i] > max3)
        {
            max3 = arr[i];
        }
    }

    cout << "Largest 3 elements are:" << endl;
    cout << max1 << endl;
    cout << max2 << endl;
    cout << max3 << endl;
}

int main()
{
    int arr[size];
    cout << "Enter elements of array: " << endl;
    input(arr);
    largest_three(arr);
    return 0;
}
