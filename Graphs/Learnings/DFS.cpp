#include<iostream>
#include<vector>
using namespace std;


void dfs(int node, vector<int>adj[], int vis[], vector<int>& ls){

    vis[node] = 1;
    ls.push_back(node);

    // treverse the neighbours

    for(auto v: adj[node]){
        if(!vis[v]){
            dfs(v,adj,vis,ls);
        }
    }

}

