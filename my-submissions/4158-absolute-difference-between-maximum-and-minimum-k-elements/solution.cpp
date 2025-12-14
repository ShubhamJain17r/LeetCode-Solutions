class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int minSum = 0;
        for (int i = 0; i < k; ++i) {
            minSum += nums[i];
        }
        int maxSum = 0;
        for (int j = n - 1; j >= (n - k); --j) {
            maxSum += nums[j];
        }
        return maxSum - minSum;
    }
};
