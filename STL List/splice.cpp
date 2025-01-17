#include <list>
#include <iostream>
using namespace std;

// Custom splice function: Moves all elements of l2 to the end of l1
void custom_splice(list<int> &l1, list<int> &l2)
{
    auto it2 = l2.begin(); // Iterator for l2

    // Transfer each element of l2 to the end of l1
    while (it2 != l2.end())
    {
        // Insert the current element from l2 into the end of l1
        l1.push_back(*it2);

        // Erase the element from l2 after it is inserted into l1
        it2 = l2.erase(it2); // it2 now points to the next element in l2
    }
}

int main()
{
    list<int> l1 = {1, 3, 5}; // List 1
    list<int> l2 = {2, 4, 6}; // List 2

    // Call custom splice function (move all elements from l2 to l1)
    custom_splice(l1, l2);

    // Print the result of l1 after splicing
    cout << "List l1 after splicing: ";
    for (const auto &elem : l1)
    {
        cout << elem << " "; // Output: 1 3 5 2 4 6
    }
    cout << endl;

    // Check if l2 is now empty
    if (l2.empty())
    {
        cout << "List l2 is empty after splicing.\n";
    }

    return 0;
}
