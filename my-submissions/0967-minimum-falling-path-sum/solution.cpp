class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> dp(grid[n-1]);

        for (int i = n - 2; i >= 0; --i) {
            vector<int> temp(n);
            for (int j = 0; j < n; ++j) {
                int d = dp[j];
                int dl = (j != 0) ? dp[j-1] : 1e9;
                int dr = (j != n-1) ? dp[j+1] : 1e9;

                temp[j] = grid[i][j] + min(d, min(dl, dr));
            }
            dp = temp;
        }
        
        int ans = 1e9;
        for (int j = 0; j < n; ++j)
            ans = min(ans, dp[j]);
        return ans;
    }
};
