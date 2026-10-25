class Solution {
public:
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& isConnected) {
        vis[node] = true;
        int n = isConnected.size();
        for (int i = 0; i < n; i++) {
            if (isConnected[node][i] == 1 && !vis[i])
                dfs(i, vis, isConnected);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, isConnected);
                provinces++;
            }
        }
        return provinces;
    }
};
