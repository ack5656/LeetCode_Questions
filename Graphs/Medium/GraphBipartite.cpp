class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, int c, vector<int>& color) {
        color[node] = c;

        for (int nbr : graph[node]) {
            if (color[nbr] == -1) {
                if (!dfs(graph, nbr, 1 - c, color)) return false;
            } else if (color[nbr] == c) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1 && !dfs(graph, i, 0, color))
                return false;
        }
        return true;
    }
};