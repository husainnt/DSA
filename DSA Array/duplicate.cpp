#include <iostream>
using namespace std;

void findDuplicates(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                cout << "Duplicate found with value " << arr[j] << endl;
            }
        }
    }
}

int main()
{
    int size = 5;
    int arr[size] = {1, 2, 3, 4, 3};
    findDuplicates(arr, size);
    return 0;
}
