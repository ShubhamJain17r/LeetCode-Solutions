class Solution {
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& vis) {
        vis[node] = true;
        for (int nei : graph[node]) {
            if (!vis[nei])
                dfs(nei, graph, vis);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        dfs(0, rooms, vis);
        for (bool isVisited : vis)
            if (!isVisited)
                return false;
        return true;
    }
};
