class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int minDiff = 1e9;

        for (int i = 0; i <= n - k; ++i) {
            minDiff = min(nums[i + k - 1] - nums[i], minDiff);
        }

        return minDiff;
    }
};
