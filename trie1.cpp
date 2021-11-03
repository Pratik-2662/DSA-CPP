#include <iostream>
using namespace std;
class Trie
{
public:
    Trie *children[26];
    bool isEnd;
    Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
            isEnd = false;
        }
    }
};
Trie *getNode()
{
    Trie *root = new Trie();
    return root;
}
void insert(Trie *root, string value)
{
    Trie *temp = root;
    for (int i = 0; i < value.length(); i++)
    {
        int index = value[i] - 'a';
        if (!temp->children[index])
        {
            temp->children[index] = getNode();
        }
        temp = temp->children[index];
    }
    temp->isEnd = true;
}
bool search(Trie *root, string value)
{
    Trie *temp = root;
    for (int i = 0; i < value.length(); i++)
    {
        int index = value[i] - 'a';
        if (!temp->children[index])
        {
            return false;
        }
        temp = temp->children[index];
    }
    return temp->isEnd;
}

int main()
{
    Trie *root = getNode();

    string arr[] = {"this", "is", "first", "trie"};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        insert(root, arr[i]);
    }
    search(root, "trie") ? cout << "Given word is present" : cout << "Given word is not Present";
    return 0;
}