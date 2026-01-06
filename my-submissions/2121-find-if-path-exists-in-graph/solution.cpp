class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int src, int dest, vector<bool>& visited) {
        if (src == dest)
            return true;
        visited[src] = true;
        for (const int &nei : graph[src]) {
            if (!visited[nei]) {
                if (dfs(graph, nei, dest, visited))
                    return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);
        for (vector<int> &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return dfs(graph, source, destination, visited);

    }
};
