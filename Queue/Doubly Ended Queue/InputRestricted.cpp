#include <bits/stdc++.h>
using namespace std;

const int N = 5;
int Dequeue[N];
int front = -1;
int rear = -1;

bool isFull()
{
    if (front == (rear + 1) % N)
        return 1;
    return 0;
}

bool isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}

void pushBack(int data)
{
    if (isFull())
    {
        cout << "Dequeue is full!\n";
        return;
    }
    if (front == -1)
    {
        front = rear = 0;
        Dequeue[rear] = data;
    }
    else
    {
        rear = (rear + 1) % N;
        Dequeue[rear] = data;
    }
}

int popFront()
{
    if (isEmpty())
    {
        cout << "Dequeue is Empty!\n";
        return -1;
    }
    int item = Dequeue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
        front = (front + 1) % N;
    return item;
}

int popBack()
{
    if (isEmpty())
    {
        cout << "Dequeue is Empty!\n";
        return -1;
    }
    int item = Dequeue[rear];
    if (rear == front)
    {
        rear = front = -1;
    }
    else if (rear > front)
    {
        if (rear == 0)
            rear = N - 1;
        else
            rear--;
    }
    else
        rear--;

    return item;
}

int main()
{
    pushBack(1);
    pushBack(2);
    pushBack(3);
    pushBack(4);
    pushBack(5);
    if (isFull())
    cout<<"Dequeue is Full!\n";

    cout << popBack() << endl;
    cout << popBack() << endl;
    cout << popBack() << endl;
    cout << popBack() << endl;
    cout<<popFront()<<endl;

    if (isEmpty())
    cout <<"Dequeue is empty!";
    if (isFull())
    cout<<"Dequeue is Full!\n";

    return 0;
}