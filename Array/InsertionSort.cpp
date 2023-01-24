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

void insertionSort(int *arr, int n)
{
    // pick the current element and place it at its correct position
    int i, j;
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
                arr[j + 1] = arr[j];
            else
            {
                break;
            }
            arr[j] = temp;
        }
    }
}

int main()
{

    int n;
    cin >> n;
    int *arr = new int[n];
    getData(arr, n);

    insertionSort(arr, n);

    printData(arr, n);

    return 0;
}

// Time complexity: O(n^2)