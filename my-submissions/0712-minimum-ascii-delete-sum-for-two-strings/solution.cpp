class Solution {
public:
    // int f(int i, int j, string &s1, string &s2) { 
    //     if (i == 0 && j == 0)
    //         return 0;
    //     if (i == 0) {
    //         int sum = 0;
    //         for(; j >= 1; --j) {
    //             sum += s2[j - 1];
    //         }
    //         return sum;
    //     }
    //     if (j == 0) {
    //         int sum = 0;
    //         for (; i >= 1; --i)
    //             sum += s1[i - 1];
    //         return sum;
    //     }
    //     if (s1[i - 1] == s2[j - 1]) 
    //         return f(i - 1, j - 1, s1, s2);
    //     int dels1 = s1[i - 1] + f(i - 1, j, s1, s2);
    //     int dels2 = s2[j - 1] + f(i, j - 1, s1, s2);
    //     return min(dels1, dels2);
    // }
    // void print(vector<vector<int>>& dp) {
    //     for (auto& v : dp) {
    //         for (int& val : v) {
    //             cout<<val<<"\t";
    //         }
    //         cout<<endl;
    //     }
    // }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // for (int i = 1; i <= n; ++i) {
        //     dp[i][0] = dp[i - 1][0] + s1[i - 1];
        // }
        for (int j = 1; j <= m; ++j) {
            // dp[0][j] = dp[0][j - 1] + s2[j - 1];
            prev[j] = prev[j - 1] + s2[j - 1];
        }
        // print(dp);
        for (int i = 1; i <= n; ++i) {
            curr[0] = prev[0] + s1[i - 1];
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1]) 
                    curr[j] = prev[j - 1];
                else {
                    int dels1 = s1[i - 1] + prev[j];
                    int dels2 = s2[j - 1] + curr[j - 1];
                    curr[j] = min(dels1, dels2);
                }
            }
            prev = curr;
        }
        // cout<<endl<<endl<<endl;
        // print(dp);
        return curr[m];
    }
};
