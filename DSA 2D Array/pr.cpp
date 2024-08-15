#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v1 = {5, 4, 2, 1, 3};

    // Sorting the vector
    sort(v1.begin(), v1.end());

    // Displaying the sorted elements of the vector
    for (int i : v1)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
