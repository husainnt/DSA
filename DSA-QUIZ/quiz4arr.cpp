#include <iostream>
#include <list>
using namespace std;

class HashChain
{
    list<int> *Array;
    int size;

public:
    HashChain(int x)
    {
        size = x;
        Array = new list<int>[size];
    }

    ~HashChain()
    {
        delete[] Array;
    }

    int hashFunction(int key)
    {
        return key % size;
    }

    void insert(int y)
    {
        int index = hashFunction(y);
        Array[index].push_back(y);
    }

    bool search(int z)
    {
        int index = hashFunction(z);
        for (int value : Array[index])
        {
            if (value == z)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    HashChain hashTable(10);
    hashTable.insert(10);
    hashTable.insert(20);
    hashTable.insert(30);
    hashTable.insert(15);

    cout << "Searching for 20: " << (hashTable.search(20) ? "Found" : "Not Found") << endl;
    cout << "Searching for 25: " << (hashTable.search(25) ? "Found" : "Not Found") << endl;

    return 0;
}