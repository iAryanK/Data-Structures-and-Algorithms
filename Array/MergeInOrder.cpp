#include <bits/stdc++.h>
using namespace std;

void getData(int *arr, int n)
{
    cout << "Enter Data: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void printData(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void sortArray(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void mergeInOrder(int *arr1, int n, int *arr2, int m, int *arr3)
{
    int i = 0, j = 0, k = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
            arr3[k++] = arr2[j++];
    }

    while (i < n)
    {
        arr3[k++] = arr1[i++];
    }
    while (j < m)
    {
        arr3[k++] = arr2[j++];
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements you want to enter in first array: ";
    cin >> n;

    int arr1[n];
    getData(arr1, n);
    sortArray(arr1, n);

    int m;
    cout << "Enter the number of elements you want to enter in second array: ";
    cin >> m;
    
    int arr2[m];
    getData(arr2, m);
    sortArray(arr2, m);

    int arr3[n + m];

    mergeInOrder(arr1, n, arr2, m, arr3);

    printData(arr3, n + m);

    return 0;
}