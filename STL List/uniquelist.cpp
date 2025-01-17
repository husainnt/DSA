#include <iostream>
#include <list>
using namespace std;
void unique_list(list<int> &l1)
{
    for (auto it1 = l1.begin(); it1 != l1.end(); ++it1)
    {
        auto it2 = next(it1);
        while (it2 != l1.end())
        {
            if (*it1 == *it2)
            {
                it2 = l1.erase(it2);
            }

            ++it2;
        }
    }
}

void display(list<int> l1)
{
    auto it1 = l1.begin();
    while (it1 != l1.end())
    {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;
}

int main()
{
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(2);
    l1.push_back(4);
    cout << "Elements in list with duplicates are: ";
    display(l1);
    cout << endl;
    unique_list(l1);
    cout << "Elements in lsit after being unique are: ";
    display(l1);
};