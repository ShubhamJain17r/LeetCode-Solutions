class Solution {
public: 
    int f(int i, int j, string &s, string &t, vector<vector<int>>& dp) {
        if (j == 0)
            return 1;
        if (i == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i - 1] == t[j - 1])
            return dp[i][j] =  f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
        return dp[i][j] = f(i - 1, j, s, t, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        if (m > n)
            return 0;
        if (m == n && s == t)
            return 1;
        // vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
        vector<double> prev(m + 1, 0), curr(m + 1, 0);
        for (int i = 0; i <= n; ++i)
            prev[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = m; j > 0; --j) {
                if (s[i - 1] == t[j - 1])
                    prev[j] =  prev[j - 1] + prev[j];
                else
                    prev[j] = prev[j];
            }
            // prev = curr;
        }
        return prev[m];
    }
};
