#include <iostream>
using namespace std;

void input(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void sort_even_odd(int arr[], int size)
{
    int left = 0;
    int right = size - 1;
    while (left < right)
    {
        while (arr[left] % 2 == 0 && left < right)
        {
            left++;
        }
        while (arr[right] % 2 != 0 && left < right)
        {
            right--;
        }
        if (left < right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

void even_greaterthan_odd(int arr[], int size)
{
    for (int i = 1; i < size; i += 2)
    {
        if (i + 1 < size && arr[i + 1] < arr[i])
        {
            swap(arr[i + 1], arr[i]);
        }
    }
}

void print(int arr[], int size)
{
    cout << "Array with even > odd is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter size of array: " << endl;
    cin >> size;
    int arr[size];
    cout << "Enter elements: " << endl;
    input(arr, size);

    sort_even_odd(arr, size);
    even_greaterthan_odd(arr, size);

    print(arr, size);

    return 0;
}
