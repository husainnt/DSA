#include <iostream>
using namespace std;

const int size2 = 4;

void input(int arr[][size2], int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size2; col++)
        {
            cin >> arr[row][col];
        }
    }
}

int largest(int arr[][size2], int size)
{
    int max = 0;
    for (int row = 0; row < size; row++)
    {
        int sum = 0;

        for (int col = 0; col < size2; col++)
        {
            sum += arr[row][col];
        }
        if (sum > max)
        {
            max = sum;
        }
    }
    cout << "Largest row sum is: " << max << " ";
}

int main()
{
    int target;
    int size;
    cout << "Enter number of rows: " << endl;
    cin >> size;
    int arr[size][size2];
    cout << "Enter elements of array: " << endl;
    input(arr, size);
    largest(arr, size);
    return 0;
}
