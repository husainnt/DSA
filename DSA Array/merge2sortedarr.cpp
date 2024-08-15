#include <iostream>
using namespace std;

const int size1 = 5;
const int size2 = 3;

void input(int arr1[], int arr2[])
{
    cout << "Enter elements for the first array: ";
    for (int i = 0; i < size1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter elements for the second array: ";
    for (int j = 0; j < size2; j++)
    {
        cin >> arr2[j];
    }
}

void merge(int arr1[], int arr2[], int arr3[])
{
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }

    while (i < size1)
    {
        arr3[k++] = arr1[i++];
    }

    while (j < size2)
    {
        arr3[k++] = arr2[j++];
    }
}

int main()
{
    int arr1[size1], arr2[size2], arr3[size1 + size2];

    input(arr1, arr2);
    merge(arr1, arr2, arr3);

    cout << "Merged array: ";
    for (int i = 0; i < size1 + size2; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;

    return 0;
}
