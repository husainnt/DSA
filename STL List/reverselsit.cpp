#include <list>
#include <iostream>
using namespace std;

void reverse_list(list<int> &l)
{
    list<int> reversedList;

    for (auto it = l.begin(); it != l.end(); ++it)
    {
        reversedList.push_front(*it);
    }

    l.swap(reversedList);
}
int main()
{
    list<int> myList = {1, 2, 3, 4, 5};

    reverse_list(myList);

    for (const auto &elem : myList)
    {
        cout << elem << " "; // Output: 5 4 3 2 1
    }

    return 0;
}