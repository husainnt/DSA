#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{
    // Base case: if the array has only one element or is empty, it's sorted
    if (size == 1 || size == 0)
        return true;

    // If the first element is greater than the second, it's not sorted
    if (arr[size - 1] < arr[size - 2])
        return false;

    // Recursively check the rest of the array
    return isSorted(arr, size - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (isSorted(arr, size))
    {
        cout << "The array is sorted." << endl;
    }
    else
    {
        cout << "The array is not sorted." << endl;
    }

    return 0;
}
