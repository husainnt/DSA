#include <iostream>
#include <list>
using namespace std;
void display(list<int> &l)
{
    list<int>::iterator it;
    for (it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    list<int> l1; // list of 0 size
    // list<int> l2(7); // ist of size 7
    l1.push_back(5);
    l1.push_back(6);
    l1.push_back(7);
    l1.push_back(8);
    display(l1);
    l1.remove(7); // removes 7 and all of its occurences in the list
}