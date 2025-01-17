#include <iostream>
using namespace std;

void input(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void Insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;

    int *arr = new int[size];

    cout << "Enter elements of array: " << endl;
    input(arr, size);

    Insertion_sort(arr, size);

    cout << "Sorted values using Insertion sort are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
