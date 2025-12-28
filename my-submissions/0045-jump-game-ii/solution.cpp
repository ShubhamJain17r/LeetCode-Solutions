class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int l = 0;
        int maxReach = nums[0];
        int jumps = 1;

        if (maxReach >= n - 1) return 1;

        while (l < n - 1) {
            int mr = maxReach;
            // cout<<mr<<" ";
            for (int r = l + 1; r <= mr; ++r) {
                maxReach = max(maxReach, r + nums[r]);
                if (maxReach >= n - 1)
                    return jumps + 1;
            }
            // cout<<maxReach<<" ";
            l = mr;
            jumps++;
            // cout<<jumps<<"\n";
        }
        return jumps;
    }
};
