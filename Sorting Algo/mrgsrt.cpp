#include <iostream>
using namespace std;

// Function to merge two halves of the array
void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1; // Length of first half
    int len2 = e - mid;     // Length of second half

    // Create temporary arrays for both halves
    int *first = new int[len1];
    int *second = new int[len2];

    // Copy values into the first half array
    int k = s;
    for (int i = 0; i < len1; ++i)
    { // Fixed typo: i0 -> i, initialized i properly
        first[i] = arr[k++];
    }

    // Copy values into the second half array
    k = mid + 1; // k should now start at mid + 1 for the second half
    for (int i = 0; i < len2; ++i)
    {
        second[i] = arr[k++];
    }

    // Merge two sorted arrays back into the main array
    int i = 0, j = 0;
    k = s;
    while (i < len1 && j < len2)
    {
        if (first[i] < second[j])
        {
            arr[k++] = first[i++];
        }
        else
        {
            arr[k++] = second[j++];
        }
    }

    // Copy remaining elements of first array, if any
    while (i < len1)
    {
        arr[k++] = first[i++];
    }

    // Copy remaining elements of second array, if any
    while (j < len2)
    {
        arr[k++] = second[j++];
    }

    // Free memory for temporary arrays
    delete[] first;
    delete[] second;
}

// Function to perform merge sort
void merge_sort(int arr[], int s, int e)
{
    // Base case: If the array has one or no elements, it's already sorted
    if (s >= e)
        return;

    int mid = s + (e - s) / 2; // Find the middle point
    // Recursively sort the first half
    merge_sort(arr, s, mid);
    // Recursively sort the second half
    merge_sort(arr, mid + 1, e);
    // Merge the two halves
    merge(arr, s, e);
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call merge sort
    merge_sort(arr, 0, n - 1);

    // Output the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
