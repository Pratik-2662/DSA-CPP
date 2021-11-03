#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    Node *left = NULL;
    int data = 0;
    Node *right = NULL;
};
Node *createNode(int value)
{
    Node *temp = new Node();
    temp->left = NULL;
    temp->data = value;
    temp->right = NULL;
    return temp;
}

void inorderBTree(Node *root, vector<int> &v)
{
    if (root = NULL)
    {
        return;
    }
    inorderBTree(root->left, v);
    v.push_back(root->data);
    inorderBTree(root->right, v);
}
bool isBST(vector<int> v)
{
    for (auto i = v.begin(); i < v.end() - 1; i++)
    {
        if (*i > *(i + 1))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    Node *root = createNode(3);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(1);
    root->left->right = createNode(4);
    vector<int> v;
    inorderBTree(root, v);
    isBST(v) ? cout << "BST" : cout << "Not a BST";
}