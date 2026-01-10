class Solution {
public:
    string dfs(unordered_map<string, vector<string>> &graph, unordered_set<string> &visited, string &node) {
        visited.insert(node);
        for (string &nei : graph[node]) {
            if (visited.count(nei) == 0) {
                return dfs(graph, visited, nei);
            }
        }
        return node;
    }
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, vector<string>> graph;
        for (vector<string> &path : paths) {
            graph[path[0]].push_back(path[1]);
        }
        unordered_set<string> visited;
        string start = paths[0][0];
        return dfs(graph, visited, start);
    }
};
