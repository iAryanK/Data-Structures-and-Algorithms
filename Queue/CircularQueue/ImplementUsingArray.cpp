#include <bits/stdc++.h>
using namespace std;

const int N = 5;
int Queue[N];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if ((front == 0 && rear == N - 1) || (front == rear + 1))
    {
        cout << "Queue is full";
        return;
    }
    else if (front == -1)
    {
        front = rear = 0;
        Queue[rear] = data;
    }
    else if (rear == N - 1)
    {
        rear = 0;
        Queue[rear] = data;
    }
    else
    {
        rear = rear + 1;
        Queue[rear] = data;
    }
    cout<<data<<" is enqueued.\n";
}

int Dequeue()
{
    if (front == -1)
    {
        cout << "Queue is empty!";
        return -1;
    }
    else if (front == rear)
    {
        int item = Queue[front];
        front = rear = -1;
        return item;
    }
    else if (front == N - 1)
    {
        front = 0;
    }
    else {
        int item = Queue[front];
        front++;
        return item;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    cout<<Dequeue()<<endl;
    enqueue(60);
    enqueue(70);
    // cout<<Dequeue()<<endl;
    // cout<<Dequeue()<<endl;

    return 0;
}