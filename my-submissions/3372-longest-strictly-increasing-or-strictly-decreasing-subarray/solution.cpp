class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        int maxLen = 1;
        int left = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                maxLen = max(maxLen, i - left + 1);
            }
            else {
                left = i;
            }
        }
        left = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                maxLen = max(maxLen, i - left + 1);
            }
            else {
                left = i;
            }
        }
        return maxLen;
    }
};
