#include <iostream>
using namespace std;
// Function to merge two halves into a sorted array
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int *leftArray = new int[n1];
    int *rightArray = new int[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; ++i)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArray[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            ++i;
        }
        else
        {
            arr[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of leftArray, if any
    while (i < n1)
    {
        arr[k] = leftArray[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of rightArray, if any
    while (j < n2)
    {
        arr[k] = rightArray[j];
        ++j;
        ++k;
    }

    // Clean up memory
    delete[] leftArray;
    delete[] rightArray;
}

// Function to implement merge sort using recursion
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Helper function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArray(arr, arrSize);

    mergeSort(arr, 0, arrSize - 1);

    cout << "\nSorted array is \n";
    printArray(arr, arrSize);
    return 0;
}
