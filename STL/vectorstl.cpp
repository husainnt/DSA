#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;       // declaring a vector
    vector<int> a(5, 1); // vector 'a' intialised with size 5 and with 1 as all elements
    vector<int> z(a);    // all elements of 'a' are copied into z
    v.push_back(1);      // adding an element
    cout << "Capacity of vector: " << v.capacity() << endl;
    v.push_back(2); // adding an element
    cout << "Capacity of vector: " << v.capacity() << endl;
    v.push_back(3);                                         // adding an element
    cout << "Capacity of vector: " << v.capacity() << endl; // now capacity will double and be 4
    cout << "Size of vector: " << v.size() << endl;         // size will be 3 as 3 elements
    cout << "Element at 1st index: " << v.at(1) << endl;
    cout << "First element: " << v.front() << endl;
    cout << "Last Element: " << v.back() << endl;
    // displaying all elements
    cout << "Elements in the vector are: " << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    // after pop
    v.pop_back();
    cout << "Elements in the vector after pop are: " << endl;
    for (int i : v)
    {
        cout << i << " ";
    }
    v.clear(); // clearing a vector
    cout << "Size of vector after clearing :" << v.size() << endl;

    return 0;
}