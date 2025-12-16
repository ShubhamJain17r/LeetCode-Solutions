class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<bool> &vis, vector<bool> &inStack, vector<int> &safe) {
        vis[node] = inStack[node] = true;
        for (int nei : graph[node]) {
            if (!vis[nei]) {
                if (dfs(nei, graph, vis, inStack, safe))
                    return true;
            }
            else if (inStack[nei])
                return true;
        }
        inStack[node] = false;
        safe.push_back(node);
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> vis(n, false);
        vector<bool> inStack(n, false);
        vector<int> safe;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, graph, vis, inStack, safe);
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};
