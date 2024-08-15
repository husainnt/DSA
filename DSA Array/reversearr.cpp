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
void reverse(int arr[])
{

    for (int i = size - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[size];
    cout << "Enter elements of array: " << endl;
    input(arr);
    cout << endl;
    cout << "Reversed array is: " << endl;
    reverse(arr);
}