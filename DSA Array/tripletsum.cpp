#include <iostream>
using namespace std;
void findTripletsWithSum(const int arr[], int size, int sum)
{
    for (int i = 0; i < size - 2; i++)
    {
        for (int j = i + 1; j < size - 1; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                {
                    cout << "Triplet pair with sum equals to " << sum << " is: (" << arr[i] << "," << arr[j] << "," << arr[k] << ")" << endl;
                }
            }
        }
    }
}

int main()
{
    int sum = 12;
    int size = 5;
    int arr[size] = {1, 2, 3, 4, 5};

    findTripletsWithSum(arr, size, sum);

    return 0;
}
