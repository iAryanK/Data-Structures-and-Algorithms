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
    cout << "\nPrinting data in the list...\n";
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

void insertionAtTail(Node *&head)
{
    cout << "\nInserting data at tail...\n";


    cout << "\nEnter the number of nodes you want to insert: ";
    int n;
    cin >> n;

    if (head == NULL) {
        Node* newnode = new Node(rand()%10);
        newnode->next = newnode;
        head = newnode;
        n--;
    }

    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    while (n--)
    {
        
        Node *newnode = new Node(rand()%10);
        temp->next = newnode;
        temp = newnode;
    }
    temp->next = head;
}

void DeletionAtHead(Node *&head)
{
    cout << "\nDeleting node at head...\n";
    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = head->next;
    Node *nodeToDelete = head;
    head = head->next;

    delete nodeToDelete;
}

void DeletionAtTail(Node *&head)
{
    cout << "\nDeleting node at head...\n";
    Node *temp = head;
    Node *curr = NULL;
    while (temp->next != head) {
        curr = temp;
        temp = temp->next; 
    }

    curr->next = head;

    delete temp;
}

int main()
{
    Node *head = NULL;

    insertionAtTail(head);
    printCLL(head);

    // DeletionAtHead(head);
    // printCLL(head);

    DeletionAtTail(head);
    printCLL(head);

    return 0;
}