#include <iostream>
using namespace std;

void swapPairs(int arr[], int size)
{
    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size = 5;
    int arr[size] = {1, 2, 7, 8, 5};

    swapPairs(arr, size);
    printArray(arr, size);

    return 0;
}
