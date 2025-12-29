class Solution {
public:
    // int sum(vector<int> &nums, int l, int r) {
    //     int sum = 0;
    //     for (int i = l; i <= r; ++i) 
    //         sum += nums[i];
    //     return sum;
    // }
    // int divide(vector<int> &nums, int l, int r) {
    //     if (l == r) 
    //         return nums[l];

    //     int m = l + ((r - l) >> 1);
    //     int leftSubArr = divide(nums, l, m);
    //     int rightSubArr = divide(nums, m + 1, r);

        
    // }
    int maxSubArray(vector<int>& nums) {
        int maxSubArrSum = INT_MIN;
        int curr = INT_MIN;

        for (const int &val : nums) {
            if (curr == INT_MIN)
                curr = val;
            else
                curr = max(val, curr + val);
            maxSubArrSum = max(maxSubArrSum, curr);
        }
        return maxSubArrSum;
    }
};
