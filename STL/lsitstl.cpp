#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l;
    list<int> a(l);  // copying list 'l' to 'a'
    l.push_front(2); // adding elements at start
    l.push_front(1);
    l.push_back(3); // adding elements at end
    cout << "Elements in list are: " << endl;
    for (int i : l)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "Size of list: " << l.size() << endl;

    return 0;
}