class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> adjRed(n), adjBlue(n);
        for (auto& e : redEdges) 
            adjRed[e[0]].push_back(e[1]);
        for (auto& e : blueEdges)
            adjBlue[e[0]].push_back(e[1]);
        int RED = 0, BLUE = 1;
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        queue<array<int, 3>> q;
        vector<int> dist(n, -1);
        q.push({0, RED, 0});
        q.push({0, BLUE, 0});
        dist[0] = 0;
        visited[0][RED] = true;
        visited[0][BLUE] = true;
        while (!q.empty()) {
            auto [node, color, d] = q.front();
            q.pop();
            if (color == RED) {
                for (int neighbor : adjBlue[node]) {
                    if (!visited[neighbor][BLUE]) {
                        visited[neighbor][BLUE] = true;
                        q.push({neighbor, BLUE, d + 1});
                        if (dist[neighbor] == -1) 
                            dist[neighbor] = d + 1;
                    }
                }
            }
            else {
                for (int neighbor : adjRed[node]) {
                    if (!visited[neighbor][RED]) {
                        visited[neighbor][RED] = true;
                        q.push({neighbor, RED, d + 1});
                        if (dist[neighbor] == -1) 
                            dist[neighbor] = d + 1;
                    }
                }

            }
        }
        return dist;
    }

};
