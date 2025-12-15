class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIdx = 0;
        for (int i = 0; i < n; ++i) {
            if (i > maxIdx) return false;
            int reach = i + nums[i];
            maxIdx = max(maxIdx, reach);
        }
        return true;
    }
};
