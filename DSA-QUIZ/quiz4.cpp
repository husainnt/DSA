#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;
class Hashset
{
public:
    vector<list<string>> hash_table;
    int table_size;
    Hashset(int size)
    {
        this->table_size = size;
        hash_table.resize(size);
    }
    int hashfunc(string key)
    {
        int hash = 0;
        int prime = 31;
        for (int i = 0; i < key.length(); i++)
        {
            hash += (key[i] * prime) % table_size;
            prime = (prime * 31) % table_size;
        }
        return hash % table_size;
    }
    void add(string key)
    {
        int idx = hashfunc(key);
        hash_table[idx].push_back(key);
    }
    bool search(string key)
    {
        int idx = hashfunc(key);
        auto it = hash_table[idx].begin();
        for (it; it != hash_table[idx].end(); ++it)
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
    Hashset myhash(6);

    myhash.add("hussain");
    myhash.add("haider");
    myhash.add("sameer");
    myhash.add("ali");
    myhash.add("ahmed");

    string names[] = {"hussain", "john", "ali", "ahmed"};

    for (const string &name : names)
    {
        if (myhash.search(name))
        {
            cout << name << " is found in the hash set." << endl;
        }
        else
        {
            cout << name << " is not found in the hash set." << endl;
        }
    }

    return 0;
}
