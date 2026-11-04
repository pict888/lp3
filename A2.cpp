
#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

void printCodes(Node *root, string code, map<char, string> &codes)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        if (code == "")
            code = "0";

        codes[root->ch] = code;
        cout << root->ch << " : " << code << endl;
        return;
    }

    printCodes(root->left, code + "0", codes);
    printCodes(root->right, code + "1", codes);
}

int main()
{
    string text;
    map<char, int> freq;
    map<char, string> codes;

    cout << "Enter text: ";
    getline(cin, text);

    if (text.empty())
    {
        cout << "Empty input!";
        return 0;
    }

    // Calculate frequency
    for (char ch : text)
        freq[ch]++;

    // Display frequency
    cout << "\nCharacter Frequencies:\n";
    for (auto p : freq)
        cout << p.first << " : " << p.second << endl;

    // Create Min Priority Queue
    priority_queue<Node *, vector<Node *>, Compare> pq;

    for (auto p : freq)
        pq.push(new Node(p.first, p.second));

    // Build Huffman Tree
    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();

        Node *right = pq.top();
        pq.pop();

        Node *parent = new Node('$', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    // Generate Huffman Codes
    cout << "\nHuffman Codes:\n";
    printCodes(pq.top(), "", codes);

    // Encode original text
    cout << "\nEncoded String: ";
    for (char ch : text)
        cout << codes[ch];

    cout << endl;

    return 0;
}
