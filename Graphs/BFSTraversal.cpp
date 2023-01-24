#include <bits/stdc++.h>
using namespace std;
    
/*
Input: A graph G = (V, E) and source node s in V.

Algorithm:
-> Mark all nodes in visited[] as unvisited
-> Mark source node s as visited 
-> enqueue(Q.s)
while(Q is not empty)
{
    -> u = dequeue(Q);
    -> for each unvisited neighbour v of u{
        -> mark v as visited;
        -> enqueue(Q.v);
    }
}
*/

int main(){
    queue<int> q;
    int v;
    int i=1;
    int visited[7] = {0};
    int a[7][7]={
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    cout<<i<<" ";
    visited[i] = 1;
    q.push(i);  // enqueue i for exploration
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int j = 0;j<7;j++)
        {
            if (a[node][j] ==1 && visited[j] == 0){
                cout<<j<<" ";
                visited[j] = 1;
                q.push(j);
            }
        }
    }
    return 0;
}