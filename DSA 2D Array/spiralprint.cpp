#include <iostream>
using namespace std;

void input(int arr[][3], int size1, int size2) // taking input row-wise
{
    for (int row = 0; row < size1; row++)
    {
        for (int col = 0; col < size2; col++)
        {
            cin >> arr[row][col];
        }
    }
}

void spiralPrint(int arr[][3], int size1, int size2) // output in spiral order
{
    int top = 0, bottom = size1 - 1;
    int left = 0, right = size2 - 1;

    while (top <= bottom && left <= right)
    {
        // Print top row
        for (int i = left; i <= right; i++)
        {
            cout << arr[top][i] << " ";
        }
        top++;

        // Print right column
        for (int i = top; i <= bottom; i++)
        {
            cout << arr[i][right] << " ";
        }
        right--;

        if (top <= bottom)
        {
            // Print bottom row
            for (int i = right; i >= left; i--)
            {
                cout << arr[bottom][i] << " ";
            }
            bottom--;
        }

        if (left <= right)
        {
            // Print left column
            for (int i = bottom; i >= top; i--)
            {
                cout << arr[i][left] << " ";
            }
            left++;
        }
    }
}

int main()
{
    const int size1 = 3; // Set the number of rows
    const int size2 = 3; // Set the number of columns
    int arr[size1][size2];

    cout << "Enter elements of the array: " << endl;
    input(arr, size1, size2);

    cout << "Spiral print is: " << endl;
    spiralPrint(arr, size1, size2);

    return 0;
}
