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
        cout << root->data << " ";
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

    if (root->data > data)
        root->lc = insertInBST(root->lc, data);
    else
        root->rc = insertInBST(root->rc, data);

    return root;
}

Node *inorderSuccessor(Node *root)
{
    while (root->lc != NULL)
        root = root->lc;
    cout << "Inorder Successor is " << root->data << endl;
    return root;
}

Node *deleteFromBST(Node *&root, int value)
{
    if (root == NULL)
        return root;

    if (root->data == value)
    {
        // leaf node i.e. node with zero child
        if (root->lc == NULL && root->rc == NULL)
        {
            delete root;
            return NULL;
        }

        // node with single child
        if (root->lc != NULL && root->rc == NULL) // left child exists
        {
            Node *temp = root->lc;
            delete root;
            return temp;
        }
        else if (root->rc != NULL && root->lc == NULL) // right child exists
        {
            Node *temp = root->rc;
            delete root;
            return temp;
        }

        // Node with 2 children
        if (root->lc != NULL && root->rc != NULL)
        {
            int mini = inorderSuccessor(root->rc)->data;
            root->data = mini;
            root->rc = deleteFromBST(root->rc, mini);
            return root;
        }
    }
    else if (root->data > value)
    {
        root->lc = deleteFromBST(root->lc, value);
        return root;
    }
    else
    {
        root->rc = deleteFromBST(root->rc, value);
        return root;
    }
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to insert in BST...\n";
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertInBST(root, data);
        cin >> data;
    }

    cout << "\nPrinting the inorder Traversal...\n";
    inOrderTraversal(root);

    cout << "\nEnter the data you want to delete: ";
    int x;
    cin >> x;
    root = deleteFromBST(root, x);

    cout << "\nPrinting the inorder Traversal...\n";
    inOrderTraversal(root);

    return 0;
}