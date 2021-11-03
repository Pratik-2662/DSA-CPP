#include <bits/stdc++.h>
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

void inorderOfBtree(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    inorderOfBtree(root->left, v);
    v.push_back(root->data);
    inorderOfBtree(root->right, v);
}

void printInorderOfBtree(vector<int> v)
{
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
}

void convertToBST(Node *root, vector<int> v, int &count)
{
    if (root == NULL)
    {
        return;
    }
    convertToBST(root->left, v, count);
    root->data = v[count];
    count++;
    convertToBST(root->right, v, count);
}

void printBST(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}

int main()
{
    Node *root = createNode(10);
    root->left = createNode(30);
    root->right = createNode(15);
    root->left->left = createNode(20);
    root->left->right = createNode(25);
    root->right->left = createNode(1);
    root->right->right = createNode(5);
    vector<int> v;
    inorderOfBtree(root, v);
    cout << "Inorder of btree is : ";
    printInorderOfBtree(v);
    sort(v.begin(), v.end());
    int count = 0;
    convertToBST(root, v, count);
    cout << "\nInorder of BST Is : ";
    printBST(root);
}