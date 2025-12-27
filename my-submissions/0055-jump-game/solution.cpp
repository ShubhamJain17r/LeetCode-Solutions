class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int i = 0;
        while (i <= maxReach) {
            if (maxReach >= nums.size() - 1)
                return true;
            maxReach = max(maxReach, i + nums[i]);
            i++;
        }
        return false;
    }
};
