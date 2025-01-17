#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Hashing
{
public:
    vector<list<int>> hashtable;
    int table_size;

    Hashing(int size)
    {
        this->table_size = size;
        hashtable.resize(size);
    }

    int hashvalue(int key)
    {
        return key % table_size;
    }

    void insert(int key)
    {
        int index = hashvalue(key);
        hashtable[index].push_back(key);
    }

    list<int>::iterator search(int key)
    {
        int index = hashvalue(key);
        for (auto it = hashtable[index].begin(); it != hashtable[index].end(); ++it)
        {
            if (*it == key)
            {
                return it;
            }
        }
        return hashtable[index].end();
    }

    void deleteKey(int key)
    {
        int index = hashvalue(key);
        auto it = search(key);
        if (it != hashtable[index].end())
        {
            hashtable[index].erase(it);
        }
        else
        {
            cout << "[WARNING] Key Not Present!" << endl;
        }
    }
 list<int> getitem(int index)
    {
        if (index >= 0 && index < table_size)
        {
            return hashtable[index];
        }
        else
        {
            cout << "[ERROR] Index out of bounds!" << endl;
            return {};
        }
    }
    void print()
    {
        
        for (int i = 0; i < table_size; i++)
        {
            cout << "Index " << i << ": ";
            auto it=hashtable[i].begin();
            for (;it!=hashtable[i].end();it++)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Hashing hashTable(10);
    hashTable.insert(15);
    hashTable.insert(25);
    hashTable.insert(35);

    hashTable.print();

    hashTable.deleteKey(25);
    hashTable.print();

    hashTable.deleteKey(40);

    // Example usage of getitem
    list<int> items = hashTable.getitem(5);
    cout << "Items at index 5: ";
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}
