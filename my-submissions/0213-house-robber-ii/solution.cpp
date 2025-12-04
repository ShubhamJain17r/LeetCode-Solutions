class Solution {
public:
    int hr_space_optimized(vector<int>& input, int n) {
        if (n == 1)
            return input[0];
        int prev2 = input[0], prev = max(input[0], input[1]);
        for (int i = 2; i < n; ++i) {
            int curr = max(prev2 + input[i], prev);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> temp1, temp2;
        for (int i = 0; i < n; ++i) {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }
        return max(hr_space_optimized(temp1, temp1.size()), hr_space_optimized(temp2, temp2.size()));
    }
};
