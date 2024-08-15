#include <iostream>
using namespace std;

// Function to partition the array and return the pivot index
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int i = start + 1; // index for tracking elements less than or equal to pivot

    for (int j = start + 1; j <= end; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    // Place the pivot in its correct position
    swap(arr[start], arr[i - 1]);

    return i - 1; // return the pivot index
}

// Function to perform quicksort recursively
void quick_sort(int arr[], int start, int end)
{
    if (start >= end) // base case: when there's only one element or invalid range
    {
        return;
    }

    int p = partition(arr, start, end); // partition the array and get pivot index

    quick_sort(arr, start, p - 1); // recursively sort left subarray
    quick_sort(arr, p + 1, end);   // recursively sort right subarray
}

// Function to print the array
void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function to test quicksort
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    print_array(arr, n);

    quick_sort(arr, 0, n - 1);

    cout << "Sorted array: ";
    print_array(arr, n);

    return 0;
}
