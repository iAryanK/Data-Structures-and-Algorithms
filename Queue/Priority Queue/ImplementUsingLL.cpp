#include <bits/stdc++.h>
using namespace std;

struct PriorityQueue
{
    int value;
    int priority;
    PriorityQueue *next;

    PriorityQueue(int data, int priority)
    {
        this->value = data;
        this->priority = priority;
        this->next = NULL;
    }
};

PriorityQueue *head = NULL;

void enqueue(int data, int priority)
{
    PriorityQueue *newnode = new PriorityQueue(data, priority);
    if (head == NULL)
        head = newnode;
    else if (head->priority < newnode->priority)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        PriorityQueue *temp = head;
        PriorityQueue *curr = NULL;
        while (temp->priority > newnode->priority && temp != NULL)
        {
            curr = temp;
            temp = temp->next;
        }

        if (temp != NULL)
        {
            newnode->next = temp;
            curr->next = newnode;
        }
        else
        {
            curr->next = newnode;
        }
    }
}

void dequeue()
{
    if (head == NULL)
    {
        cout << "Priority Queue is empty!";
        return;
    }
    PriorityQueue *temp = head;
    head = head->next;
    delete temp;
}

void printQueue()
{
    PriorityQueue *temp = head;
    while (temp != NULL)
    {
        cout << "priority of " << temp->value << " is " << temp->priority << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    enqueue(5, 1);
    enqueue(15, 7);
    enqueue(45, 3);
    enqueue(55, 4);

    printQueue();
    dequeue();
    printQueue();
    
    return 0;
}