class Solution {
public:
    void dfs(vector<vector<int>>& grid, int m, int n, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) {
            return;
        }

        grid[i][j] = 0;
        dfs(grid, m, n, i + 1, j);
        dfs(grid, m, n, i, j + 1);
        dfs(grid, m, n, i - 1, j);
        dfs(grid, m, n, i, j - 1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int numIslands = 0;
        for (int i = 0; i < m; ++i) {
            if (grid[i][0]) dfs(grid, m, n, i, 0);
            if (grid[i][n-1]) dfs(grid, m, n, i, n-1);
        }
        for (int j = 0; j < n; ++j) {
            if (grid[0][j]) dfs(grid, m, n, 0, j);
            if (grid[m-1][j]) dfs(grid, m, n, m-1, j);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j])
                    numIslands++;
            }
        }
        return numIslands;
    }
};
