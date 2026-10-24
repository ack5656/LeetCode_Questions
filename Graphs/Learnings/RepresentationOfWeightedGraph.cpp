#include<iostream>
#include<vector>
using namespace std;

int main(){
    int V,E;

    cin>>V>>E;

    vector<vector<pair<int,int>>> adj(V);

    for(int i=0; i<E; i++){
        int u,v,w;

        cin>>u>>v>>w;

        // undirected weighted graph
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }
    return 0;
}