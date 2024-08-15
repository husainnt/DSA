#include <iostream>
using namespace std;

void input(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
int appear_once(int arr[], int size)
{
    int unique = arr[0];
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; i < size; i++)
        {
            if (unique != arr[j])
            {
                arr[i] = unique;
            }
        }
    }
    cout << unique;
}
int main()
{
    int size;
    cout << "Enter size of array: " << endl;
    cin >> size;
    int arr[size];
    cout << "Enter elements of array: " << endl;
    input(arr, size);
    cout << endl;
    appear_once(arr, size);

    return 0;
}