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

int peak_idx_mountain_array(int arr[])
{
    int start = 0;
    int end = size - 1; // Corrected endpoint
    int mid;

    while (start < end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return start; // Return the peak index
}

int main()
{
    int arr[size];
    cout << "Enter elements of array: " << endl;
    input(arr);

    int peak_index = peak_idx_mountain_array(arr);
    cout << "Peak element is: " << arr[peak_index] << " at index " << peak_index << endl;

    return 0;
}
