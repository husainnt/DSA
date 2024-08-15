#include <iostream>
using namespace std;

const int size = 6;

void input(int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

int binarysearch(int arr[], int n)
{
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    while (start <= end)
    {
        if (arr[mid] == n)
        {
            return mid;
        }
        if (n > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
}

int main()
{
    int arr[size];
    cout << "Enter elements of array: " << endl;
    input(arr);

    int target;
    cout << "Enter the number to search for: ";
    cin >> target;

    int index = binarysearch(arr, target);

    if (index != -1)
    {
        cout << "Element found at index " << index << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}
