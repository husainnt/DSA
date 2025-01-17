#include <iostream>
#include <list>
using namespace std;

void sort_odd_even(list<int> &l1, list<int> &l2, list<int> &l3)
{
    auto it = l1.begin();
    while (it != l1.end())
    {
        if (*it % 2 == 0)
        {
            l2.push_back(*it);
        }
        else
        {
            l3.push_back(*it);
        }
        ++it; // Increment iterator once here
    }
}

void display(const list<int> &l2, const list<int> &l3)
{
    cout << "List with even values are :" << endl;
    for (auto it2 = l2.begin(); it2 != l2.end(); ++it2)
    {
        cout << *it2 << " ";
    }
    cout << endl;

    cout << "List with odd values are :" << endl;
    for (auto it3 = l3.begin(); it3 != l3.end(); ++it3)
    {
        cout << *it3 << " ";
    }
    cout << endl;
}

int main()
{
    list<int> l1;
    list<int> l2;
    list<int> l3;

    // Populate the list
    for (int i = 1; i <= 10; ++i)
    {
        l1.push_back(i);
    }

    // Sort odd and even numbers
    sort_odd_even(l1, l2, l3);

    // Display the results
    display(l2, l3);

    return 0;
}
