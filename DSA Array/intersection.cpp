#include <iostream>
using namespace std;

void findCommonElements(const int arr1[], int m, const int arr2[], int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr1[i] == arr2[j])
            {
                cout << "Common element is: " << arr1[i] << endl;
            }
        }
    }
}

int main()
{
    int m = 3;
    int n = 3;
    int arr1[m] = {1, 2, 3};
    int arr2[n] = {4, 3, 5};

    findCommonElements(arr1, m, arr2, n);

    return 0;
}
