#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int arr[N];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if (rear == -1)
    {
        front = rear = 0;
        arr[rear] = data;
    }
    else if (rear == N-1)
    {
        cout<<"Queue is full!";
    }
    else
    {
        rear++;
        arr[rear] = data;
    }
}

int Dequeue()
{
    if (front == -1)
    {
        cout<<"Queue is empty!";
        return -1;
    }
    else if (front == rear)
    {
        int item = arr[front];
        front = rear = -1;
        return item;
    }
    else{
        int item = arr[front];
        front++;
        return item;
    }
}

int main(){
    enqueue(5);
    enqueue(15);
    enqueue(56);
    enqueue(57);
    enqueue(58);
    cout<<endl<<Dequeue();
    
    return 0;
}