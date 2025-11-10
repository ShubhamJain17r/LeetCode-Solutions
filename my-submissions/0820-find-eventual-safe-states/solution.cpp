class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& inStack, int start) {
        visited[start] = true;
        inStack[start] = true;
        for (int neighbour : graph[start]) {
            if (!visited[neighbour] && dfs(graph, visited, inStack, neighbour))
                return true;
            if (inStack[neighbour]) 
                return true;
        }
        inStack[start] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> inStack(n, false);
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (!visited[i])
                dfs(graph, visited, inStack, i);
        }
        for (int i = 0; i < n; ++i) {
            if (!inStack[i])
                ans.push_back(i);
        }
        return ans;
    }
};
