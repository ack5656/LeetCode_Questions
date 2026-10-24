#include<iostream>
using namespace std;

int main(){
    int n,m;

    cin>>n>>m;
    
    // Graph

    int adj[n+1][n+1];
    for(int i=0; i<m; i++){
        
        int u,v;

        cin>>u>>v;
        adj[u][v] = 1; //**NOTE:-  in the Weighted graphs we write the edge weight instead of 1
        adj[v][u] = 1;
        
    }
    
    return 0;
}