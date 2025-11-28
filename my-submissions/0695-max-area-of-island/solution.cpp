class Solution {
public:
    void dfs(vector<vector<int>>& grid, int m, int n, int i, int j, int& count) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        count++;
        dfs(grid, m, n, i + 1, j, count);
        dfs(grid, m, n, i, j + 1, count);
        dfs(grid, m, n, i - 1, j, count);
        dfs(grid, m, n, i, j - 1, count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int count = 0, maxCount = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    count = 0;
                    dfs(grid, m, n, i, j, count);
                    maxCount = max(maxCount, count);
                }
            }
        }
        return maxCount;
    }
};
