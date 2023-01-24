#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *previous;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }
};

void printDLL(Node *head, Node *tail)
{
    cout << "\nPrinting the data of the list...\n";
    Node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != NULL);

    cout << "\nPrinting in reverse...\n";
    temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->previous;
    } while (temp != NULL);
}

void insertionAtTail(Node *&head, Node *&tail)
{
    cout << "\nInserting data at tail in the linked list...\n";
    cout << "\nEnter the number of nodes you want to insert in the list: ";
    int n;
    cin >> n;

    if (head == NULL)
    {
        Node *newnode = new Node(rand() % 10);
        head = newnode;
        tail = newnode;
        n--;
    }

    while (n--)
    {
        Node *newnode = new Node(rand() % 10);
        tail->next = newnode;
        newnode->previous = tail;
        tail = newnode;
    }
}

void DeletionAtTail(Node *&head, Node *&tail)
{
    cout << "\nDeleting data from tail in the linked list...\n";

    Node *temp = tail;
    tail = tail->previous;

    tail->next = NULL;
    delete temp;
}

void DeletionAtHead(Node *&head, Node *&tail)
{
    cout << "\nDeleting node at head of the linked list...\n";

    Node *temp = head;
    head = head->next;
    head->previous = NULL;
    delete temp;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertionAtTail(head, tail);
    printDLL(head, tail);

    // DeletionAtTail(head);
    // printDLL(head);

    DeletionAtHead(head, tail);
    printDLL(head, tail);
    return 0;
}