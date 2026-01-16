class Solution {
public:
//     void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited) {
//         visited[node] = true;
//         for (int nei : graph[node]) {
//             if (!visited[nei]) {
//                 dfs(graph, nei, visited);
//             }
//         }
//     }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);

        for (const auto &edge : edges) {
            indegree[edge[1]]++;
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
