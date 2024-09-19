#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    vector<int> a(5, 1);
    vector<int> z(a);
    v.push_back(1);
    cout << "Capacity of vector: " << v.capacity() << endl;
    v.push_back(2);
    cout << "Capacity of vector: " << v.capacity() << endl;
    v.push_back(3);
    cout << "Capacity of vector: " << v.capacity() << endl;
    cout << "Size of vector: " << v.size() << endl;
    cout << "Element at 1st index: " << v.at(1) << endl;
    cout << "First element: " << v.front() << endl;
    cout << "Last Element: " << v.back() << endl;

    cout << "Elements in the vector are: " << endl;
    for (int i : v)
    {
        cout << i << " ";
    }

    v.pop_back();
    cout << "Elements in the vector after pop are: " << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    v.clear();
    cout << "Size of vector after clearing :" << v.size() << endl;

    return 0;
}