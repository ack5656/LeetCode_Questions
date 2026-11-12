#include<iostream>
#include<vector>
using namespace std;

bool hasCycleUnd(int node,int parent,vector<vector<int>>& adj, vector<bool>& vis){
    vis[node] = true;
    for(auto neigh : adj[node]){
        if(!vis[neigh]) {
            if(hasCycleUnd(neigh,node,adj,vis)){
                return true;
            }
        }else if(neigh!=parent){
            return true;
        } 
    }

    return false;
} 