#include <iostream>
using namespace std;

bool binary_search(int *arr, int start, int end, int k)
{
    if (start > end)
    {
        return false; // base case: element not found
    }
    int mid = start + (end - start) / 2;
    if (arr[mid] == k)
    {
        return true; // element found
    }
    else if (arr[mid] < k)
    {
        return binary_search(arr, mid + 1, end, k);
    }
    else // arr[mid] > k
    {
        return binary_search(arr, start, mid - 1, k);
    }
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int target = 6;
    bool found = binary_search(arr, 0, 5, target);
    if (found)
    {
        cout << "Element found!" << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }
    return 0;
}
