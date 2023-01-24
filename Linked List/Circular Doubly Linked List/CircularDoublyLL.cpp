#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void TraverseLL(Node *head, Node *tail)
{
    cout << "\nPrinting the data in the list...\n";
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << "\nPrinting the list in reverse order\n";
    temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->prev;
    } while (temp != tail);
}

void insertAtHead(Node *&head, Node *&tail)
{
    cout << "\nInserting data at head of the Circular doubly linked list...\n";
    int n;
    cout << "Enter number of Nodes You want to insert: ";
    cin >> n;

    if (head == NULL)
    {
        Node *newnode = new Node(rand() % 10);
        newnode->prev = newnode;
        newnode->next = newnode;
        head = newnode;
        tail = newnode;
        n--;
    }
    while (n--)
    {
        Node *newnode = new Node(rand() % 10);
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = tail;
        tail->next = newnode;
        head = newnode;
    }
}

void insertAtTail(Node *&head, Node *&tail)
{
    cout << "\nInserting data at the tail of circular doubly linked list...\n";
    int n;
    cout << "Enter number of nodes you want to insert: ";
    cin >> n;

    if (head == NULL)
    {
        Node *newnode = new Node(rand() % 10);
        newnode->prev = newnode;
        newnode->next = newnode;
        head = newnode;
        tail = newnode;
        n--;
    }
    while (n--)
    {
        Node *newnode = new Node(rand() % 10);
        newnode->prev = tail;
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
        head->prev = tail;
    }
}

void deleteAtHead(Node *&head, Node *&tail)
{
    cout << "\nDeleting the element present at head...\n";
    Node *nodeToDelete = head;
    head = head->next;
    head->prev = tail;
    tail->next = head;
    delete nodeToDelete;
}

void deleteAtTail(Node *&head, Node *&tail)
{
    cout << "\nDeleting element present at the tail of the list...\n";
    Node *nodeToDelete = tail;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete nodeToDelete;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail);
    TraverseLL(head, tail);

    insertAtTail(head, tail);
    TraverseLL(head, tail);

    deleteAtHead(head, tail);
    TraverseLL(head, tail);

    deleteAtTail(head, tail);
    TraverseLL(head, tail);

    return 0;
}