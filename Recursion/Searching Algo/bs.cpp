#include <iostream>
#include <vector>
using namespace std;

int binary_search(const vector<int> &arr, int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    while (start <= end)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target > arr[mid])
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
    int size, target;
    cout << "Enter the size of the array: " << endl;
    cin >> size;

        vector<int> arr(size);
    cout << "Enter elements of array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to be searched for within the array: " << endl;
    cin >> target;

    int result = binary_search(arr, size, target);
    if (result != -1)
        cout << "The element is at index: " << result;
    else
        cout << "Element not found in the array.";
}
