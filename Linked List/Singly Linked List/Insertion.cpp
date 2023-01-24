#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void printLL(Node *head)
{
    cout << "Printing the list...\n";
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertAtHead(Node *&head)
{
    cout << "\nInserting data at the beginning of the list...\n";
    char c = 'Y';

    while (c == 'Y' || c == 'y')
    {
        Node *newNode = new Node;

        cout << "Enter the element to be added in the list: ";
        cin >> newNode->data;
        newNode->next = head;
        head = newNode;

        cout << "Wanna add more element to the list? (Y/N): ";
        cin >> c;
    }
}

void insertAtTail(Node *&head)
{
    cout << "\nInserting data at the end of the list...\n";
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    char c = 'Y';

    while (c == 'Y' || c == 'y')
    {
        Node *newNode = new Node;

        cout << "Enter the element to be added in the list: ";
        cin >> newNode->data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;

        cout << "Wanna add more element to the list? (Y/N): ";
        cin >> c;
    }
}

void insertByPosition(Node *&head)
{
    Node *temp = head;

    cout << "\nEnter position at which you want to insert data: ";
    int pos;
    cin >> pos;

    // insert at position 1 i.e. head
    if (pos == 1)
    {
        insertAtHead(head);
        return;
    }

    Node *curr;
    for (int i = 1; i < pos; i++)
    {
        curr = temp;
        temp = temp->next;
    }

    Node *newnode = new Node;
    cout << "Enter the element you want to insert: ";
    cin >> newnode->data;
    newnode->next = curr->next;
    curr->next = newnode;
}

void insertByValue(Node *&head)
{
    Node *temp = head;

    cout << "\nEnter the value after which you want to insert the data: ";
    int value;
    cin >> value;

    while (temp->data != value)
        temp = temp->next;

    Node *newnode = new Node;
    cout << "Enter the data you want to insert: ";
    cin >> newnode->data;

    newnode->next = temp->next;
    temp->next = newnode;
}

int main()
{
    Node *head = NULL;

    insertAtHead(head);
    printLL(head);

    insertAtTail(head);
    printLL(head);

    insertByPosition(head);
    printLL(head);

    insertByValue(head);
    printLL(head);

    return 0;
}