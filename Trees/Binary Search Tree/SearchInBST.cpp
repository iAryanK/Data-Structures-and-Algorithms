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

void inOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->lc);
        cout << root->data << ' ';
        inOrderTraversal(root->rc);
    }
}

Node *insertInBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data < root->data)
        root->lc = insertInBST(root->lc, data);
    else
        root->rc = insertInBST(root->rc, data);

    return root;
}

// Recursive Search 
bool searchInBSTrecursive(Node* root, int x){
    if (root == NULL)
    return false;
    if (root->data == x)
    return true;

    if (root->data>x)
    return searchInBSTrecursive(root->lc, x);
    else
    return searchInBSTrecursive(root->rc, x);
}

// Iterative Search 
bool searchInBSTiterative(Node* root, int x)
{
    while (root!= NULL)
    {
        if (root->data == x)
        return true;
        if (root->data>x)
        root = root->lc;
        else
        root = root->rc;
    }
    return false;
}

int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST...\n";

    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertInBST(root, data);
        cin >> data;
    }

    cout << "\nPrinting inOrder Traversal...\n";
    inOrderTraversal(root);

    cout<<"\nEnter the element you want to search: ";
    int x; cin>>x;
    if (searchInBSTiterative(root, x))
    cout<<"Element Found!";
    else
    cout<<"Element not found!";

    return 0;
}