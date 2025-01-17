#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f, Node *l = nullptr, Node *r = nullptr)
        : ch(c), freq(f), left(l), right(r) {}
};

struct Compare
{
    bool operator()(Node *left, Node *right)
    {
        return left->freq > right->freq;
    }
};

class Huffman
{
public:
    Node *root;

    Huffman() : root(nullptr) {}

    void encode(Node *root, string str, unordered_map<char, string> &huffcode);
    void decode(Node *root, int &idx, string str);
    void build_huff(string str);
};

void Huffman::encode(Node *root, string str, unordered_map<char, string> &huffcode)
{
    if (root == nullptr)
    {
        return;
    }
    // Leaf node
    if (!root->left && !root->right)
    {
        huffcode[root->ch] = str;
    }
    encode(root->left, str + "0", huffcode);
    encode(root->right, str + "1", huffcode);
}

void Huffman::decode(Node *root, int &idx, string str)
{
    if (root == nullptr)
    {
        return;
    }
    // Leaf node
    if (!root->left && !root->right)
    {
        cout << root->ch;
        return;
    }
    idx++;
    if (str[idx] == '0')
    {
        decode(root->left, idx, str);
    }
    else
    {
        decode(root->right, idx, str);
    }
}

void Huffman::build_huff(string str)
{
    // Step 1: Count frequencies of each character
    unordered_map<char, int> freq;
    for (char ch : str)
    {
        freq[ch]++;
    }

    // Step 2: Create a priority queue (min-heap)
    priority_queue<Node *, vector<Node *>, Compare> pq;

    for (auto pair : freq)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    // Step 3: Build the Huffman tree
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum, left, right));
    }

    // The root of the tree
    root = pq.top();

    // Step 4: Generate Huffman codes
    unordered_map<char, string> huffcode;
    encode(root, "", huffcode);

    cout << "Huffman Codes are:\n";
    for (auto pair : huffcode)
    {
        cout << pair.first << " -> " << pair.second << "\n";
    }

    // Step 5: Encode the input string
    string encodedString = "";
    for (char ch : str)
    {
        encodedString += huffcode[ch];
    }

    cout << "Encoded string: " << encodedString << "\n";

    // Step 6: Decode the encoded string
    cout << "Decoded string: ";
    int idx = -1;
    while (idx < (int)encodedString.size() - 1)
    {
        decode(root, idx, encodedString);
    }
    cout << "\n";
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string text;
    cout << "Enter the text to be encoded: " << endl;
    getline(cin, text);
    Huffman huffman;
    huffman.build_huff(text);

    return 0;
}
