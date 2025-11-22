class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
 
        vector<pair<int, int>> dirs = {
            {1,0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
        };
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = -1;
        int steps = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front();
                q.pop();
                if (x == n - 1 && y == n - 1)
                    return steps + 1;

                for (auto& [r, c] : dirs) {
                    int nR = x + r, nC = y + c;
                    if (nR >= 0 && nC >= 0 && nR < n && nC < n && grid[nR][nC] == 0) {
                        grid[nR][nC] = -1;
                        q.push({nR, nC});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
