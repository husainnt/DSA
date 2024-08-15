#include <iostream>
using namespace std;

const int max_size = 5;

void input(int arr[])
{
    for (int i = 0; i < max_size; i++)
    {
        cin >> arr[i];
    }
}

int linearsearch(int arr[], int n)
{
    int ans = -1;
    for (int i = 0; i < max_size; i++)
    {
        if (n == arr[i])
        {
            ans = i;
            break;
        }
    }
    return ans;
}

int main()
{
    int arr[max_size];
    cout << "Enter elements of array:" << endl;
    input(arr);

    int numberToSearch;
    cout << "Enter a number to search: ";
    cin >> numberToSearch;

    int result = linearsearch(arr, numberToSearch);

    if (result != -1)
    {
        cout << "Element " << numberToSearch << " is at index: " << result << endl;
    }
    else
    {
        cout << "Element " << numberToSearch << " is not found in the array." << endl;
    }

    return 0;
}
