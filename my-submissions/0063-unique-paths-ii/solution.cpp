class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int>dp (n, 0);
        if (grid[0][0] == 1 || grid[m-1][n-1] == 1)
            return 0;
        dp[0] = 1;
        for (int j = 1; j < n; ++j) {
            if (grid[0][j] == 0 && dp[j-1] == 1) 
                dp[j] = 1;
            else
                break;
        } 
        for (int i = 1; i < m; ++i) {
            dp[0] = (grid[i][0] == 0 ? dp[0] : 0);
            for (int j = 1; j < n; ++j) {
                if (grid[i][j] == 0)
                    dp[j] += dp[j-1];
                else
                    dp[j] = 0;
            }
        }
        return dp[n-1];
    }
};
