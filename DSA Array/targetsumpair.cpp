#include <iostream>
using namespace std;

const int max_size = 100;

void input(int arr[], int &l)
{
    cout << "Enter array length: ";
    cin >> l;
    cout << "Enter elements of array: ";
    for (int i = 0; i < l; i++)
    {
        cin >> arr[i];
    }
}

void pairs(int arr[], int l)
{
    int ts, pair = 0;
    cout << "Enter target sum: ";
    cin >> ts;
    cout << "Pairs that add up to the target sum are:" << endl;
    for (int i = 0; i < l; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            if (arr[i] + arr[j] == ts)
            {
                cout << "[" << arr[i] << "," << arr[j] << "]";
                pair++;
            }
        }
    }
    cout << endl;
    cout << "Total pairs: " << pair << endl;
}

int main()
{
    int arr[max_size];
    int l;

    input(arr, l);
    cout << endl;
    pairs(arr, l);
    cout << endl;

    return 0;
}
