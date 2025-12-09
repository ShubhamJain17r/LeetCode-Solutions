class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<double> prev (amount + 1, 0);
        vector<double> curr (amount + 1, 0);

        // Base case for first row
        for (int t = 0; t <= amount; t++)
            prev[t] = (t % coins[0] == 0);

        // Fill DP
        for (int i = 1; i < n; ++i) {
            curr[0] = 1;
            for (int t = 0; t <= amount; ++t) {
                double notPick = prev[t];
                double pick = (coins[i] <= t) ? curr[t - coins[i]] : 0;
                curr[t] = notPick + pick;
            }
            prev = curr;
        }

        // Since problem asks for int, safe only if <= INT_MAX
        double ans = prev[amount];
        return (ans > INT_MAX ? INT_MAX : (int)ans);
    }
};

