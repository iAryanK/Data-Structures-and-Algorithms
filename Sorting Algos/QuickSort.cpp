#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (pivot<arr[j])
        j--;

        while (pivot>=arr[i])
        i++;

        if (i<j)
        swap(arr[i], arr[j]);
    }while(i<j);

    swap(arr[low], arr[j]);

    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low<high)
    {
        int partitionIdx = partition(arr, low, high);
        quickSort(arr, low, partitionIdx-1);
        quickSort(arr, partitionIdx+1, high);
    }
}

int main(){
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
    quickSort(arr, 0, n - 1);

    for (auto &iter : arr)
        cout << iter << " ";

    return 0;
}