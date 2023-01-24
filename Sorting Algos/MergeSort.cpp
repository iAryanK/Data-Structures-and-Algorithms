#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int b[high - low + 1];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            b[k++] = arr[i++];
        else
            b[k++] = arr[j++];
    }

    while (i <= mid)
        b[k++] = arr[i++];

    while (j <= mid)
        b[k++] = arr[j++];

    for (int i = low; i <= high; i++)
        arr[i] = b[i];
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    srand(time(0));
    cout << "Enter the number of elements in array: ";
    int n;
    n = rand() % 10;
    cout << n << "\n";

    cout << "Enter data in the array: ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }

    cout << "\nSorting the Array...\n";
    mergeSort(arr, 0, n - 1);

    for (auto &iter : arr)
        cout << iter << " ";

    return 0;
}