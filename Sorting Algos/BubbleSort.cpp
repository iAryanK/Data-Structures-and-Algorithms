#include <bits/stdc++.h>
using namespace std;

// Bubble out the largest element to the end of the array in each iteration and continue the process with the rest of the array.
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            return;
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
    bubbleSort(arr, n);

    for (auto &iter : arr)
        cout << iter << " ";
    return 0;
}

// Time complexity: O(n^2)
