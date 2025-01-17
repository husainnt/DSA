/*
 * Assignment #: 3
 * Name: Hussain Tahir
 * Roll #: 22i-1838
 * Section: A
 * Program Description:
 * The program performs the following tasks:
 * 1. Creates a Hashtable of size 9973 (a prime number) and inserts all words from the file "Assig03_wordlist.txt".
 * 2. Uses chaining to handle collisions.
 * 3. Reads the file "input.txt", searches for every word in that file against the entries in the hashtable,
 *    and if not present, converts the word/character to uppercase and overwrites the file.
 * 4. Displays the Load Factor.
 *
 * Hash Function:
 * The hash function computes an index by multiplying the ASCII value of each character by a prime number.
 * The resulting hash number is then taken modulo the table size to generate an index.
 * This approach helps distribute the entries uniformly across the hashtable.
 *
 * Additionally, I have created the following classes:
 * 1. HashChain - For Hashing, Searching, Destructor, Insertion and Load-Factor.
 * 2. Spellchecking - Containing functions check for corresponding words in the input file with the hashtable and
 *    containing functions for file handling.
 *
 * Note: As I use VSCode, the compiler gives no errors, but I am not aware of any issues if compiled
 * on any other code editor/IDE.
 */

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class HashChain
{
public:
    list<string> *Table;
    int size;

    HashChain(int tableSize);
    ~HashChain();
    int MyHashfunc(const string &key);
    void insert(const string &key);
    bool search(const string &key);
    double Load_Factor();
};

HashChain::HashChain(int tableSize)
{
    size = tableSize;
    Table = new list<string>[size];
}

HashChain::~HashChain()
{
    delete[] Table;
}

int HashChain::MyHashfunc(const string &key)
{
    int hash_no = 0;
    int prime_no = 53;
    for (int i = 0; i < key.size(); i++)
    {
        hash_no = (hash_no * prime_no + key[i]) % size;
    }
    return hash_no % size;
}

void HashChain::insert(const string &key)
{
    int idx = MyHashfunc(key);
    Table[idx].push_back(key);
}

bool HashChain::search(const string &key)
{
    int idx = MyHashfunc(key);
    for (auto it = Table[idx].begin(); it != Table[idx].end(); ++it)
    {
        if (*it == key)
        {
            return true;
        }
    }
    return false;
}

double HashChain::Load_Factor()
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += Table[i].size();
    }
    return total / (size * 1.0);
}

class Spellchecking
{
public:
    HashChain ht;

    Spellchecking(int tableSize);
    string Convert_To_Lowercase(string str);
    string Convert_To_Uppercase(string str);
    bool Chk_alphabet(const string &word);
    void Load_Words(const string &filename);
    void Overwrite_File(const string &filename);
};

Spellchecking::Spellchecking(int tableSize) : ht(tableSize) {}

string Spellchecking::Convert_To_Lowercase(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }
    return str;
}

string Spellchecking::Convert_To_Uppercase(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }
    return str;
}

bool Spellchecking::Chk_alphabet(const string &word)
{
    for (int i = 0; i < word.size(); i++)
    {
        if (!(word[i] >= 'a' && word[i] <= 'z') && !(word[i] >= 'A' && word[i] <= 'Z'))
        {
            return false;
        }
    }
    return true;
}

void Spellchecking::Load_Words(const string &filename)
{
    ifstream file(filename);
    string word;

    while (file >> word)
    {
        string lowercase_word = Convert_To_Lowercase(word);
        if (Chk_alphabet(lowercase_word))
        {
            ht.insert(lowercase_word);
        }
    }
    file.close();
}

void Spellchecking::Overwrite_File(const string &filename)
{
    ifstream infile(filename);
    if (!infile.is_open())
    {
        cout << "[WARNING!] File couldn't open" << endl;
        return;
    }

    stringstream text_modified;
    string line;

    while (getline(infile, line))
    {
        stringstream ss(line);
        string word;

        while (ss >> word)
        {
            string cleaned_word = Convert_To_Lowercase(word);

            if (Chk_alphabet(cleaned_word))
            {
                if (!ht.search(cleaned_word))
                {
                    word = Convert_To_Uppercase(word);
                }
            }

            text_modified << word << " ";
        }

        text_modified << endl;
    }

    infile.close();

    ofstream outfile(filename, ios::trunc);
    if (!outfile.is_open())
    {
        cout << "[WARNING!] File couldn't open " << endl;
        return;
    }

    outfile << text_modified.str();
    outfile.close();
}

int main()
{
    int table_size = 9973;

    Spellchecking SC(table_size);

    SC.Load_Words("Assig03_wordlist.txt");

    double loadFactor = SC.ht.Load_Factor();
    cout << "Load Factor is: " << loadFactor << endl;

    SC.Overwrite_File("input.txt");
    cout << "The file has been successfully overwritten with words not found in the HashTable converted to Uppercase." << endl;

    return 0;
}
