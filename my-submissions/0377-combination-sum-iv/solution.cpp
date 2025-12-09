class Solution {
public:
    int f(int t, vector<int>& nums, vector<int>& dp) {
        if (t == 0)
            return 1;
        if (dp[t] != -1)
            return dp[t];
        long long ways = 0;
        for (int& val : nums) {
            if (val <= t)
                ways += f(t - val, nums, dp);
        }
        return dp[t] = ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        sort(nums.begin(), nums.end());
        dp[0] = 1;
        for (int t = 1; t <= target; ++t) {
            long long ways = 0;
            for (int& val : nums) {
                if (val <= t)
                    ways += dp[t - val];
                else 
                    break;
            }
            dp[t] = ways;
        }
        return dp[target];
    }
};
