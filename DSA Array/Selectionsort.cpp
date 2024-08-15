#include <iostream>
using namespace std;
const int size = 5;

void input(int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void SelSort(int arr[])
{
    for (int i = 0; i < size; i++)
    {
        int minidx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minidx])
            {
                minidx = j;
            }
        }
        swap(arr[minidx], arr[i]);
    }
}

int main()
{
    int arr[5];
    cout << "Enter elements of array: " << endl;
    input(arr);
    SelSort(arr);
    cout << "Sorted array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
