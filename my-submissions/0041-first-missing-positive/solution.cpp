class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Place each number in its correct index: value x goes to index x-1
        for (int i = 0; i < n; ++i) {
            // Keep swapping until nums[i] is in its correct position
            while (nums[i] >= 1 && nums[i] <= n && 
                   nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // The first place where index+1 != value is the answer
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }

        // Otherwise all numbers 1..n are present
        return n + 1;
    }
};

