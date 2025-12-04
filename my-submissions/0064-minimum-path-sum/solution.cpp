class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> dp(n, 1e8);

        dp[0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 1e8);
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = grid[0][0];
                    continue;
                }
                int up = (i > 0) ? dp[j] : (int)1e8;
                int left = (j > 0) ? temp[j - 1] : (int)1e8;

                temp[j] = grid[i][j] + min(up, left);
            }
            dp = temp;
        }
        return dp[n - 1];
    }
};
