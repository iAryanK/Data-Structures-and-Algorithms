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

void deletePosition(int *arr, int n)
{
    int position;
    cout << "Enter the position of value you want to delete: ";
    cin >> position;

    for (int i = position - 1; i < n; i++)
        arr[i] = arr[i + 1];
}

void deleteValue(int *arr, int n)
{
    int x, position;
    cout << "Enter the value you want to delete: ";
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            position = i;
            break;
        }
    }

    for (int i = position; i < n - 1; i++)
        arr[i] = arr[i + 1];
}

int main()
{
    int *arr = new int[100];

    int n;
    cout << "How many values do you want to enter: ";
    cin >> n;
    cout << "Enter data: ";
    getData(arr, n);

    // deletion when position of value to be deleted is known
    // deletePosition(arr, n);

    // deletion when value to be deleted is known
    deleteValue(arr, n);

    printData(arr, n - 1);

    delete[] arr;

    return 0;
}

// Time Complexity: O(n)