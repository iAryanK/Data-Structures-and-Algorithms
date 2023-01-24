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

void printLL(Node *head)
{
    cout << "\nPrinting the data in the list...\n";
    Node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != NULL);
}

void insertAtHead(Node *&head)
{
    cout << "\nInserting data at the beginning of list...\n";

    char c = 'Y';
    while (c == 'Y' || c == 'y')
    {
        cout << "Enter Data you want to insert: ";
        int data;
        cin >> data;
        Node *newnode = new Node(data);
        newnode->next = head;
        head = newnode;

        cout << "Wanna insert more data into the list? (Y/N): ";
        cin >> c;
    }
}

void insertAtTail(Node *&head)
{
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    cout << "\nInserting data at the end of the list...\n";

    char c = 'Y';

    while (c == 'Y')
    {
        cout << "Enter the element you want to insert: ";
        int data;
        cin >> data;
        Node *newnode = new Node(data);
        temp->next = newnode;
        temp = newnode;

        cout << "Wanna insert more data at the tail (Y/N): ";
        cin >> c;
    }
}

void deletionAtHead(Node*& head) {
    cout<<"\nDeleting the first element in the linked list...\n";
    Node* nodeToDelete = head;
    head = head->next;
    
    delete nodeToDelete;
}

void deletionAtTail(Node*& head) {
    cout<<"\nDeleting the last element in the linked list...\n";

    Node *temp = head;
    Node *curr = NULL;
    while (temp->next != NULL)
    {
        curr = temp;
        temp = temp->next;
    }

    Node* nodeToDelete = temp;
    curr->next = NULL;
    
    delete nodeToDelete;
}


int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head);
    printLL(head);

    insertAtTail(head);
    printLL(head);

    deletionAtHead(head);
    printLL(head);

    deletionAtTail(head);
    printLL(head);

    return 0;
}