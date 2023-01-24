#include <bits/stdc++.h>
using namespace std;

int arr[10];
int top = -1;

void printArray()
{
    cout << "\nPrinting elements of Array...\n";
    int idx = 0;
    while (idx <= top)
    {
        cout << arr[idx] << " ";
        idx++;
    }
}

void push(int value)
{
    if (top == sizeof(arr) / sizeof(arr[0]) - 1)
    {
        cout << "\nOverflow!";
        return;
    }
    top++;
    arr[top] = value;
}

void pop()
{
    if (top == -1)
    {
        cout << "\nUnderflow!";
        return;
    }
    cout << "\nElement popped is: " << arr[top];
    top--;
}

int main()
{
    int choice;
    do
    {
        cout << "\n1. Push an element\n";
        cout << "2. Pop an element\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int value;
            cout << "Enter element to be pushed: ";
            cin >> value;
            push(value);
            break;

        case 2:
            pop();
            break;

        default:
            cout << "\nExits!";
        }
    } while (choice != 3);

    printArray();

    return 0;
}