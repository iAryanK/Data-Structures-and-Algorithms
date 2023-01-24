#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void printCLL(Node *head)
{
    cout << "\nPrinting elements of the circular list...\n";
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

void insertionAtTail(Node *&head, Node *&tail)
{
    cout << "\nInserting Data at tail...\n";

    char c = 'Y';
    while (c == 'y' || c == 'Y')
    {
        cout << "Enter the data you want to insert: ";
        int data;
        cin >> data;

        if (head == NULL)
        {
            Node *newnode = new Node(data);
            newnode->next = newnode;
            head = newnode;
            tail = newnode;
        }
        else
        {
            Node *newnode = new Node(data);
            tail->next = newnode;
            newnode->next = head;
            tail = newnode;
        }
        cout << "Do you want to insert more data (Y/N): ";
        cin >> c;
    }
}

void insertionInHead(Node *&head, Node *&tail)
{
    cout << "\nInserting Data at head...\n";

    char c = 'Y';
    while (c == 'y' || c == 'Y')
    {
        cout << "Enter the data you want to insert: ";
        int data;
        cin >> data;

        if (head == NULL)
        {
            Node *newnode = new Node(data);
            newnode->next = newnode;
            head = newnode;
            tail = newnode;
        }
        else
        {
            Node *newnode = new Node(data);
            newnode->next = head;
            head = newnode;
        }
        cout << "Do you want to insert more data (Y/N): ";
        cin >> c;
    }
    tail->next = head;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    // insertionAtTail(head, tail);
    // printCLL(head);

    insertionInHead(head, tail);
    printCLL(head);

    return 0;
}