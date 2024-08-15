#include <iostream>
using namespace std;
const int size = 5;
void input(int arr[])
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
int first_occur(int arr[], int n)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans = 1;
    while (start <= end)
    {
        if (arr[mid] == n)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (n > arr[mid]) // moving on right
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
int last_occur(int arr[], int n)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int ans = 1;
    while (start <= end)
    {
        if (arr[mid] == n)
        {
            ans = mid;
            start = mid + 1;
        }
        else if (n > arr[mid]) // moving on right
        {
            start = mid + 1;
        }
        else // moving on left
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
int main()
{
    int arr[size];
    cout << "Enter elements of array: " << endl;
    input(arr);
    cout << "The first occurence is at index:" << first_occur(arr, 3) << endl;
    cout << "The last occurence is at index: " << last_occur(arr, 3) << endl;
    return 0;
}
