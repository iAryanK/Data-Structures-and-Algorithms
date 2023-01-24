#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *lc;
    Node *rc;
};

void build_tree(Node *ptr, int item)
{
    char option;
    
    if (ptr != NULL)
    {
        ptr->data = item;
        cout << "Want to enter left child?(Y/N)";
        cin >> option;

        if (option == 'Y')
        {
            cout << "Enter item: ";
            int item;
            cin >> item;
            Node *lcptr = new Node;
            ptr->lc = lcptr;
            build_tree(lcptr, item);
        }
        else
        {
            Node *lcptr = NULL;
            ptr->lc = NULL;
            build_tree(lcptr, NULL);
        }

        cout << "Want to enter right child?(Y/N)";
        cin >> option;
        if (option == 'Y')
        { 
            cout << "Enter item: ";
            int item;
            cin >> item;
            Node *rcptr = new Node;
            ptr->rc = rcptr;
            build_tree(rcptr, item);
        }
        else
        {
            Node *rcptr = NULL;
            ptr->rc = NULL;
            build_tree(rcptr, NULL);
        }
    }
}

/*
Node *buildTree(Node *root)
{
    cout << "Enter data: ";
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for inserting in left of " << data << endl;
    root->lc = buildTree(root->lc);

    cout << "Enter data for inserting in right of " << data << endl;
    root->rc = buildTree(root->rc);

    return root;
}
*/

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

int main()
{
    Node *root = new Node;
    cout<<"Enter data of root node: ";
    int data; cin>>data;
    build_tree(root, data);

    cout << "\nPrinting inOrder Traversal...\n";
    InorderTraversal(root);
    cout << "\nPrinting preOrder Traversal...\n";
    PreorderTraversal(root);
    cout << "\nPrinting postOrder Traversal...\n";
    PostorderTraversal(root);

    return 0;
}