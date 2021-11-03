#include <iostream>
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
}
Node *ancesstor(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (n1 < root->data && n2 < root->data)
    {
        return ancesstor(root->left, n1, n2);
    }
    if (n1 > root->data && n2 > root->data)
    {
        return ancesstor(root->right, n1, n2);
    }
    return root;
}

bool checkBST(Node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    if (root->left != NULL && root->left->data > root->data)
    {
        return 0;
    }
    if (root->right != NULL && root->right->data < root->data)
    {
        return 0;
    }
    if (!checkBST(root->left) || !checkBST(root->right))
    {
        return 0;
    }
    return 1;
}

int main()
{
    Node *root = createNode(20);
    root->left = createNode(8);
    root->right = createNode(22);
    root->left->left = createNode(4);
    root->left->right = createNode(12);
    root->left->right->left = createNode(10);
    root->left->right->right = createNode(14);
    checkBST(root) ? cout << "Yes" : cout << "No";
}