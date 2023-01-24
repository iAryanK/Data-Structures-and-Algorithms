#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char begin, char aux, char end)
{
    if (n == 0)
    return;
    
    towerOfHanoi(n - 1, begin, end, aux);
    cout << "Move disk " << n << " from rod " << begin << " to rod " << end << endl;
    towerOfHanoi(n - 1, aux, begin, end);
}

int main()
{
    int N = 3;

    towerOfHanoi(N, 'A', 'B', 'C');
    return 0;
}