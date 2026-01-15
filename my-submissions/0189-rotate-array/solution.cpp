class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) return;

        // -------------------------- Brute Force -----------------------------

        // vector<int> ans;

        // for (int i = n - k; i < n; ++i)
        //     ans.push_back(nums[i]);
        // for (int i = 0; i < n - k; ++i)
        //     ans.push_back(nums[i]);
        // for (int i = 0; i < n; ++i)
        //     nums[i] = ans[i];

        // ----------------------- Space Optimized ---------------------------

        // O(2n)
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
