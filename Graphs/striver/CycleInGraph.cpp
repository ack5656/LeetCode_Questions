#include <bits/stdc++.h>
using namespace std;

bool detectCycle(int src, vector<int> adj[], 
                 vector<int>& vis) {

    queue<pair<int, int>> q;

    vis[src] = 1;
    q.push({src, -1});

    while (!q.empty()) {

        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjNode : adj[node]) {

            if (!vis[adjNode]) {
                vis[adjNode] = 1;
                q.push({adjNode, node});
            }

            else if (adjNode != parent) {
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[]) {

    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {

        if (!vis[i]) {
            if (detectCycle(i, adj, vis))
                return true;
        }
    }

    return false;
}