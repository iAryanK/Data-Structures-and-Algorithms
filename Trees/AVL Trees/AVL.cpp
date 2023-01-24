#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;

    Node(int data)
    {
        this->key = data;
        this->height = 1;
        this->left = NULL;
        this->right = NULL;
    }
};

void preOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int getHeight(Node *n)
{
    if (n == NULL)
        return 0;

    return n->height;
}

int getBalanceFactor(Node *n)
{
    if (n == NULL)
        return 0;

    return getHeight(n->left) - getHeight(n->right);
}

struct Node* rightRotate(struct Node* y){
    struct Node* x = y->left;
    struct Node* T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
 
    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;

    return y;
}

Node *insertInBST(Node *node, int key)
{
    if (node == NULL)
    {
        Node *temp = new Node(key);
        return temp;
    }
    if (key < node->key)
        node->left = insertInBST(node->left, key);
    else if (key > node->key)
        node->right = insertInBST(node->right, key);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    // left left case
    if (bf > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (bf < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int main()
{
    Node *root = NULL;
    // root = insertInBST(root, 1);
    // root = insertInBST(root, 2);
    // root = insertInBST(root, 4);
    // root = insertInBST(root, 5);
    // root = insertInBST(root, 6);
    // root = insertInBST(root, 3);

    root = insertInBST(root, 4);
    root = insertInBST(root, 3);
    root = insertInBST(root, 2);
    root = insertInBST(root, 1);
    preOrderTraversal(root);
    return 0;
}