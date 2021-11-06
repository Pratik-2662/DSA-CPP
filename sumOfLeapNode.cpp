#include <iostream>
#include <queue>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
Node *createNode(int value)
{
    Node *temp = new Node();
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void findSumofLeaf(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is Empty";
        return;
    }
    queue<pair<Node *, int>> q;
    map<int, int> m;
    pair<Node *, int> p;
    q.push({root, 1});
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (m.find(p.second) == m.end())
        {
            m[p.second] = 0;
        }
        if (p.first->left == NULL && p.first->right == NULL)
        {
            m[p.second] = m[p.second] + p.first->data;
        }
        if (p.first->left)
        {
            q.push({p.first->left, p.second + 1});
        }
        if (p.first->right)
        {
            q.push({p.first->right, p.second + 1});
        }
    }
    for (auto i : m)
    {
        cout << "Sum of Level " << i.first << " = " << i.second << endl;
    }
}
int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->right->right->left = createNode(10);
    // root->right->right->left->left = createNode(16);
    // root->right->right->left->right = createNode(17);
    root->right->right->right = createNode(11);
    root->right->right->right->left = createNode(18);
    root->right->right->right->right = createNode(19);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->right->right = createNode(9);
    root->left->right->right->left = createNode(14);
    root->left->right->right->right = createNode(15);
    root->left->left->right = createNode(8);
    root->left->left->right->right = createNode(12);
    root->left->left->right->left = createNode(13);
    findSumofLeaf(root);
    return 0;
}