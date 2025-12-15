class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int l = 0, r = 0;
        while (r < n - 1) {
            int maxReach = 0;
            for (int idx = l; idx <= r; ++idx)
                maxReach = max(maxReach, idx + nums[idx]);
            l = r + 1;
            r = maxReach;
            jumps++;
        }
        return jumps;
    }
};
