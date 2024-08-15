#include <iostream>
using namespace std;

const int col = 4;

void input(int arr[][col], int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cin >> arr[row][col];
        }
    }
}

int row_wise_sum(int arr[][col], int size)
{
    for (int row = 0; row < size; row++)
    {
        int sum = 0;
        for (int col = 0; col < 4; col++)
        {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }
    cout << endl;
}

int main()
{
    int target;
    int size;
    cout << "Enter number of rows: " << endl;
    cin >> size;
    int arr[size][col];
    cout << "Enter elements of array: " << endl;
    input(arr, size);
    cout << "Row wise sum is: " << endl;
    row_wise_sum(arr, size);
    return 0;
}
