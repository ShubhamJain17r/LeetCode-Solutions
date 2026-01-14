class Solution {
public:
    int crossSum(vector<int> &nums, int l, int m, int r) {
        int maxLeft = INT_MIN, sum = 0;
        for (int i = m; i >= l; --i) {
            sum += nums[i];
            maxLeft = max(maxLeft, sum);
        }
        sum = 0;
        int maxRight = INT_MIN;
        for (int i = m + 1; i <= r; ++i) {
            sum += nums[i];
            maxRight = max(maxRight, sum);
        }

        return maxLeft + maxRight;
    }

    int maxSubArrayHelper(vector<int> &nums, int l, int r) {
        if (l == r) return nums[l];

        int mid = l + ((r - l) >> 1);
        int left = maxSubArrayHelper(nums, l, mid);
        int right = maxSubArrayHelper(nums, mid + 1, r);
        int cross = crossSum(nums, l, mid, r);

        return max({left, cross, right});
    }

    int maxSubArray(vector<int> &nums) {
        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }

    // int maxSubArray(vector<int>& nums) {
    //     int n = nums.size();
    //     int currSum = nums[0];
    //     int maxSum = nums[0];

    //     for (int i = 1; i < n; ++i) {
    //         currSum += nums[i];
    //         currSum = max(currSum, nums[i]);
    //         maxSum = max(maxSum, currSum);
    //     }
    //     return maxSum;
    // }
};
