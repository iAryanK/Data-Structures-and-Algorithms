#include <bits/stdc++.h>
using namespace std;

void getData(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void binarySearch(int *arr, int n, int key)
{
    int start = 0, end = n - 1, ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            break;
        }
        else if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    if (ans != -1)
        cout << "Element " << key << " is found at position " << ans + 1;
    else
        cout << "Item doesn't exist!";
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    getData(arr, n);

    int key;
    cout << "Enter the element you want to search: ";
    cin >> key;

    binarySearch(arr, n, key);

    return 0;
}