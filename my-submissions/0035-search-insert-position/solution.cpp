class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int l = 0, r = nums.size() - 1;
        int lb = nums.size();             // if target > nums[last]
        while (l <= r) {
            int m = l + ((r - l) >> 2);
            int mid = nums[m];
            if (mid < target)   l = m + 1;
            else {
                lb = m;         // insert position
                r = m - 1;
            }
        }
        return lb;
    }
};
