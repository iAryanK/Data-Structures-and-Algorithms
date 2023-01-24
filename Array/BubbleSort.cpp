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

void bubbleSort(int *arr, int n)
{
    // for two adjacent elements, if (first>second), swap them
    for (int i = 1; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(swapped==false)
        break;
    }
}

int main()
{

    int n;
    cin >> n;
    int *arr = new int[n];
    getData(arr, n);

    bubbleSort(arr, n);

    printData(arr, n);

    return 0;
}

// Time complexity: O(n^2)