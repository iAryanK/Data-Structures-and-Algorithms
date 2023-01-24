#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *lc;
    Node *rc;

    Node(int data)
    {
        this->data = data;
        this->lc = NULL;
        this->rc = NULL;
    }
};

void InorderTraversal(Node *ptr)
{
    if (ptr != NULL)
    {
        InorderTraversal(ptr->lc);
        cout << ptr->data << " ";
        InorderTraversal(ptr->rc);
    }
}

void PreorderTraversal(Node *ptr)
{
    if (ptr != NULL)
    {
        cout << ptr->data << " ";
        PreorderTraversal(ptr->lc);
        PreorderTraversal(ptr->rc);
    }
}

void PostorderTraversal(Node *ptr)
{
    if (ptr != NULL)
    {
        PostorderTraversal(ptr->lc);
        PostorderTraversal(ptr->rc);
        cout << ptr->data << " ";
    }
}


Node *insertInBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
        root->rc = insertInBST(root->rc, data);
    else
        root->lc = insertInBST(root->lc, data);
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertInBST(root, data);
        cin>>data;
    }
}

int main()
{
    Node *root = NULL;
    cout<<"Enter data to create BST...\n";
    takeInput(root);
    cout<<"\nPrinting inOrder Traversal...\n";
    InorderTraversal(root);
    cout<<"\nPrinting preOrder Traversal...\n";
    PreorderTraversal(root);
    cout<<"\nPrinting postOrder Traversal...\n";
    PostorderTraversal(root);
    return 0;
}