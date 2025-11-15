class Solution {
public:
    int t = 0;

    void dfs(int u, int parent, vector<vector<int>>& graph,
             vector<int>& disc, vector<int>& low,
             vector<vector<int>>& bridges) {

        disc[u] = low[u] = t++;

        for (int v : graph[u]) {

            if (v == parent) continue;

            if (disc[v] == -1) {
                dfs(v, u, graph, disc, low, bridges);

                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u])    // bridge condition
                    bridges.push_back({u, v});
            }
            else {
                low[u] = min(low[u], disc[v]);   // back edge
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> graph(n);
        for (auto& c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<vector<int>> bridges;

        for (int i = 0; i < n; i++) {
            if (disc[i] == -1)
                dfs(i, -1, graph, disc, low, bridges);
        }

        return bridges;
    }
};

