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

void selectionSort(int *arr, int n)
{
    // select smallest element and place it at the beginning
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minIdx] > arr[j])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main()
{

    int n;
    cin >> n;
    int *arr = new int[n];
    getData(arr, n);

    selectionSort(arr, n);

    printData(arr, n);

    return 0;
}