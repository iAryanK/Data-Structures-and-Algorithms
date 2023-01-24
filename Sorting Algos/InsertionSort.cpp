#include <bits/stdc++.h>
using namespace std;

// Keep swapping the current element to the left till it reaches its correct position where the element at its left is smaller than it.
void insertionSort(int arr[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    srand(time(0));
    cout << "Enter the number of elements in the array: ";
    int n = rand() % 10;
    cout << n << "\n";

    cout << "Enter data: ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }

    cout << "\nSorting the Array...\n";
    insertionSort(arr, n);

    for (auto &iter : arr)
        cout << iter << " ";
    return 0;
}

// Time complexity: O(n^2)
