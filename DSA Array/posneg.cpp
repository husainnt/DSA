#include <iostream>
using namespace std;

void input(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void rearrange(int arr[], int size)
{
    // Create separate arrays for positive and negative numbers
    int pos[size], neg[size];
    int posIndex = 0, negIndex = 0;

    // Separate positive and negative numbers
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= 0)
        {
            pos[posIndex++] = arr[i];
        }
        else
        {
            neg[negIndex++] = arr[i];
        }
    }

    // Merge the positive and negative arrays back into the original array alternately
    int i = 0, j = 0, k = 0;
    while (i < posIndex && j < negIndex)
    {
        if (k % 2 == 0)
        {
            arr[k++] = pos[i++];
        }
        else
        {
            arr[k++] = neg[j++];
        }
    }

    // If there are remaining positive numbers
    while (i > posIndex)
    {
        arr[k++] = pos[i++];
    }

    // If there are remaining negative numbers
    while (j < negIndex)
    {
        arr[k++] = neg[j++];
    }
}

void print(int arr[], int size)
{
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
    cout << "Enter array elements: " << endl;
    input(arr, size);
    cout << endl;
    rearrange(arr, size);
    cout << "Array after rearranging: " << endl;
    print(arr, size);
    return 0;
}
