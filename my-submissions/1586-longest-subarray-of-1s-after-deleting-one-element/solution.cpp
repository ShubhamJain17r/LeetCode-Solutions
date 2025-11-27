class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, ans = 0, z_count = 0;
        for (int r = 0; r < nums.size(); ++r) {
            if (nums[r] == 1) {
                ans = max(ans, r - l + 1);
            }
            else if (z_count == 0) {
                z_count = 1;
                ans = max(ans, r - l + 1);
            }
            else {
                while (nums[l] == 1) l++;
                l++;
                z_count = 1;
            }
        }
        return ans - 1;
    }
};
