class Solution {
public:
    int houseRobber(vector<int>& nums, int s, int e) {
        if (s == e) return nums[s];
        int prev2 = nums[s];
        int prev1 = max(nums[s], nums[s + 1]);

        for (int i = s + 2; i <= e; ++i) {
            int rob = nums[i] + prev2;
            int leave = prev1;

            prev2 = prev1;
            prev1 = max(rob, leave);
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        return max(houseRobber(nums, 0, n - 2), houseRobber(nums, 1, n - 1));
    }
};
