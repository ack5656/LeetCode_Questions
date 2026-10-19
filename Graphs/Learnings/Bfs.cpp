/* 
BFS (Breadth-First Search):
Traverses a graph level by level, starting from node 0.
Uses a queue (FIFO) to process nodes in the order they are visited.

Marks each node as visited to avoid processing it multiple times.

Stores the traversal order in the result vector.
Time Complexity: O(V + E) - Visits each vertex and processes each edge.

Space Complexity: O(V) - Stores the visited array, queue, and result vector.
*/


vector<int>BFS(int v,vector<int> adj[]){
    
    vector<int> ans;
    vector<bool>vis(v,false);
    
    queue<int> q;
    q.push(0);
    vis[0] = true;
    
    while(!q.empty()){
    
    int node = q.front();
    
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