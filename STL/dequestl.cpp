#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> d;    // declaring a deque 'd'
    d.push_front(1); // adding 1 at start
    d.push_back(2);  // adding 2 at end
    d.push_back(3);
    cout << "Elements in Deque are: ";
    // dispalying elements
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Size of deque is: " << d.size() << endl;
    cout << "Element at 0th index is: " << d.at(0) << endl;
    d.pop_back();  // removing last element
    d.pop_front(); // removing frst element
    cout << "Elements in Deque after popping are: ";
    // dispalying elements
    for (int i : d)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Is the Deque empty? " << d.empty() << endl;
    d.erase(d.begin(), d.end()); // erasing all elements from starts to end
    cout << "Is the Deque empty after erasing? " << d.empty() << endl;
    return 0;
}