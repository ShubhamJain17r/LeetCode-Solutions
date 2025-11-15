class Solution {
public:
    int uniquePathsHelper(vector<vector<int>>& memo, int i, int j) {
        if (memo[i][j] != 0)
            return memo[i][j];
        memo[i][j] = uniquePathsHelper(memo, i + 1, j) + uniquePathsHelper(memo, i, j + 1);
        return memo[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            memo[i][n-1] = 1;
        }
        for (int i = 0; i < n; ++i) {
            memo[m-1][i] = 1; 
        }
        memo[0][0] = uniquePathsHelper(memo, 0, 0);
        return memo[0][0];
    }
};
