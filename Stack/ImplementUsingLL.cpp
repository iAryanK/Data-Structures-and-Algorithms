#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

void traverseLL(Node *head)
{
    cout << "\nPrinting the elements of the list...\n";
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void push(Node *&head, int value)
{
    Node *newnode = new Node(value);
    newnode->next = head;
    head = newnode;
}

void pop(Node *&head)
{
    if (head == NULL)
    {
        cout << "\nUnderflow\n";
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

int main()
{
    Node *head = NULL;

    int choice;
    do
    {
        cout << "\n1. Push an element";
        cout << "\n2. Pop an element";
        cout << "\n3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int value;
            cout << "\nEnter the element you want to insert: ";
            cin >> value;
            push(head, value);
            break;

        case 2:
            pop(head);
            break;

        default:
            cout << "\nExits\n";
        }
    } while (choice != 3);

    traverseLL(head);

    return 0;
}