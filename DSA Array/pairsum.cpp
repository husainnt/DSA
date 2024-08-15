#include <iostream>
using namespace std;
void findPairsWithSum(const int arr[], int size, int sum)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                cout << "Pairs with sum equal to " << sum << ": (" << arr[i] << "," << arr[j] << ")" << endl;
            }
        }
    }
}

int main()
{
    int sum = 5;
    int size = 5;
    int arr[size] = {1, 2, 3, 4, 5};

    findPairsWithSum(arr, size, sum);

    return 0;
}
