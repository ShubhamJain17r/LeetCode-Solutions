class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if (grid[0][0] || grid[m - 1][n - 1]) return 0;

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        for (int j = n - 1; j >= 0; --j) {
            if (grid[m - 1][j]) break;
            dp[m - 1][j] = 1; 
        }
        for (int i = m - 1; i >= 0; --i) {
            if (grid[i][n - 1]) break;
            dp[i][n - 1] = 1;
        }
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                if (!grid[i][j])
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return (int)dp[0][0];
    }
};
