class Solution {
public:
    int f(int i, int t, vector<int>& nums, vector<vector<int>>& dp) {

        // Base: only one number left
        if (i == 0) {
            if (nums[0] == 0)
                return (t == 0 ? 2 : 0); // +0 and -0 are two different ways

            return ( (t == nums[0]) || (t == -nums[0]) ) ? 1 : 0;
        }

        if (t < -1000 || t > 1000)
            return 0;  // safety but not critical

        if (dp[i][t + 1000] != -1)
            return dp[i][t + 1000];

        int plus  = f(i - 1, t - nums[i], nums, dp);
        int minus = f(i - 1, t + nums[i], nums, dp);

        return dp[i][t + 1000] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int x : nums) total += x;

        // The transformed target
        if ((total + target) % 2 != 0) return 0;
        int S = (total + target) / 2;
        if (S < 0) return 0;

        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(S + 1, 0));

        // Base case
        // If nums[0] == 0: two ways to make sum 0 → {+0, -0}
        // If nums[0] != 0: one way if nums[0] == sum
        if (nums[0] == 0)
            dp[0][0] = 2;
        else {
            dp[0][0] = 1;
            if (nums[0] <= S)
                dp[0][nums[0]] = 1;
        }

        // Fill table
        for (int i = 1; i < n; i++) {
            for (int s = 0; s <= S; s++) {
                long long notPick = dp[i-1][s];
                long long pick = 0;
                if (nums[i] <= s)
                    pick = dp[i-1][s - nums[i]];

                dp[i][s] = pick + notPick;
            }
        }

        return dp[n-1][S];
    }
};
