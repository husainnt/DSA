#include <iostream>
using namespace std;

int linear_search(int arr[], int size, int target)
{
    if (size == 0)
    {
        return -1;
    }
    // Check if the last element is the target
    if (arr[size - 1] == target)
    {
        return size - 1;
    }
    // Recursive case: search in the remaining array
    return linear_search(arr, size - 1, target);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 30;
    cout << "Element found at index: " << linear_search(arr, size, target);
}
