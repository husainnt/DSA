#include <iostream>
#include <vector>
#include <list>

using namespace std;

class MyHashSet
{
public:
    vector<list<int>> hashtable;
    int table_size;

    MyHashSet(int size = 1000)
    {
        this->table_size = size;
        hashtable.resize(size);
    }

    void add(int key)
    {
        int hashvalue = key % table_size;
        int idx = hashvalue;

        if (!contains(key))
        {
            hashtable[idx].push_back(key);
        }
    }

    void remove(int key)
    {
        int hashvalue = key % table_size;
        int idx = hashvalue;

        auto it = hashtable[idx].begin();
        while (it != hashtable[idx].end())
        {
            if (*it == key)
            {
                hashtable[idx].erase(it);
                return;
            }
            ++it;
        }

        cout << "[WARNING] Key Not Present!" << endl;
    }

    bool contains(int key)
    {
        int hashvalue = key % table_size;
        int idx = hashvalue;

        for (auto it = hashtable[idx].begin(); it != hashtable[idx].end(); ++it)
        {
            if (*it == key)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    MyHashSet myHashSet;
    myHashSet.add(1);
    myHashSet.add(2);
    cout << myHashSet.contains(1) << endl;
    cout << myHashSet.contains(3) << endl;
    myHashSet.add(2);
    cout << myHashSet.contains(2) << endl;
    myHashSet.remove(2);
    cout << myHashSet.contains(2) << endl;
}
