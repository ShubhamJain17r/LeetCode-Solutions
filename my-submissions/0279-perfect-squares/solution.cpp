class Solution {
public:
//     int f(int i, vector<int>& dp) {
//     if (i == 0)
//         return 0;
//     if (dp[i] != -1)
//         return dp[i];

//     int mini = 1e9;

//     for (int sq = 1; sq*sq <= i; sq++) {
//         int num = sq * sq;
//         mini = min(mini, 1 + f(i - num, dp)); 
//     }
//     return dp[i] = mini;
// }

    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int mini = 1e9;
            for (int sq = 1; sq*sq <= i; sq++) {
                int num = sq * sq;
                mini = min(mini, 1 + dp[i - num]); 
            }
            dp[i] = mini;
        }
        return dp[n];
    }
};
