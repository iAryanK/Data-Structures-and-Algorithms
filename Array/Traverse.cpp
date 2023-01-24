#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; cin>>n;
    int *arr=new int(n);
    int arr[n];

    //getData
    for (int i=0;i<n;i++) 
    cin>>arr[i];

    //traverse using for loop
    for (int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    
    return 0;
}

// Time complexity: O(n)


/* We can't use range-for-loop with dynamically allocated arrays, since compiler can't deduce begin and end of this array. We should always use containers instead of it, for example std::vector.
If the array is not dynamically allocated, traverse using for-each loop
    for (auto &iter: arr)
    cout<<iter<<" ";
*/