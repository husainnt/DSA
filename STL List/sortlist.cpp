#include <list>
#include <iostream>
using namespace std;

void sort(list<int> &l2)
{
    auto it1 = l2.begin();
    for (it1; it1 != l2.end(); it1++)
    {
        auto it2 = next(it1);
        while (it2 != l2.end())
        {
            if (*it1 > *it2)
            {
                swap(*it1, *it2);
            }
            it2++;
        }
    }
}

void display(const list<int> &l1)
{
    for (const auto &item : l1)
    {
        cout << item << " ";
    }
    cout << endl;
}

int main()
{
    list<int> l1;
    l1.push_back(100);
    l1.push_back(80);
    l1.push_back(60);
    l1.push_back(40);
    l1.push_back(20);
    l1.push_back(10);

    sort(l1);
    cout << "Values in list are: ";
    display(l1);

    return 0;
}
