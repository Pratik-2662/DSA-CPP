#include <iostream>
#include <queue>
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
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

Node *insertNode(Node *head, int value)
{
    if (head == NULL)
    {
        Node *temp = createNode(value);
        head = temp;
        return head;
    }
    queue<Node *> q;
    q.push(head);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left == NULL)
        {
            temp->left = createNode(value);
            return head;
        }
        else
        {
            q.push(temp->left);
        }
        if (temp->right == NULL)
        {
            temp->right = createNode(value);
            return head;
        }
        else
        {
            q.push(temp->right);
        }
    }
}

void printLevelOrder(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(head);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);

    cout << "Level order traversal of tree : ";
    printLevelOrder(root);
    cout << "\nInorder Traversal of Binary Tree is : ";
    print(root);
    // cout << "\nAfter insertion our Binary Tree is : ";
    // root = insertNode(root, 5);
    // print(root);
    return 0;
}