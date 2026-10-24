#include<iostream>
using namespace std;

int main(){
    
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];

    for(int i=0; i<m; i++){
        int u,v;
        adj[u].push_back(v);
        adj[v].push_back(u); //**NOTE:-  in the Directed graphs we do not need this line

    }

    return 0;
}