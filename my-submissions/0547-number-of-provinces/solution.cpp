class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool> &vis) {
        vis[node] = true;
        for (int j = 0; j < isConnected.size(); ++j) {
            if (isConnected[node][j] && !vis[j])
                dfs(j, isConnected, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<bool> vis(n, false);
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, isConnected, vis);
                ans++;
            }
        } 
        return ans;
    }
};
