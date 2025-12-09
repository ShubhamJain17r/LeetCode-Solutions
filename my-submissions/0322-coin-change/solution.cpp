#define INF 1e9
class Solution {
public:
    // double f(int i, int t, vector<int>& coins, vector<vector<double>>& dp) {
    //     if (t == 0)
    //         return 0;
    //     if (i == 0) {
    //         if (t % coins[0] == 0)
    //             return t/coins[0];
    //         else
    //             return INT_MAX;
    //     }
    //     if (dp[i][t] != -1)
    //         return dp[i][t];
    //     double notTake = f(i - 1, t, coins, dp);
    //     double take = (coins[i] <= t) ? 1 + f(i, t - coins[i], coins, dp) : INT_MAX;
    //     return dp[i][t] = min(notTake, take);
    // }
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount+1, INF));

        for (int i = 0; i < n; ++i)
            dp[i][0] = 0;
        for (int t = 0; t <= amount; ++t)
            if (t % coins[0] == 0)
                dp[0][t] = t / coins[0];

        for (int i = 1; i < n; ++i) {
            for (int t = 1; t  <= amount; ++t) {
                int notTake = dp[i - 1][t];
                int take = (coins[i] <= t) ? 1 + dp[i][t - coins[i]] : INF;
                dp[i][t] = min(notTake, take);
            }
        }
        double ans = dp[n - 1][amount];
        if (ans >= INF)
            return -1;
        return ans;
    }
};
