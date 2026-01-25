class Solution {
public:
    vector<int> bfs(int n, vector<vector<int>> &graph, int src) {
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(src);

        dist[src] = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();

            for (int nei : graph[node]) {
                if (dist[nei] == -1) {
                    dist[nei] = dist[node] + 1;
                    q.push(nei);
                }
            }
        }
        return dist;
    }
    
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> graph(n);
        for (const auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> x_dist = bfs(n, graph, x);
        vector<int> y_dist = bfs(n, graph, y);
        vector<int> z_dist = bfs(n, graph, z);

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            vector<long long>temp = {x_dist[i], y_dist[i], z_dist[i]};

            sort(temp.begin(), temp.end());

            if ((temp[0] * temp[0]) == ((temp[2] * temp[2]) - (temp[1] * temp[1]))) {
                cnt++;
            }
        }
        return cnt;
    }
};
