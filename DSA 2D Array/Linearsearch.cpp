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

void Linear_search(int arr[][col], int size, int target)
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (arr[row][col] == target)
            {
                cout << "Element found at (" << row << "," << col << ")" << endl;
                return; // Exit the function after finding the element
            }
        }
    }
    cout << "Element not found" << endl; // Print once after checking all elements
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
    cout << "Enter the element to be searched: " << endl;
    cin >> target;
    Linear_search(arr, size, target);
    return 0;
}
