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
void Bubble_sort(int arr[])
{
    for (int i = 1; i < size; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

int main()
{
    int arr[5];
    cout << "Enter elements of array: " << endl;
    input(arr);
    Bubble_sort(arr);
    cout << "Sorted values using Bubble sort are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
