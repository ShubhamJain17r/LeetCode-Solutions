class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();

        // Find start and count total keys
        int totalKeys = 0;
        int startR = 0, startC = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                char c = grid[i][j];
                if (c == '@') {
                    startR = i;
                    startC = j;
                }
                if (c >= 'a' && c <= 'z') {
                    totalKeys = max(totalKeys, (c - 'a' + 1));
                }
            }
        }

        int finalMask = (1 << totalKeys) - 1;

        // BFS queue: {row, col, keyMask}
        queue<tuple<int,int,int>> q;
        q.push({startR, startC, 0});

        // visited[r][c][mask]
        vector<vector<vector<bool>>> visited(
                m, vector<vector<bool>>(n, vector<bool>(1<<totalKeys, false)));

        visited[startR][startC][0] = true;

        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,1,-1};

        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [r, c, mask] = q.front();
                q.pop();

                // If all keys collected → return steps
                if (mask == finalMask) return steps;

                for (int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    char g = grid[nr][nc];
                    if (g == '#') continue; // wall

                    int newMask = mask;

                    // If it's a key, collect it
                    if (g >= 'a' && g <= 'z') {
                        newMask |= (1 << (g - 'a'));
                    }

                    // If it's a lock but we don't have the key → skip
                    if (g >= 'A' && g <= 'Z') {
                        if ((newMask & (1 << (g - 'A'))) == 0)
                            continue;
                    }

                    // If not visited with this mask
                    if (!visited[nr][nc][newMask]) {
                        visited[nr][nc][newMask] = true;
                        q.push({nr, nc, newMask});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};

