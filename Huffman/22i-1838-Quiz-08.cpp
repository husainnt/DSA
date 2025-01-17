#include <iostream>
#include <string>
#include <map>

using namespace std;

class Huffman
{
public:
    char data;
    Huffman *left;
    Huffman *right;

    Huffman(char c)
    {
        this->data = c;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void insertNode(Huffman *&root, char ch, const string &str)
{
    if (!root)
    {
        root = new Huffman('\0');
    }

    Huffman *current = root;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == '0')
        {
            if (!current->left)
            {
                current->left = new Huffman('\0');
            }
            current = current->left;
        }
        else if (str[i] == '1')
        {
            if (!current->right)
            {
                current->right = new Huffman('\0');
            }
            current = current->right;
        }
    }
    current->data = ch;
}

void printTree(Huffman *root, string str = "")
{
    if (!root)
        return;

    if (root->data != '\0')
    {
        cout << str << " : " << root->data << endl;
    }

    printTree(root->left, str + "0");
    printTree(root->right, str + "1");
}

int main()
{
    map<char, string> input = {
        {'a', "00"},
        {'b', "001"},
        {'C', "010"},
        {'d', "1100"}};

    Huffman *root = nullptr;

    for (auto x : input)
    {
        char ch = x.first;
        string str = x.second;

        insertNode(root, ch, str);
    }

    cout << "The HUFFMAN TREE is : " << endl;
    printTree(root);

    return 0;
}
