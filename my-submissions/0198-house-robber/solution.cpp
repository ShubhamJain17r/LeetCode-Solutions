class Solution {
public:
    int f(int i, vector<int>& nums) {
        if (i < 0)
            return 0;
        if (i == 0)
            return nums[0];
        int rob = nums[i] + f(i - 2, nums);
        int leave = f(i-1, nums);
        return max(rob, leave);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp(n + 1, 0);
        dp[0] = 0, dp[1] = nums[0];
        int prev2 = 0, prev1 = nums[0], curr = 0;
        for (int i = 2; i <= n; ++i) {
            curr = max(nums[i-1] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};
