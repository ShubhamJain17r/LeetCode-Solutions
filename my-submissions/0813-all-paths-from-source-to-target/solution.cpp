class Solution {
public:
    void dfs(vector<vector<int>>& graph, int curr, vector<vector<int>>& paths, vector<int>& currPath, int target) {
        if (curr == target) {
            paths.push_back(currPath);
            return;
        }
        for (int neighbour : graph[curr]) {
            currPath.push_back(neighbour);
            dfs(graph, neighbour, paths, currPath, target);
            currPath.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        // vector<bool> visited(n, false);
        vector<int> currPath = {0};
        vector<vector<int>> paths;
        dfs(graph, 0, paths, currPath, n-1);
        return paths;
    }
};
