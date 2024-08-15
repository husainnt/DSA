#include <iostream>
using namespace std;
const int size = 4;
void input(int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
void max_min(int arr[])
{
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << "maximum value is: " << max << endl;
    cout << "minimum value is: " << min << endl;
}
int main()
{
    int arr[size];
    cout << "Enter elements of array: " << endl;
    input(arr);
    cout << endl;
    max_min(arr);
    return 0;
}