#include <bits/stdc++.h>
using namespace std;

// Select the smallest element after the current element in the given array and swap it with the current element.
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int indexofmin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[indexofmin])
                indexofmin = j;
        }
        swap(arr[i], arr[indexofmin]);
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
    selectionSort(arr, n);

    for (auto &iter : arr)
        cout << iter << " ";
    return 0;
}

// Time complexity: O(n^2)
