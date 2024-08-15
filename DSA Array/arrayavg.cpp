#include <iostream>
using namespace std;

const int max_size = 5;

void input(int arr[]);
float avg(const int arr[]);

void input(int arr[])
{
    for (int i = 0; i < max_size; i++)
    {
        cin >> arr[i];
    }
}

float avg(const int arr[])
{
    int sum = 0;
    for (int i = 0; i < max_size; i++)
    {
        sum += arr[i];
    }
    float average = static_cast<float>(sum) / max_size;
    return average;
}

int main()
{
    int arr[max_size];
    cout << "Enter elements of array:" << endl;
    input(arr);
    cout << "Average of the elements of the array is: " << avg(arr) << endl;
    return 0;
}
