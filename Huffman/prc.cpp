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

void insertNode(Huffman *&root, char ch, unsigned int code, int length)
{
    if (!root)
    {
        root = new Huffman('\0');
    }

    Huffman *current = root;
    for (int i = length - 1; i >= 0; --i)
    {
        if ((code & (1 << i)) == 0)
        {
            if (!current->left)
            {
                current->left = new Huffman('\0');
            }
            current = current->left;
        }
        else
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
    map<char, string> input = {{'a', "00"}, {'b', "001"}, {'C', "010"}, {'d', "1100"}};

    Huffman *root = nullptr;

    for (auto x : input)
    {
        char ch = x.first;
        string str = x.second;

        int ans = 0;
        for (char bit : str)
        {
            ans = (ans << 1) | (bit - '0');
        }

        insertNode(root, ch, ans, str.length());
    }

    cout << "The HUFFMAN TREE is : " << endl;
    printTree(root);

    return 0;
}
