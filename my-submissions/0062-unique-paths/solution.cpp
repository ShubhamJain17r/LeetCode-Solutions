class Solution {
public:
    // int f(vector<vector<int>> &grid, int i, int j) {
    //     if (i == 0 && j == 0) return 1;
    //     if (i == -1 || j == -1) return 0;

    //     if (grid[i][j] != -1) return grid[i][j];

    //     return grid[i][j] = f(grid, i - 1, j) + f(grid, i, j - 1);
    // }
    int uniquePaths(int m, int n) {
        // vector<vector<int>> grid(m, vector<int>(n, -1));
        // return f(grid, m - 1, n - 1);

        // vector<vector<int>> grid(m, vector<int>(n, 0));
        // for (int i = 0; i < m; ++i) {
        //     grid[i][0] = 1;
        // }
        // for (int j = 0; j < n; ++j) {
        //     grid[0][j] = 1;
        // }
        // for (int i = 1; i < m; ++i) {
        //     for (int j = 1; j < n; ++j) {
        //         grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
        //     }
        // }
        // return grid[m - 1][n - 1];

        vector<int> dp(n, 1);
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
        
    }
};
