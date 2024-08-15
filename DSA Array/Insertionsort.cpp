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

void Insertion_sort(int arr[])
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
    int arr[size];
    cout << "Enter elements of array: " << endl;
    input(arr);
    Insertion_sort(arr);
    cout << "Sorted values using Insertion sort are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
