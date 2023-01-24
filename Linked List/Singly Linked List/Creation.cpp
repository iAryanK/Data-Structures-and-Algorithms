#include <bits/stdc++.h>
using namespace std;

// creating and defining structure 'Node'
struct Node
{
    int data;
    Node *next;
};

// printing the data in list by traversing the nodes
void printLL(Node *head)
{
    cout << "Printing Data of List...\n";
    Node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != NULL);
}

// taking user input and linking the nodes in list
Node *createLL(Node *head, int n)
{
    cout << "Creating Linked list...\nEnter data: ";

    // if there is no node in the list...i.e. list is empty, we create a node and make it the 'head'
    if (head == NULL)
    {
        int data;
        cin >> data;
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        head = newNode;
        n--;
    }

    Node *temp = head;

    while (n--)
    {
        int data;
        cin >> data;
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

int main()
{
    Node *head = NULL;

    cout << "Enter Number of Nodes: ";
    int n;
    cin >> n;

    head = createLL(head, n);

    printLL(head);

    return 0;
}