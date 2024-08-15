#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 4> arr = {1, 2, 3, 4};
    int size = arr.size();
    cout << "Element at 1st index is: " << arr.at(1) << endl;
    cout << "First element is: " << arr.front() << endl;
    cout << "Last element is: " << arr.back() << endl;
    cout << "Is the array empty: " << arr.empty() << endl;
    cout << "Elements in the array are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}