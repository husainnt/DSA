#include <iostream>
#include <list>
#include <vector>
using namespace std;

template <typename T>
class Myhashset
{
public:
    vector<list<T>> hash_table;
    int table_size;

    Myhashset(int size)
    {
        this->hash_table = vector<list<T>>(size);
        this->table_size = size;
    }

    int hashfunction(T key)
    {
        return key % table_size;
    }

    void insert(T key)
    {
        int idx = hashfunction(key);
        hash_table[idx].push_back(key);
    }

    bool search(T key)
    {
        int idx = hashfunction(key);

        for (auto it = hash_table[idx].begin(); it != hash_table[idx].end(); ++it)
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
    Myhashset<int> hashset(10);
    hashset.insert(5);
    hashset.insert(15);
    hashset.insert(25);

    if (hashset.search(15))
        cout << "15 found in hash set." << endl;
    else
        cout << "15 not found." << endl;

    if (hashset.search(9))
        cout << "9 found in hash set." << endl;
    else
        cout << "9 not found." << endl;

    return 0;
}
