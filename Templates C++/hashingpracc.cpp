#include <iostream>
#include <list>
#include <vector>
using namespace std;
class Hashset
{
public:
    vector<list<int>> hashtable;
    int table_size;
    Hashset(int size)
    {
        this->hashtable = vector<list<int>>(size);
        this->table_size = size;
    }
    int hashfunction(int key)
    {
        return key % table_size;
    }
    void insert(int key)
    {
        int idx = hashfunction(key);
        hashtable[idx].push_back(key);
    }
    bool search(int key)
    {
        int idx = hashfunction(key);
        auto it = hashtable[idx].begin();
        for (it; it != hashtable[idx].end(); ++it)
        {
            if (*it == key)
                return true;
        }
        return false;
    }
};
int main()
{
    Hashset hs(5);
    hs.insert(2);
    hs.insert(4);
    hs.insert(6);
    hs.insert(8);
    hs.insert(10);
    if (hs.search(10))
    {
        cout << "10 found in the hashtable" << endl;
    }
    else
    {
        cout << "10 not found in the hashtable" << endl;
    }
    return 0;
}