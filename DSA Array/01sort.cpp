#include <iostream>
using namespace std;

void sortZeroOne(int arr[], int size)
{
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        // Increment left index while we see 0 at left
        while (arr[left] == 0 && left < right)
        {
            left++;
        }

        // Decrement right index while we see 1 at right
        while (arr[right] == 1 && left < right)
        {
            right--;
        }

        // Swap arr[left] and arr[right] if left is still less than right
        if (left < right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

void printArray(int arr[], int size)
{
    cout << "Sorted array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int size = 6; // Adjusted to the correct size of the initial array
    int arr[] = {0, 1, 1, 0, 0, 1};

    sortZeroOne(arr, size);
    printArray(arr, size);

    return 0;
}
