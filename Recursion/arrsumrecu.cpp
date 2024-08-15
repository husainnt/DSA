#include <iostream>
using namespace std;

int array_sum(int arr[], int size)
{
    // Base case
    if (size == 0)
    {
        return 0;
    }
    // Recursive case
    return arr[size - 1] + array_sum(arr, size - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = array_sum(arr, size);
    cout << "Sum of array elements: " << sum << endl;
    return 0;
}
