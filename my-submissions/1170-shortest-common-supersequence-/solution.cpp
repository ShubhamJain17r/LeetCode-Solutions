class Solution {
public:
    void LCS(string &s1, string &s2, vector<vector<int>> &dp) {
        int n = s1.length(), m = s2.length();
        for (int i = 1; i<= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);              
            }
        }
    }
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        LCS(s1, s2, dp);

        string ans = "";
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (dp[i][j] > dp[i - 1][j] && dp[i][j] > dp[i][j - 1]) {
                ans.push_back(s1[i - 1]);
                i--, j--;
            }
            else if (dp[i][j] == dp[i - 1][j]) {
                ans.push_back(s1[i - 1]);
                i--;
            }
            else {
                ans.push_back(s2[j - 1]);
                j--;
            }
        }
        while (i > 0) ans.push_back(s1[i-- - 1]);
        while (j > 0) ans.push_back(s2[j-- - 1]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
