#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insertInHeap(int value)
    {
        size = size + 1;
        int index = size;
        arr[index] = value;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }

    // Deletion is always performed at root node
    void deleteInHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete!";
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex <= size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex <= size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
                return;
        }
    }

    void printHeap()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// max heap
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
        largest = left;
    if (right <= n && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[1], arr[size]);
        size--;

        heapify(arr, size, 1);
    }
}

int main()
{
    heap h;
    h.insertInHeap(1);
    h.insertInHeap(2);
    h.insertInHeap(3);
    h.insertInHeap(4);
    h.insertInHeap(5);
    h.printHeap();

    h.deleteInHeap();
    h.printHeap();

    int arr[] = {-1, 1, 2, 3, 4, 5};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    
    cout << "Printing the array\n";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n);

    cout << "Printing the array\n";
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";

    return 0;
}

// Priority queue STL can be used to store data in heap form