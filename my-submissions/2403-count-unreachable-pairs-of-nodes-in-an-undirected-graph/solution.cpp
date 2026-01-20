class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, long long& cnt) {
        vis[node] = true;
        cnt++;
        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, adj, vis, cnt);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        long long result = 0;
        long long remaining = n;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                long long size = 0;
                dfs(i, adj, vis, size);
                result += size * (remaining - size);
                remaining -= size;
            }
        }
        return result;
    }
};

