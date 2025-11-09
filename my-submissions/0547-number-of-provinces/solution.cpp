class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int start, int n) {
        visited[start] = true;
        for (int i = 0; i < n; ++i) {
            if (i == start || isConnected[start][i] == 0)
                continue;
            if (!visited[i])
                dfs(isConnected, visited, i, n);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        int n = isConnected.size();
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                provinces++;
                dfs(isConnected, visited, i, n);
            }
        }
        return provinces;
    }
};
