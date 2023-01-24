#include <bits/stdc++.h>
using namespace std;

struct PriorityQueue
{
    int value;
    int priority;
};

const int maxsize = 5;
PriorityQueue q[maxsize];
int size = -1;

void enqueue(int data, int priority)
{
    if (size == maxsize - 1)
    {
        cout << "Priority queue is full!\n";
        return;
    }
    size++;
    q[size].value = data;
    q[size].priority = priority;
}

void dequeue()
{
    int idx = 0, highest_priority = q[0].priority;
    for (int i = 1; i <= size; i++)
    {
        if (q[i].priority > highest_priority)
        {
            highest_priority = q[i].priority;
            idx = i;
        }
    }
    cout << "Element with highest Priority is: " << q[idx].value << endl;
    for (int i = idx; i < size; i++)
    {
        q[i] = q[i + 1];
    }
    size--;
}

int main()
{
    enqueue(5, 1);
    enqueue(15, 7);
    enqueue(45, 3);
    enqueue(55, 4);

    dequeue();
    dequeue();
    dequeue();
    dequeue();

    return 0;
}