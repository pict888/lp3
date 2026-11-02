
#include <iostream>
#include <queue>
#include <map>
#include <string>
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

    for (char ch : text)
        freq[ch]++;

    priority_queue<Node *, vector<Node *>, Compare> pq;

    for (auto p : freq)
        pq.push(new Node(p.first, p.second));

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

    cout << "\nHuffman Codes:\n";
    printCodes(pq.top(), "", codes);

    cout << "\nEncoded string: ";
    for (char ch : text)
        cout << codes[ch];

    cout << endl;
    return 0;
}
