class Solution {
public:
    void dfsHelper(vector<vector<int>>& grid, queue<pair<int,int>>& q, int i, int j, int n) {
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1)
            return;

        grid[i][j] = -1;        // mark as visited
        q.push({i, j});

        dfsHelper(grid, q, i+1, j, n);
        dfsHelper(grid, q, i-1, j, n);
        dfsHelper(grid, q, i, j+1, n);
        dfsHelper(grid, q, i, j-1, n);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;

        // --------------------
        // 1. Find and mark the first island
        // --------------------
        bool found = false;
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfsHelper(grid, q, i, j, n);
                    found = true;
                }
            }
        }

        vector<pair<int,int>> dirs = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        // --------------------
        // 2. BFS from the first island until touching second island
        // --------------------
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();      // process one layer
            while (sz--) {
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr < 0 || nc < 0 || nr >= n || nc >= n)
                        continue;

                    if (grid[nr][nc] == 1)      // reached second island
                        return steps;

                    if (grid[nr][nc] == 0) {    // expand bridge
                        grid[nr][nc] = -1;      // mark visited
                        q.push({nr, nc});
                    }
                }
            }
            steps++;   // increment after finishing full BFS layer
        }

        return -1;
    }
};

