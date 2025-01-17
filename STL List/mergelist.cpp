#include <iostream>
#include <list>
#include <iterator>
using namespace std;
void merge_list(list<int> &l1, list<int> &l2)
{
    auto it1 = l1.begin();
    auto it2 = l2.begin();
    while (it1 != l1.end() && it2 != l2.end())
    {
        if (*it1 > *it2)
        {
            it1 = l1.insert(it1, *it2);
            ++it2;
        }
        else
        {
            ++it1;
        }
    }
    {
        if (it2 != l2.end())
        {
            l1.insert(l1.end(), it2, l2.end());
        }
    }
}
void display(list<int> l)
{

    auto it = l.begin();
    while (it != l.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

int main()
{
    list<int> l1;
    l1.push_back(2);
    l1.push_back(4);
    l1.push_back(6);
    l1.push_back(8);
    l1.push_back(10);
    list<int> l2;
    l2.push_back(12);
    l2.push_back(13);
    l2.push_back(14);
    l2.push_back(15);
    l2.push_back(16);
    cout << "List l1 is: ";
    display(l1);
    merge_list(l1, l2);
    cout << "List l1 after merging is: ";
    display(l1);
}
