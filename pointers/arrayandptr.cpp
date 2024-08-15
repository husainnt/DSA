#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {2, 5, 6};
    cout << "Address of first memory block of array is: " << arr << endl;
    cout << "value at 0th index is: " << *arr << endl;
    cout << "incrementing by 1 at 0th loc: " << *arr + 1 << endl;
    cout << "value at 1st loc: " << *(arr + 1) << endl;
    int i = 2;
    cout << i[arr] << endl;
    return 0;
}