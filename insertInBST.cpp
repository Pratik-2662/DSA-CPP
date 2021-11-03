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
    return temp;
}
Node *insertNode(Node *root, int value)
{
    if (root == NULL)
    {
        root = createNode(value);
        return root;
    }
    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    if (value > root->data)
    {
        root->right = insertNode(root->right, value);
    }
    return root;
}
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    Node *root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(10);
    root->left->left = createNode(1);
    root->right->left = createNode(6);
    root->right->right = createNode(12);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 9);
    root = insertNode(root, 5);
    root = insertNode(root, 8);
    root = insertNode(root, 11);
    inorder(root);

    return 0;
}