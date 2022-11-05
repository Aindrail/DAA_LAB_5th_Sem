/*
Huffman coding assigns variable length codewords to fixed length input characters
based on their frequencies/probabilities of occurrence. Given an array of characters
along with their frequency of occurrences. Write a menu driven programming to
perform the following functions.

HUFFMAN CODE GEBERATION MENU

0. Quit
1. Input n unique characters with their frequencies into an array
2. Display the Array
3. Generate Huffman Tree and Traverse the tree with pre-order.
4. Generate Huffman Codes for n characters and display the same.
5. Compare Huffman code with Fixed-Length Code
*/

#include<bits/stdc++.h>
using namespace std;

struct node
{
    char ch;
    int freq;
    node *left, *right;
    node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct compare
{
    bool operator()(node *l, node *r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(struct node *root, string str)
{
    if (!root)
        return;
    if (root->ch != '$')
        cout << root->ch << ": " << str << " ";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size)
{
    struct node *left, *right, *top;
    priority_queue<node *, vector<node *>, compare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new node(data[i], freq[i]));
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}

int main()
{
    int n, ch;
    char data[10];
    int freq[10];
    cout << "HUFFMAN CODE GEBERATION MENU " << endl;
    cout << "0. Quit" << endl;
    cout << "1. Input n unique characters with their frequencies into an array" << endl;
    cout << "2. Display the Array" << endl;
    cout << "3. Generate Huffman Tree and Traverse the tree with pre-order." << endl;
    cout << "4. Generate Huffman Codes for n characters and display the same." << endl;
    cout << "5. Compare Huffman code with Fixed-Length Code" << endl;
    do
    {
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 0:
            break;
        case 1:
            cout << "Enter the number of characters: ";
            cin >> n;
            cout << "Enter the characters: ";
            for (int i = 0; i < n; i++)
                cin >> data[i];
            cout << "Enter the frequencies: ";
            for (int i = 0; i < n; i++)
                cin >> freq[i];
            break;
        case 2:
            cout << "The array is: " << endl;
            for (int i = 0; i < n; i++)
                cout << data[i] << " " << freq[i] << endl;
            break;
        case 3:
            cout << "The Huffman Tree is: " << endl;
            HuffmanCodes(data, freq, n);
            break;
        case 4:
            cout << "The Huffman Codes are: " << endl;
            HuffmanCodes(data, freq, n);
            break;
        case 5:
            cout << "The Huffman Codes are: " << endl;
            HuffmanCodes(data, freq, n);
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (ch != 0);
    return 0;
}
