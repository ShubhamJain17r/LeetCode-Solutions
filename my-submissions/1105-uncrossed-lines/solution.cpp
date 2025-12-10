class Solution {
public:
    // int f(int i, int j, vector<int>& nums1, vector<int>& nums2, vector<vector<int>> &dp) {
    //     if (i == 0 || j == 0)
    //         return 0;
    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     if (nums1[i - 1] == nums2[j - 1])
    //         return dp[i][j] = 1 + f(i - 1, j - 1, nums1, nums2, dp);
    //     return dp[i][j] = max(f(i - 1, j, nums1, nums2, dp), f(i, j - 1, nums1, nums2, dp));
    // }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) 
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[m];
    }
};
