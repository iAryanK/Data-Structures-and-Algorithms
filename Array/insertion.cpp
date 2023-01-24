#include <bits/stdc++.h>
using namespace std;

void getData(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    cin >> arr[i];
}

void printData(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}

int main()
{

    int n;
    cout << "Enter number of values you want to enter: ";
    cin >> n;
    int *arr = new int[100];
    cout<<"Enter data: ";
    getData(arr, n);

    int x, position;
    cout << "Enter the value you want to insert: ";
    cin >> x;
    cout << "Enter the position at which you want to insert this value: ";
    cin >> position;

    for (int i = n; i >= position; i--)
    arr[i] = arr[i - 1];

    arr[position-1] = x;

    printData(arr, n + 1);
    
    delete (arr);

    return 0;
}

// Time complexity: O(n)