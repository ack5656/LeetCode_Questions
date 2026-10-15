
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int, int>>> graph(n);

        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            graph[u].push_back({v, wt});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;
        q.push({src, {0, -1}});

        while (!q.empty()) {
            auto val = q.front();
            q.pop();

            int u = val.first;
            int cost = val.second.first;
            int stops = val.second.second;

            if (stops == k) continue;

            for (auto edge : graph[u]) {
                int v = edge.first;
                int wt = edge.second;

                if (dist[v] > cost + wt) {
                    dist[v] = cost + wt;
                    q.push({v, {dist[v], stops + 1}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
