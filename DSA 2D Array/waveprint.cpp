#include <iostream>
using namespace std;

void input(int arr[][2], int size1) // taking input row wise
{
    for (int row = 0; row < size1; row++)
    {
        for (int col = 0; col < 2; col++)
        {
            cin >> arr[row][col];
        }
    }
}

void output_in_waveform(int arr[][2], int size1) // output column wise
{
    for (int col = 0; col < 2; col++)
    {
        if (col % 2 != 0)
        {
            for (int row = size1 - 1; row >= 0; row--)
            {
                cout << arr[row][col] << " ";
            }
        }
        else
        {
            for (int row = 0; row < size1; row++)
            {
                cout << arr[row][col] << " ";
            }
        }
    }
}

int main()
{
    int size1;
    cout << "Enter number of rows: " << endl;
    cin >> size1;
    int arr[size1][2];
    cout << "Enter elements of array: " << endl;
    input(arr, size1);
    cout << endl;
    cout << "Wave form print is: " << endl;
    output_in_waveform(arr, size1);
    return 0;
}
