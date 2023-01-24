#include <bits/stdc++.h>
using namespace std;

void getData(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void linearSearch(int *arr, int n, int key)
{
    bool flag = false;
    int count = 0;
    while (count < n)
    {
        if (arr[count] == key)
        {
            flag = true;
            break;
        }
        count++;
    }
    if (flag)
        cout << "Element " << key << " is found at position " << count + 1;
    else
        cout << "Element doesn't exist!";
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    getData(arr, n);

    int key;
    cout << "Enter the item to be Searched: ";
    cin >> key;

    linearSearch(arr, n, key);

    return 0;
}