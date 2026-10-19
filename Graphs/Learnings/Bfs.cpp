vector<int>BFS(int v,vector<int> adj[]){
    
    vector<int> ans;
    vector<bool>vis(v,false);
    
    queue<int> q;
    q.push(0);
    vis[0] = true;
    
    while(!q.empty()){
    
    int node = q.feont();
    
    q.pop();
    ans.push_back(node);
    
    for(auto i: adj[node]){
    
        if(!vis[i]){
            q.push(i);
            vis[i] = true;
         }
      }

    }

    return ans;
}